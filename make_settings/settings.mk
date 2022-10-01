ifndef SETTINGS_MK
SETTINGS_MK = 1

NAME	= quick_math

CFLAGS	= -Wall -Wextra -Werror -pedantic -std=c++20
IFLAGS	= -I$(IDIR) -I$(IDIR)/data
LFLAGS	= 

SDIR	= src
ODIR	= obj
IDIR	= includes

ifdef DEBUG
	CFLAGS += -g -D DEBUG
endif

ifdef LEAKS
	CFLAGS += -D LEAKS
endif

ifdef FSANITIZE
	CFLAGS += -D FSANITIZE
	CFLAGS += -g -fsanitize=address
endif

include ./make_settings/src_files.mk
OBJ := $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRC))

endif
