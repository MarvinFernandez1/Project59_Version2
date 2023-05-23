output: main.o Spiker.o Setter.o Digger.o Skill.o Player.o Team.o Game.o
    g++ main.o Spiker.o Setter.o Digger.o Skill.o Player.o Team.o Game.o -o output

main.o: main.cpp
    g++ -c main.cpp

Spiker.o:
    g++ -c Spiker.cpp Spiker.h

Setter.o:
    g++ -c Setter.cpp Setter.h

Digger.o:
    g++ -c Digger.cpp Digger.h

Skill.o:
    g++ -c Skill.cpp Skill.h

Player.o:
    g++ Player.cpp Player.h

Team.o:
    g++ Team.cpp Team.h

Game.o:
    g++ Game.cpp Game.h

clean:
    rm *.o