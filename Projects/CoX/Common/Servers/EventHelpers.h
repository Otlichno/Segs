/*
 * SEGS - Super Entity Game Server
 * http://www.segs.dev/
 * Copyright (c) 2006 - 2019 SEGS Team (see AUTHORS.md)
 * This software is licensed under the terms of the 3-clause BSD License. See LICENSE.md for details.
 */

#pragma once

#include "InternalEvents.h"

using namespace SEGSEvents;

uint64_t get_session_token(Event* ev);
uint64_t get_session_token(InternalEvent* ev);
