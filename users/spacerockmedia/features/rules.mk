
FEATURE_CALLUM_ENABLE ?= yes
ifeq ($(strip $(FEATURE_CALLUM_ENABLE)), yes)
	SRC += $(USER_PATH)/features/callum.c
	OPT_DEFS += -DFEATURE_CALLUM_ENABLE
endif

FEATURE_SWAPPER_ENABLE ?= yes
ifeq ($(strip $(FEATURE_SWAPPER_ENABLE)), yes)
	SRC += $(USER_PATH)/features/swapper.c
	OPT_DEFS += -DFEATURE_SWAPPER_ENABLE
endif

FEATURE_REPEAT_KEY_ENABLE ?= yes
ifeq ($(strip $(FEATURE_REPEAT_KEY_ENABLE)), yes)
	SRC += $(USER_PATH)/features/repeat_key_callbacks.c
	SRC += $(USER_PATH)/features/repeat_key.c
	OPT_DEFS += -DFEATURE_REPEAT_KEY_ENABLE
endif

FEATURE_SENTENCE_CASE_ENABLE ?= yes
ifeq ($(strip $(FEATURE_SENTENCE_CASE_ENABLE)), yes)
	SRC += $(USER_PATH)/features/sentence_case.c
	OPT_DEFS += -DFEATURE_SENTENCE_CASE_ENABLE
endif

LEADER_ENABLE ?= yes
ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += $(USER_PATH)/features/leader.c
endif

FEATURE_KEYSWAPPER_ENABLE ?= yes
ifeq ($(strip $(FEATURE_KEYSWAPPER_ENABLE)), yes)
	SRC += $(USER_PATH)/features/keyswapper.c
	OPT_DEFS += -FEATURE_KEYSWAPPER_ENABLE
endif

AUDIO_ENABLE ?= no
# ifeq ($(strip $(AUDIO_ENABLE)), yes)
# 	SRC += $(USER_PATH)/features/audio.c
# endif
