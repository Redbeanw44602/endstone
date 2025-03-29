add_rules('mode.debug', 'mode.release', 'mode.releasedbg', 'mode.coverage')

set_allowedplats('linux', 'windows')
set_allowedarchs('linux|x86_64', 'windows|x64')

if is_plat('linux') then
    set_toolchains('clang')
    set_runtimes('c++_static')
end

if is_plat('windows') then
    set_toolchains('msvc')
    set_runtimes('MT')
end

option('dev-tools')
    set_default(false)
    set_showmenu(true)
    set_description('Build endstone with devtools support.')
    after_check(function (option) 
        if not is_plat('windows') then -- TODO: Support linux.
            wprint('Endstone: DevTools is currently only available on windows.')
            option:enable(false)
        end
    end)
option_end()

-- add_repositories('endstone-repo xmake-repo') --- TODO: Move to a separate repository.

-- add_requires('aklomp-base64   0.5.2')
-- add_requires('funchook        1.1.3')
add_requires('boost           1.86.0')
add_requires('concurrentqueue 1.0.4')
add_requires('cpptrace        0.7.5')
add_requires('date            3.0.3')
add_requires('entt            3.14.0')
add_requires('expected-lite   0.8.0')
add_requires('fmt             10.x')
add_requires('glm             1.0.1')
add_requires('magic_enum      0.9.7')
add_requires('microsoft-gsl   4.1.0')
add_requires('nlohmann_json   3.11.3')
-- add_requires('pybind11        2.13.1')
add_requires('sentry-native   0.7.17')
add_requires('spdlog          1.14.1')
add_requires('toml++          3.3.0')
add_requires('gtest           1.15.2')

if is_plat('linux') then
    add_requires('libelf      0.8.13')
end

if is_plat('windows') then
    add_requires('microsoft-detours 2023.6.8')
end

if has_config('dev-tools') then
    add_requires('glew        2.2.0')
    add_requires('glfw        3.4')
    add_requires('imgui       v1.91.5-docking')
    -- add_requires('zstr        1.0.7')
end

set_languages('c++20')
set_warnings('all')

add_includedirs('src')

add_cxflags('clang::-fms-extensions')

target('endstone')
    set_kind('headeronly')
    add_headerfiles('include/**.h')
    add_headerfiles('include/**.hpp') -- endstone/endstone.hpp
    add_includedirs('include', {public = true})

    add_packages(
        'fmt',
        'expected-lite'
    )

target('bedrock')
    set_kind('static')
    add_files('src/bedrock/**.cpp')
    remove_files('src/bedrock/symbol_generator/**')

    add_deps('endstone')
    add_packages(
        'boost',
        'fmt',
        'entt',
        'glm',
        'magic_enum',
        'microsoft-gsl',
        'expected-lite'
    )

    add_defines(
        'ENTT_SPARSE_PAGE=2048',
        'ENTT_PACKED_PAGE=128',
        'ENTT_NO_MIXIN'
    )

    -- We need to build bedrock_symbols_generator.exe separately first.
    add_deps('bedrock_symbols_generator')
    before_build(function (target) 
        import("core.project.project")

        local program = project.target('bedrock_symbols_generator'):targetfile()
        os.execv(program, { 
            'src/bedrock/symbol_generator/symbols.toml', -- Don't use absolute paths. (for cross-compile)
            'build/bedrock_symbols.generated.h' 
        })
    end)

target('bedrock_symbols_generator')
    set_kind('binary')
    add_files('src/bedrock/symbol_generator/**.cpp')
    add_includedirs('build', {interface = true})

    add_packages('toml++')

target('endstone_core')
    set_kind('static')
    add_files('src/endstone/core/**.cpp')
    if not has_config('dev-tools') then
        remove_files('src/endstone/core/devtools/**')
        add_defines('ENDSTONE_DISABLE_DEVTOOLS')
    end

    add_packages(
        'aklomp-base64',
        'boost',
        'concurrentqueue',
        'cpptrace',
        'date',
        'entt',
        'magic_enum',
        'nlohmann_json',
        'pybind11',
        'sentry-native',
        'spdlog',
        'toml++'
    )

    add_defines('PYBIND11_DETAILED_ERROR_MESSAGES')

    -- TODO: Define ENDSTONE_VERSION.

target('endstone_runtime')
    set_kind('shared')
    add_files('src/endstone/runtime/**.cpp')
    remove_files('src/endstone/runtime/loader.cpp')

    if is_plat('windows') then
        add_syslinks(
            'dbghelp', 
            'ws2_32'
        )
    end    
    if is_plat('linux') then
        add_packages('libelf')
    end

    add_packages('funchook')

target('endstone_runtime_loader') 
    set_kind('shared' and is_plat('windows') or 'phony')
    add_files('src/endstone/runtime/loader.cpp')
    
    add_defines('_CRT_SECURE_NO_WARNINGS')

target('endstone_python')
    add_rules('python.library')
    add_files('src/endstone/python/**.cpp')

    if not is_plat('windows') then
        remove_files('src/endstone/python/winext.cpp')
    else
        -- is windows platform
        add_packages('detours')
    end

    add_deps('endstone')
    add_packages('pybind11')
