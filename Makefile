ifndef config
  config=debug
endif
export config

PROJECTS := PIDMenace

.PHONY: all clean help $(PROJECTS)

all: $(PROJECTS)

PIDMenace: 
	@echo "==== Building PIDMenace ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f PIDMenace.make

clean:
	@${MAKE} --no-print-directory -C . -f PIDMenace.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "   debug"
	@echo "   release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   PIDMenace"
	@echo ""
	@echo "For more information, refer to your mother, she knows best, babyboy ;)"
