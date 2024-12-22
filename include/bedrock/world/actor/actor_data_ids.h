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

enum class ActorDataIDs : uint8_t {
    RESERVED_0 = 0,
    STRUCTURAL_INTEGRITY = 1,
    VARIANT = 2,
    COLOR_INDEX = 3,
    NAME = 4,
    OWNER = 5,
    TARGET = 6,
    AIR_SUPPLY = 7,
    EFFECT_COLOR = 8,
    RESERVED_009 = 9,
    RESERVED_010 = 10,
    HURT = 11,
    HURT_DIR = 12,
    ROW_TIME_LEFT = 13,
    ROW_TIME_RIGHT = 14,
    VALUE = 15,
    DISPLAY_TILE_RUNTIME_ID = 16,
    DISPLAY_OFFSET = 17,
    CUSTOM_DISPLAY = 18,
    SWELL = 19,
    OLD_SWELL = 20,
    SWELL_DIR = 21,
    CHARGE_AMOUNT = 22,
    CARRY_BLOCK_RUNTIME_ID = 23,
    CLIENT_EVENT = 24,
    USING_ITEM = 25,
    PLAYER_FLAGS = 26,
    PLAYER_INDEX = 27,
    BED_POSITION = 28,
    X_POWER = 29,
    Y_POWER = 30,
    Z_POWER = 31,
    AUX_POWER = 32,
    FISHX = 33,
    FISHZ = 34,
    FISHANGLE = 35,
    AUX_VALUE_DATA = 36,
    LEASH_HOLDER = 37,
    RESERVED_038 = 38,
    HAS_NPC = 39,
    NPC_DATA = 40,
    ACTIONS = 41,
    AIR_SUPPLY_MAX = 42,
    MARK_VARIANT = 43,
    CONTAINER_TYPE = 44,
    CONTAINER_SIZE = 45,
    CONTAINER_STRENGTH_MODIFIER = 46,
    BLOCK_TARGET = 47,
    INV = 48,
    TARGET_A = 49,
    TARGET_B = 50,
    TARGET_C = 51,
    AERIAL_ATTACK = 52,
    RESERVED_053 = 53,
    RESERVED_054 = 54,
    FUSE_TIME = 55,
    RESERVED_056 = 56,
    SEAT_LOCK_PASSENGER_ROTATION = 57,
    SEAT_LOCK_PASSENGER_ROTATION_DEGREES = 58,
    SEAT_ROTATION_OFFSET = 59,
    SEAT_ROTATION_OFFSET_DEGREES = 60,
    DATA_RADIUS = 61,
    DATA_WAITING = 62,
    DATA_PARTICLE = 63,
    PEEK_ID = 64,
    ATTACH_FACE = 65,
    ATTACHED = 66,
    ATTACH_POS = 67,
    TRADE_TARGET = 68,
    CAREER = 69,
    HAS_COMMAND_BLOCK = 70,
    COMMAND_NAME = 71,
    LAST_COMMAND_OUTPUT = 72,
    TRACK_COMMAND_OUTPUT = 73,
    RESERVED_074 = 74,
    STRENGTH = 75,
    STRENGTH_MAX = 76,
    DATA_SPELL_CASTING_COLOR = 77,
    DATA_LIFETIME_TICKS = 78,
    POSE_INDEX = 79,
    DATA_TICK_OFFSET = 80,
    NAMETAG_ALWAYS_SHOW = 81,
    COLOR_2_INDEX = 82,
    NAME_AUTHOR = 83,
    SCORE = 84,
    BALLOON_ANCHOR = 85,
    PUFFED_STATE = 86,
    BUBBLE_TIME = 87,
    AGENT = 88,
    SITTING_AMOUNT = 89,
    SITTING_AMOUNT_PREVIOUS = 90,
    EATING_COUNTER = 91,
    RESERVED_092 = 92,
    LAYING_AMOUNT = 93,
    LAYING_AMOUNT_PREVIOUS = 94,
    DATA_DURATION = 95,
    DATA_SPAWN_TIME_deprecated = 96,
    DATA_CHANGE_RATE = 97,
    DATA_CHANGE_ON_PICKUP = 98,
    DATA_PICKUP_COUNT = 99,
    INTERACT_TEXT = 100,
    TRADE_TIER = 101,
    MAX_TRADE_TIER = 102,
    TRADE_EXPERIENCE = 103,
    SKIN_ID = 104,
    SPAWNING_FRAMES = 105,
    COMMAND_BLOCK_TICK_DELAY = 106,
    COMMAND_BLOCK_EXECUTE_ON_FIRST_TICK = 107,
    AMBIENT_SOUND_INTERVAL = 108,
    AMBIENT_SOUND_INTERVAL_RANGE = 109,
    AMBIENT_SOUND_EVENT_NAME = 110,
    FALL_DAMAGE_MULTIPLIER = 111,
    NAME_RAW_TEXT = 112,
    CAN_RIDE_TARGET = 113,
    LOW_TIER_CURED_TRADE_DISCOUNT = 114,
    HIGH_TIER_CURED_TRADE_DISCOUNT = 115,
    NEARBY_CURED_TRADE_DISCOUNT = 116,
    NEARBY_CURED_DISCOUNT_TIME_STAMP = 117,
    HITBOX = 118,
    IS_BUOYANT = 119,
    FREEZING_EFFECT_STRENGTH = 120,
    BUOYANCY_DATA = 121,
    GOAT_HORN_COUNT = 122,
    BASE_RUNTIME_ID = 123,
    MOVEMENT_SOUND_DISTANCE_OFFSET = 124,
    HEARTBEAT_INTERVAL_TICKS = 125,
    HEARTBEAT_SOUND_EVENT = 126,
    PLAYER_LAST_DEATH_POS = 127,
    PLAYER_LAST_DEATH_DIMENSION = 128,
    PLAYER_HAS_DIED = 129,
    COLLISION_BOX = 130,
    VISIBLE_MOB_EFFECTS = 131,
    Count = 132,
};
