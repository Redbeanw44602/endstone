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

#pragma once

#include <cstdint>

class Tick {
public:
    bool operator==(const Tick &other) const
    {
        return tick_id == other.tick_id;
    }

    bool operator!=(const Tick &other) const
    {
        return !(*this == other);
    }

    Tick operator+(int value) const
    {
        Tick result;
        result.tick_id = this->tick_id + value;
        return result;
    }

    std::uint64_t tick_id;
};
