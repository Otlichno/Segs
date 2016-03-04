/*
 * Super Entity Game Server Project
 * http://segs.sf.net/
 * Copyright (c) 2006 - 2016 Super Entity Game Server Team (see Authors.txt)
 * This software is licensed! (See License.txt for details)
 *
 */

#pragma once

// ACE Logging
#include <string>
#include <ace/Log_Msg.h>
#include <ace/Singleton.h>

#include "Database.h"
class IClient;
class CharacterClient;
class CharacterCostume;
class Character;
class AccountInfo;
class CharacterDatabase : public IDataBaseCallbacks
{
        Database *      m_db;
        IPreparedQuery *m_prepared_account_select;
        IPreparedQuery *m_prepared_account_insert;
        IPreparedQuery *m_prepared_char_insert;
        IPreparedQuery *m_prepared_char_exists;
        IPreparedQuery *m_prepared_char_delete;
        IPreparedQuery *m_prepared_char_select;
        IPreparedQuery *m_prepared_fill;
        IPreparedQuery *m_prepared_costume_insert;

        void        on_connected(Database *db); //prepare statements here
public:
virtual             ~CharacterDatabase();
        bool        CreateLinkedAccount(uint64_t auth_account_id,const std::string &username); // returns true on success
        bool        create(AccountInfo *);
        bool        create(uint64_t gid,uint8_t slot,Character *c);
        bool        fill( AccountInfo *); //!x
        bool        fill( Character *); //! Will call fill(CharacterCostume)
        bool        fill( CharacterCostume *);
        int         remove_account(uint64_t acc_serv_id); //will remove given account, TODO add logging feature
        bool        remove_character(AccountInfo *,uint8_t slot_idx);
        bool        named_character_exists(const std::string &name);
        void        setDb(Database *db) {m_db=db;}
        Database *  getDb() {return m_db;}
};