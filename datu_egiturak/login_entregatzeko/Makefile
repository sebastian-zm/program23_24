TARGET_EXEC ?= executable

BUILD_DIR ?= ./build
SRC_DIR ?= ./src
ASSET_DIR ?= ./assets

ASSETS := $(wildcard $(addsuffix /*/*,$(ASSET_DIR)))
COPIED_ASSETS := $(ASSETS:%=$(BUILD_DIR)/%)

SELF_INC_DIRS := $(patsubst %/,%,$(wildcard $(addsuffix /*/,$(SRC_DIR))))
INC_DIRS := $(SELF_INC_DIRS) $(LIB_INC_DIRS)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

SRCS := $(wildcard $(addsuffix /*.c,$(SELF_INC_DIRS)))
SELF_HDRS := $(wildcard $(addsuffix /*.h,$(SELF_INC_DIRS)))
LIB_HDRS := $(wildcard $(addsuffix /*.h,$(LIB_INC_DIRS)))
HDRS := $(SELF_HDRS) $(LIB_HDRS)
SELF_CODE := $(SRCS) $(SELF_HDRS)
CODE := $(SELF_CODE) $(LIB_HDRS)

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CFLAGS := -std=c17 -Wall -Wextra -Werror -pedantic-errors -Og -ggdb3
CPPFLAGS := $(INC_FLAGS) -MMD -MP
LDFLAGS := $(LIB_LDFLAGS)

.PHONY: all clean indent

all: $(BUILD_DIR)/$(TARGET_EXEC) $(COPIED_ASSETS)

clean:
	$(RM) -r $(BUILD_DIR)

indent:
	indent -linux $(SELF_CODE)

tags: $(INC_DIRS)
	ctags --extras=+f $(CODE)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# assets
$(BUILD_DIR)/$(ASSET_DIR)/%: $(ASSET_DIR)/%
	$(MKDIR_P) $(dir $@)
	$(CP) $< $@

-include $(DEPS)

CC ?= gcc
MKDIR_P ?= mkdir -p
CP ?= cp

