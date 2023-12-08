// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#if defined(SPLIT_KEYBOARD)
#    include "features/split_config.h"
#endif

#ifdef FEATURE_LEADER_ENABLE
#    include "features/leader_config.h"
#endif

#ifdef AUDIO_ENABLE
#    include "features/audio_config.h"
#endif // AUDIO_ENABLE

