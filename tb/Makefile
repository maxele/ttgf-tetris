VERILATOR := verilator
VERILATOR_FLAGS := -Wno-fatal -Wall --trace --timing

SRC_FILES := ../src/tt_um_maxele.sv ../src/vga_graphics.sv ../src/valid_placement.sv ../src/input_buffer.sv

test: ./obj_dir/Vtt_um_maxele
	make -C obj_dir -f Vtt_um_maxele.mk
	./obj_dir/Vtt_um_maxele

./obj_dir/Vtt_um_maxele: lint $(SRC_FILES) tb.cpp
	rm -f ./obj_dir/Vtt_um_maxele
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--cc $(SRC_FILES) tb.cpp \
		--top-module tt_um_maxele \
		--exe tb.cpp \
		-CFLAGS -lSDL3 \
		-LDFLAGS -lSDL3

.PHONY: lint
lint:
	$(VERILATOR) --lint-only -Wall $(SRC_FILES)

.PHONY: clean
clean:
	rm -rf obj_dir
