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
CFLAGS	= -c -g

EXECALL	       = execAll
EXECTRAPEZIUM  = execTrapezium
EXECSIMPSON13  = execSimpson13
EXECSIMPSON38  = execSimpson38
EXECCLOSEDNC   = execClosedNC
EXECOPENNC     = execOpenNC
EXECROMBERG    = execRomberg
EXECQUADRATURE = execQuadrature

CLOSED     = ClosedNewtonCotes.cpp
OPEN       = OpenNewtonCotes.cpp
ROMBERG    = RombergIntegration.cpp
QUADRATURE = GaussianQuadrature.cpp

METHODS	= \
	$(CLOSED) \
	$(OPEN) \
	$(ROMBERG) \
	$(QUADRATURE) \
	$(DOUBLE)

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
	$(EXECROMBERG) \
	$(EXECQUADRATURE) 

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

$(EXECROMBERG): $(ROMBERG:.cpp = .o) $(CLOSED:.cpp = .o) main_romberg.o
	$(CC) $^ -o $@

$(EXECQUADRATURE): $(QUADRATURE:.cpp = o) main_quadrature.o
	$(CC) $^ -o $@


# make's individuais

all: $(EXECALL)

trapezium: $(EXECTRAPEZIUM)

simpson13: $(EXECSIMPSON13)

simpson38: $(EXECSIMPSON38)

closedNC: $(EXECCLOSEDNC)

openNC: $(EXECOPENNC)

romberg: $(EXECROMBERG)

quadrature: $(EXECQUADRATURE)


# outra opcoes

.PHONY: clean cleanall

clean:
	$(RM) *.o *~

cleanall:
	$(RM) $(EXECTRAPEZIUM) $(EXECSIMPSON13) $(EXECSIMPSON38) $(EXECCLOSEDNC) $(EXECOPENNC) $(EXECROMBERG) $(EXECQUADRATURE) *.o *~

help:
	@echo "# "
	@echo "# ----- MAKE HELP -----"
	@echo "# "
	@echo "#     make           : Compila todos os arquivos e gera varios executaveis."
	@echo "#     make all       : O mesmo que make."
	@echo "# "
	@echo "#     make trapezium : Compila somente os arquivos do metodo do trapezio."
	@echo "#                        Gera executavel execTrapezium."
	@echo "#     make simpson13 : Compila somente os arquivos do metodo 1/3 de Simpson."
	@echo "#                        Gera executavel execSimpson13."
	@echo "#     make simpson38 : Compila somente os arquivos do metodo 3/8 de Simpson."
	@echo "#                        Gera executavel execSimpson38."
	@echo "#     make closedNC  : Compila todos os arquivos dos metodos fechados de Newton-Cotes."
	@echo "#                        Gera executavel execClosedNC."
	@echo "#     make openNC    : Compila todos os arquivos dos metodos abertos de Newton-Cotes."
	@echo "#                        Gera executavel execOpenNC."
	@echo "#     make romberg   : Compila somente os arquivos do metodo de Romberg."
	@echo "#                        Gera executavel execRomberg."
	@echo "#     make quadrature: Compila somente os arquivos do metodo da Quadratura de Gauss."
	@echo "#                        Gera executavel execQuadrature."
	@echo "#     make clean     : Elimina os arquivos criados no processo de compilacao."
	@echo "#     make cleanall  : O mesmo que make clean e elimina tambem os executaveis."
	@echo "#     make help      : Mostra esta ajuda."
	@echo "# "
	@echo "#     Para mais informacoes consulte o arquivo README."
	@echo "# "
