
all: compile

configure:
	mkdir -p build
	(cd build && cmake -DCMAKE_BUILD_TYPE=Release ..)
	git submodule init
	git submodule update

configure-debug:
	mkdir -p build
	(cd build && cmake -DCMAKE_BUILD_TYPE=Debug ..)
	git submodule init
	git submodule update

compile:
	make -C build
	(cd build/bin && ./unit_test)

#run:
#	(./build/bin/demo -i examples/logo.png examples/Demo.js)

#debug:
#	(gdb --args ./build/bin/demo -i examples/logo.png examples/Demo.js)

test:
	(cd build/bin && ./unit_test)

clean:
	make -C build clean

distclean:
	(rm -rf build)
