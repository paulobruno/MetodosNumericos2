# 2014, Fortaleza, Ceara
#
# UNIVERSIDADE FEDERAL DO CEARA
# CURSO DE COMPUTACAO
# METODOS NUMERICOS II
# PROFESSORA: Emanuele Marques dos Santos
#
# Jose Orlando Barbosa Filho      336224
# Paulo Bruno de Sousa Serafim    354086

CC		= g++
CFLAGS	= -c

EXECALL	      = execAll
EXECTRAPEZIUM = execTrapezium
EXECSIMPSON13 = execSimpson13
EXECSIMPSON38 = execSimpson38
EXECCLOSEDNC  = execClosedNC
EXECOPENNC    = execOpenNC
EXECROMBERG   = execRomberg

CLOSED  = ClosedNewtonCotes.cpp
OPEN    = OpenNewtonCotes.cpp
ROMBERG = RombergIntegration.cpp

METHODS	= \
	$(CLOSED) \
	$(OPEN) \
	$(ROMBERG)

RM		= rm -rf

%.o: %.cpp
	$(CC) $(CFLAGS) $<


# Executaveis

$(EXECALL): \
	$(EXECTRAPEZIUM) \
	$(EXECSIMPSON13) \
	$(EXECSIMPSON38) \
	$(EXECCLOSEDNC) \
	$(EXECOPENNC) \
	$(EXECROMBERG) 

$(EXECTRAPEZIUM): $(CLOSED:.cpp = .o) main_trapezium.o
	$(CC) $^ -o $@

$(EXECSIMPSON13): $(CLOSED:.cpp = .o) main_simpson13.o
	$(CC) $^ -o $@

$(EXECSIMPSON38): $(CLOSED:.cpp = .o) main_simpson38.o
	$(CC) $^ -o $@

$(EXECCLOSEDNC): $(CLOSED:.cpp = .o) main_closedNewtonCotes.o
	$(CC) $^ -o $@

$(EXECOPENNC): $(OPEN:.cpp = .o) main_openNewtonCotes.o
	$(CC) $^ -o $@

$(EXECROMBERG): $(ROMBERG:.cpp = .o) main_romberg.o
	$(CC) $^ -o $@


# make's individuais

all: $(EXECALL)

trapezium: $(EXECTRAPEZIUM)

simpson13: $(EXECSIMPSON13)

simpson38: $(EXECSIMPSON38)

closedNC: $(EXECCLOSEDNC)

openNC: $(EXECOPENNC)

romberg: $(EXECROMBERG)


# outra opcoes

.PHONY: clean cleanall

clean:
	$(RM) *.o *~

cleanall:
	$(RM) $(EXEC) *.o *~

help:
	@echo "# "
	@echo "# ----- MAKE HELP -----"
	@echo "# "
	@echo "#     make           : Compila todos os arquivos e gera varios executaveis."
	@echo "#     make all       : O mesmo que make."
	@echo "#     make trapezium : Compila somente os arquivos do metodo do trapezio."
	@echo "#                        Gera executavel execTrapezium."
	@echo "#     make simpson13 : Compila somente os arquivos do metodo 1/3 de Simpson."
	@echo "#                        Gera executavel execSimpson13."
	@echo "#     make simpson38 : Compila somente os arquivos do metodo 3/8 de Simpson."
	@echo "#                        Gera executavel execSimpson38."
	@echo "#     make closedNC  : Compila todos os arquivos dos metodos fechados de"
	@echo "#                        Newton-Cotes. Gera executavel execClosedNC."
	@echo "#     make openNC    : Compila todos os arquivos dos metodos abertos de"
	@echo "#                        Newton-Cotes. Gera executavel execOpenNC."
	@echo "#     make romberg   : Compila somente os arquivos do metodo de Romberg."
	@echo "#                        Gera executavel execRomberg."
	@echo "#     make clean     : Elimina os arquivos criados no processo de compilacao."
	@echo "#     make cleanall  : O mesmo que make clean e elimina tambem o executavel."
	@echo "#     make help      : Mostra esta ajuda."
	@echo "# "
