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

#include "endstone/detail/network/packet_codec.h"

#include <stdexcept>

#include <endstone/network/spawn_particle_effect_packet.h>

namespace endstone::detail {

std::string PacketCodec::encode(Packet &packet)
{
    switch (packet.getType()) {
    case PacketType::SpawnParticleEffect:
        return encode(static_cast<SpawnParticleEffectPacket &>(packet));
    default:
        throw std::runtime_error("Not supported");
    }
}
}  // namespace endstone::detail
