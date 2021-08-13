biquadris: main.o game.o grid.o BlockCell.o BaseCell.o decorator.o cell.o
	g++ main.o game.o grid.o BlockCell.o BaseCell.o decorator.o cell.o -o biquadris

main.o: main.cc game.h
	g++ -std=c++14 -Werror=vla -c main.cc

game.o: game.cc game.h grid.h
	g++ -std=c++14 -Werror=vla -c game.cc

grid.o: grid.cc grid.h
	g++ -std=c++14 -Werror=vla -c grid.cc

BlockCell.o: BlockCell.cc BlockCell.h cell.h
	g++ -std=c++14 -Werror=vla -c BlockCell.cc

BaseCell.o: BaseCell.cc BaseCell.h cell.h
	g++ -std=c++14 -Werror=vla -c BaseCell.cc

decorator.o: decorator.cc decorator.h cell.h
	g++ -std=c++14 -Werror=vla -c decorator.cc

cell.o: cell.cc cell.h
	g++ -std=c++14 -Werror=vla -c cell.cc
