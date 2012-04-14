/*
 * Copyright (C) 2011-2012 DarkCore <http://www.darkpeninsula.eu/>
 * Copyright (C) 2011-2012 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2012 MaNGOS <http://getmangos.com/>
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef __BATTLEGROUNDDS_H
#define __BATTLEGROUNDDS_H

#include "Unit.h"

class Battleground;

enum BattlegroundDSObjectTypes
{
    BG_DS_OBJECT_DOOR_1         = 0,
    BG_DS_OBJECT_DOOR_2         = 1,
    BG_DS_OBJECT_WATER_1        = 2,
    BG_DS_OBJECT_WATER_2        = 3,
    BG_DS_OBJECT_BUFF_1         = 4,
    BG_DS_OBJECT_BUFF_2         = 5,
    BG_DS_OBJECT_MAX            = 6
};

enum BattlegroundDSObjects
{
    BG_DS_OBJECT_TYPE_DOOR_1    = 192642,
    BG_DS_OBJECT_TYPE_DOOR_2    = 192643,
    BG_DS_OBJECT_TYPE_WATER_1   = 194395, // LoS checker
    BG_DS_OBJECT_TYPE_WATER_2   = 191877, // Visual
    BG_DS_OBJECT_TYPE_BUFF_1    = 184663,
    BG_DS_OBJECT_TYPE_BUFF_2    = 184664
};

enum BattlegroundDSData
{
    BG_DS_WATERFALL_TIMER_MIN                    = 35000,
    BG_DS_WATERFALL_TIMER_MAX                    = 60000,
    BG_DS_WATERFALL_DURATION                     = 30000,
};

class BattlegroundDSScore : public BattlegroundScore
{
    public:
        BattlegroundDSScore() {};
        virtual ~BattlegroundDSScore() {};
        //TODO fix me
};

class BattlegroundDS : public Battleground
{
    public:
        BattlegroundDS();
        ~BattlegroundDS();

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player* player);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();

        void RemovePlayer(Player* player, uint64 guid, uint32 team);
        void HandleAreaTrigger(Player* Source, uint32 Trigger);
        bool SetupBattleground();
        virtual void Reset();
        virtual void FillInitialWorldStates(WorldPacket &d);
        void HandleKillPlayer(Player* player, Player* killer);
        bool HandlePlayerUnderMap(Player* player);
    private:
        uint32 m_waterTimer;
        bool m_waterfallActive;
        bool m_knockbackCheck;
        uint32 m_knockback;
        void KnockBackPlayer(Unit *player, float angle, float horizontalSpeed, float verticalSpeed);

        virtual void PostUpdateImpl(uint32 diff);
    protected:
        bool isWaterFallActive() { return m_waterfallActive; };
        void setWaterFallActive(bool active) { m_waterfallActive = active; };
        void setWaterFallTimer(uint32 timer) { m_waterTimer = timer; };
        uint32 getWaterFallTimer() { return m_waterTimer; };
};
#endif
