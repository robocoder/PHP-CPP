B0RKED = \
	ConstStaticProp \
	CppClassesInPhp \
	DlUnrestricted \
	EmptyExtension \
	ReturnObject \
	simple

EXAMPLES = \
	CallPhpFunctions \
	ExceptionCatch \
	ExceptionThrow \
	Extension \
	FunctionNoParameters \
	FunctionReturnValue \
	FunctionVoid \
	FunctionWithParameters \
	Globals

.PHONY: all clean $(EXAMPLES)

all clean: $(EXAMPLES)
	for dir in $(EXAMPLES); do \
		$(MAKE) -C $$dir $@; \
	done
