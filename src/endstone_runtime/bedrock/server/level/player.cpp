// Copyright (c) 2024, The Endstone Project. (https://endstone.dev) All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "bedrock/server/level/player.h"

#include "bedrock/network/game/available_commands_packet.h"
#include "endstone/detail/hook.h"
#include "endstone/detail/server.h"
#include "endstone/detail/singleton.h"

void Player::setPermissions(CommandPermissionLevel level)
{
    using endstone::detail::EndstoneServer;
    using endstone::detail::Singleton;

    ENDSTONE_HOOK_CALL_ORIGINAL(&Player::setPermissions, this, level);
    // TODO: refactor this into endstone::Player::sendCommands or endstone::Server::syncCommands
    // TODO: set command flags (hidden) based on testPermissionSilently results
    auto &server = Singleton<EndstoneServer>::getInstance();
    auto &registry = server.getMinecraftCommands().getRegistry();
    AvailableCommandsPacket packet = registry.serializeAvailableCommands();
    // TODO: use virtual function Player::sendNetworkPacket instead of this
    getPacketSender().send(packet);
}
