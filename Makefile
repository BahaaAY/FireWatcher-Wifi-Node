#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := firewatcher-wifi
EXTRA_COMPONENT_DIRS := /Users/bahaa/esp/extra_components/esp-idf-lib/components 
EXTRA_COMPONENT_DIRS += $(PROJECT_PATH)/components
EXCLUDE_COMPONENTS := ads130e08 max7219 mcp23x17 led_strip max31865 ls7366r max31855
include $(IDF_PATH)/make/project.mk

