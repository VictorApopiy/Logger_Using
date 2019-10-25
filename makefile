CC := g++
NAME := logger

lib: lib$(NAME).so

logger: $(NAME)_use
	LD_LIBRARY_PATH=. ./$(NAME)_use

$(NAME)_use: lib$(NAME).so
	$(CC) LoggerUse/src/$(NAME)_use.cpp Shared/src/os_api.cpp  -ldl -o $@ -L. -l$(NAME) -IShared/include


lib$(NAME).so:
	$(CC) -DEXPORT_LOGGER -fPIC logger/src/logger_api.cpp -Ilogger/include -IShared/include -shared -Wl,-soname,lib$(NAME).so $^ -o $@

clean:
	$(RM) $(NAME)_use *.o *.so*

