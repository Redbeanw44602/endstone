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

#include "endstone/detail/actor/mob.h"

namespace endstone::detail {

EndstoneMob::EndstoneMob(EndstoneServer &server, ::Mob &mob) : EndstoneActor(server, mob), mob_(mob) {}

void EndstoneMob::sendMessage(const std::string &message) const
{
    EndstoneActor::sendMessage(message);
}

void EndstoneMob::sendMessage(const Translatable &message) const
{
    EndstoneActor::sendMessage(message);
}

void EndstoneMob::sendErrorMessage(const Translatable &message) const
{
    EndstoneActor::sendErrorMessage(message);
}

void EndstoneMob::sendErrorMessage(const std::string &message) const
{
    EndstoneActor::sendErrorMessage(message);
}

Server &EndstoneMob::getServer() const
{
    return EndstoneActor::getServer();
}

std::string EndstoneMob::getName() const
{
    return EndstoneActor::getName();
}

bool EndstoneMob::isPermissionSet(std::string name) const
{
    return EndstoneActor::isPermissionSet(name);
}

bool EndstoneMob::isPermissionSet(const Permission &perm) const
{
    return EndstoneActor::isPermissionSet(perm);
}

bool EndstoneMob::hasPermission(std::string name) const
{
    return EndstoneActor::hasPermission(name);
}

bool EndstoneMob::hasPermission(const Permission &perm) const
{
    return EndstoneActor::hasPermission(perm);
}

PermissionAttachment *EndstoneMob::addAttachment(Plugin &plugin, const std::string &name, bool value)
{
    return EndstoneActor::addAttachment(plugin, name, value);
}

PermissionAttachment *EndstoneMob::addAttachment(Plugin &plugin)
{
    return EndstoneActor::addAttachment(plugin);
}

bool EndstoneMob::removeAttachment(PermissionAttachment &attachment)
{
    return EndstoneActor::removeAttachment(attachment);
}

void EndstoneMob::recalculatePermissions()
{
    EndstoneActor::recalculatePermissions();
}

std::unordered_set<PermissionAttachmentInfo *> EndstoneMob::getEffectivePermissions() const
{
    return EndstoneActor::getEffectivePermissions();
}

bool EndstoneMob::isOp() const
{
    return EndstoneActor::isOp();
}

void EndstoneMob::setOp(bool value)
{
    EndstoneActor::setOp(value);
}

std::uint64_t EndstoneMob::getRuntimeId() const
{
    return EndstoneActor::getRuntimeId();
}

Location EndstoneMob::getLocation() const
{
    return EndstoneActor::getLocation();
}

Vector<float> EndstoneMob::getVelocity() const
{
    return EndstoneActor::getVelocity();
}

bool EndstoneMob::isOnGround() const
{
    return EndstoneActor::isOnGround();
}

bool EndstoneMob::isInWater() const
{
    return EndstoneActor::isInWater();
}

bool EndstoneMob::isInLava() const
{
    return EndstoneActor::isInLava();
}

Level &EndstoneMob::getLevel() const
{
    return EndstoneActor::getLevel();
}

Dimension &EndstoneMob::getDimension() const
{
    return EndstoneActor::getDimension();
}

void EndstoneMob::setRotation(float pitch, float yaw)
{
    EndstoneActor::setRotation(pitch, yaw);
    mob_.setYBodyRotation(yaw);
}

bool EndstoneMob::isGliding() const
{
    return mob_.isGliding();
}

}  // namespace endstone::detail
