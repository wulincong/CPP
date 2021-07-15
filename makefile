dirs  := enum homework leetcode math Sql test 
files := $(foreach dir, $(dirs), $(wildcard $(dir)/*.exe))

all: 
	echo $(files)
