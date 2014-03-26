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

EXECALL	       = execAll
EXECTRAPEZIUM  = execTrapezium
EXECSIMPSON13  = execSimpson13
EXECSIMPSON38  = execSimpson38
EXECCLOSEDNC   = execClosedNC
EXECOPENNC     = execOpenNC
EXECROMBERG    = execRomberg
EXECQUADRATURE = execQuadrature
EXECDOUBLETRAPEZIUM = execDoubleTrapezium
EXECDOUBLESIMPSON13 = execDoubleSimpson13
EXECDOUBLECLOSEDNC  = execDoubleClosedNC

CLOSED     = ClosedNewtonCotes.cpp
OPEN       = OpenNewtonCotes.cpp
ROMBERG    = RombergIntegration.cpp
QUADRATURE = 
DOUBLE     = DoubleIntegration.cpp

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
	$(EXECQUADRATURE) \
	$(EXECDOUBLETRAPEZIUM) \
	$(EXECDOUBLESIMPSON13) \
	$(EXECDOUBLECLOSEDNC) 

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

$(EXECQUADRATURE): 

$(EXECDOUBLETRAPEZIUM): $(DOUBLE:.cpp = .o) $(CLOSED:.cpp = .o) main_doubleTrapezium.o
	$(CC) $^ -o $@

$(EXECDOUBLESIMPSON13): $(DOUBLE:.cpp = .o) $(CLOSED:.cpp = .o) main_doubleSimpson13.o
	$(CC) $^ -o $@

$(EXECDOUBLECLOSEDNC): $(DOUBLE:.cpp = .o) $(CLOSED:.cpp = .o) main_doubleIntegration.o
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

doubleTrapezium: $(EXECDOUBLETRAPEZIUM)

doubleSimpson13: $(EXECDOUBLESIMPSON13)

doubleClosedNC: $(EXECDOUBLECLOSEDNC)


# outra opcoes

.PHONY: clean cleanall

clean:
	$(RM) *.o *~

cleanall:
	$(RM) $(EXECTRAPEZIUM) $(EXECSIMPSON13) $(EXECSIMPSON38) $(EXECCLOSEDNC) $(EXECOPENNC) $(EXECROMBERG) $(EXECQUADRATURE) $(EXECDOUBLETRAPEZIUM) $(EXECDOUBLESIMPSON13) $(EXECDOUBLECLOSEDNC) *.o *~

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
	@echo "#     make closedNC  : Compila todos os arquivos dos metodos fechados de Newton-Cotes."
	@echo "#                        Gera executavel execClosedNC."
	@echo "#     make openNC    : Compila todos os arquivos dos metodos abertos de Newton-Cotes."
	@echo "#                        Gera executavel execOpenNC."
	@echo "#     make romberg   : Compila somente os arquivos do metodo de Romberg."
	@echo "#                        Gera executavel execRomberg."
	@echo "#     make quadrature: Compila somente os arquivos do metodo da Quadratura de Gauss."
	@echo "#                        Gera executavel execQuadrature."
	@echo "#     make doubletrap: Compila somente os arquivos de integral dupla metodo do trapezio."
	@echo "#                        Gera executavel execDoubleTrapezium."
	@echo "#     make double13  : Compila somente os arquivos de integral dupla metodo 1/3 de Simpson."
	@echo "#                        Gera executavel execDoubleSimpson13."
	@echo "#     make double    : Compila todos os arquivos dos metodos de integral dupla."
	@echo "#                        Gera executavel execDoubleClosedNC."
	@echo "#     make clean     : Elimina os arquivos criados no processo de compilacao."
	@echo "#     make cleanall  : O mesmo que make clean e elimina tambem os executaveis."
	@echo "#     make help      : Mostra esta ajuda."
	@echo "# "
	@echo "#     Para mais informacoes consulte o arquivo README."
	@echo "# "
