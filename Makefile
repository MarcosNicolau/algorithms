SHELL := /bin/bash

CC := gcc

test:
	$(CC) ./tests/$(TEST_FILE_NAME)

