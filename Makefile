VERSION=0.0.1
PREFIX?=/usr/local

BUILD_DIR=bazel-bin
NAME=nascodec-cpp
LIB_NAME=lib$(NAME)
LIBSTATIC_BIN=$(BUILD_DIR)/$(LIB_NAME).a
LIBDYN_BIN=$(BUILD_DIR)/$(LIB_NAME).so

.PHONY: test clean install uninstall
$(LIBSTATIC_BIN):
	bazel build //:nascodec-cpp

$(LIBDYN_BIN):
	bazel build //:nascodec-cpp


all: $(LIBSTATIC_BIN) $(LIBDYN_BIN)

debug: $(LIBSTATIC_BIN) $(LIBDYN_BIN)
	bazel build -c dbg :all

test: debug
	bazel test :all

clean:
	bazel clean

install: all
	# static lib
	mkdir -p $(DESTDIR)$(PREFIX)/lib/$(NAME)/$(VERSION)/
	cp $(LIBSTATIC_BIN) $(LIBDYN_BIN) $(DESTDIR)$(PREFIX)/lib/$(NAME)/$(VERSION)/
	chmod 644 $(DESTDIR)$(PREFIX)/lib/$(NAME)/$(VERSION)/*
	# c headers
	mkdir -p $(DESTDIR)$(PREFIX)/include/$(NAME)-$(VERSION)
	cp -r include/* $(DESTDIR)$(PREFIX)/include/$(NAME)-$(VERSION)
	# pkgconfig
	mkdir -p $(DESTDIR)$(PREFIX)/share/pkgconfig
	sed $(NAME).pc.in \
		-e "s/@VERSION@/$(VERSION)/g;s/@NAME@/$(NAME)/g;s,@PREFIX@,$(PREFIX),g;s/@LIBNAME@/$(LIBNAME)/g" \
		> $(DESTDIR)$(PREFIX)/share/pkgconfig/$(NAME)-$(VERSION).pc

uninstall:
	rm -vrf $(DESTDIR)$(PREFIX)/lib/$(NAME)/$(VERSION)
	rm -vrf $(DESTDIR)$(PREFIX)/include/$(NAME)-$(VERSION)
	rm -vf  $(DESTDIR)$(PREFIX)/share/pkgconfig/$(NAME)-$(VERSION).pc
