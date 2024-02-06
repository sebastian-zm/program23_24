TARGET_EXEC ?= executable

BUILD_DIR ?= ./build
SRC_DIR ?= ./src
ASSET_DIR ?= ./assets
HELPERS_DIR ?= $(abspath ../../helpers)

ASSETS := $(wildcard $(addsuffix /*/*,$(ASSET_DIR)))
COPIED_ASSETS := $(ASSETS:%=$(BUILD_DIR)/%)

INC_DIRS := $(patsubst %/,%,$(wildcard $(addsuffix /*/,$(SRC_DIR)))) $(LIB_INC_DIRS) $(HELPERS_DIR)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

SRCS := $(wildcard $(addsuffix /*.c,$(INC_DIRS)))
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CFLAGS := -std=c17 -Wall -Wextra -Werror -pedantic-errors -Og -ggdb3
CPPFLAGS := $(INC_FLAGS) -MMD -MP
LDFLAGS := $(LIB_LDFLAGS)

.PHONY: all clean

all: $(BUILD_DIR)/$(TARGET_EXEC) $(COPIED_ASSETS)

clean:
	$(RM) -r $(BUILD_DIR)

tags: $(INC_DIRS)
	ctags -R $(INC_DIRS)

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

