# 2014, Fortaleza, Ceara
#
# UNIVERSIDADE FEDERAL DO CEARA
# CURSO DE COMPUTACAO
# METODOS NUMERICOS II
# PROFESSORA: Emanuele Marques dos Santos
#
# Paulo Bruno de Sousa Serafim    354086

CC		= g++
CFLAGS	= -c -g

EXECALL	          = execAll
EXECFIRSTBACK     = execFirstBackward
EXECFIRSTFOR      = execFirstForward
EXECFIRSTCENTRAL  = execFirstCentral
EXECFIRSTLAGRANGE = execLagrangeDerivative
EXECSECBACK       = execSecondBackward
EXECSECFOR        = execSecondForward
EXECSECCENTRAL    = execSecondCentral
EXECRICHBACK      = execRichardsonBackWard
EXECRICHFOR       = execRichardsonForward
EXECRICHCENTRAL   = execRichardsonCentral
EXECFIRST         = execFirstDerivative
EXECSECOND        = execSecondDerivative
EXECRICHARDSON    = execRichardsonExtrapolation

FIRST      = FirstDerivative.cpp
SECOND     = SecondDerivative.cpp
RICHARDSON = RichardsonExtrapolation.cpp

METHODS	= \
	$(FIRST) \
	$(SECOND) \
	$(RICHARDSON)

RM		= rm -rf

%.o: %.cpp
	$(CC) $(CFLAGS) $<


# Executaveis

$(EXECALL): \
	$(EXECFIRSTBACK) \
	$(EXECFIRSTFOR) \
	$(EXECFIRSTCENTRAL) \
	$(EXECFIRSTLAGRANGE) \
	$(EXECSECBACK) \
	$(EXECSECFOR) \
	$(EXECSECCENTRAL) \
	$(EXECRICHBACK) \
	$(EXECRICHFOR) \
	$(EXECRICHCENTRAL) \
	$(EXECFIRST) \
	$(EXECSECOND) \
	$(EXECRICHARDSON)
	
	
$(EXECFIRSTBACK): $(FIRST:.cpp = .o) main_firstDerivativeBackward.o
	$(CC) $^ -o $@

$(EXECFIRSTFOR): $(FIRST:.cpp = .o) main_firstDerivativeForward.o
	$(CC) $^ -o $@
	
$(EXECFIRSTCENTRAL): $(FIRST:.cpp = .o) main_firstDerivativeCentral.o
	$(CC) $^ -o $@
	
$(EXECFIRSTLAGRANGE): $(FIRST:.cpp = .o) main_lagrangeDerivative.o
	$(CC) $^ -o $@
	
$(EXECSECBACK): $(SECOND:.cpp = .o) main_secondDerivativeBackward.o
	$(CC) $^ -o $@
	
$(EXECSECFOR): $(SECOND:.cpp = .o) main_secondDerivativeForward.o
	$(CC) $^ -o $@
	
$(EXECSECCENTRAL): $(SECOND:.cpp = .o) main_secondDerivativeCentral.o
	$(CC) $^ -o $@
	
$(EXECRICHBACK): $(RICHARDSON:.cpp = .o) $(FIRST:.cpp = .o) main_richardsonBackward.o
	$(CC) $^ -o $@
	
$(EXECRICHFOR): $(RICHARDSON:.cpp = .o) $(FIRST:.cpp = .o) main_richardsonForward.o
	$(CC) $^ -o $@
	
$(EXECRICHCENTRAL): $(RICHARDSON:.cpp = .o) $(FIRST:.cpp = .o) main_richardsonCentral.o
	$(CC) $^ -o $@
	
$(EXECFIRST): $(FIRST:.cpp = .o) main_firstDerivative.o
	$(CC) $^ -o $@
	
$(EXECSECOND): $(SECOND:.cpp = .o) main_secondDerivative.o
	$(CC) $^ -o $@
	
$(EXECRICHARDSON): $(RICHARDSON:.cpp = .o) $(FIRST:.cpp = .o) main_richardsonExtrapolation.o
	$(CC) $^ -o $@


# make's individuais

all: $(EXECALL)

firstBackward: $(EXECFIRSTBACK) 

firstForward: $(EXECFIRSTFOR)

firstCentral: $(EXECFIRSTCENTRAL) 

lagrangeDerivative: $(EXECFIRSTLAGRANGE) 

secondBackward: $(EXECSECBACK)

secondForward: $(EXECSECFOR)

secondCentral: $(EXECSECCENTRAL) 

richardsonBackward: $(EXECRICHBACK)

richardsonForward: $(EXECRICHFOR) 

richardsonCentral: $(EXECRICHCENTRAL) 

firstDerivative: $(EXECFIRST) 

secondDerivative: $(EXECSECOND) 

richardsonExtrapolation: $(EXECRICHARDSON)


# outra opcoes

.PHONY: clean cleanall

clean:
	$(RM) *.o *~

cleanall:
	$(RM) $(EXECFIRSTBACK) $(EXECFIRSTFOR) $(EXECFIRSTCENTRAL) $(EXECFIRSTLAGRANGE) $(EXECSECBACK) $(EXECSECFOR) $(EXECSECCENTRAL) $(EXECRICHBACK) $(EXECRICHFOR) $(EXECRICHCENTRAL) $(EXECFIRST) $(EXECSECOND) $(EXECRICHARDSON) *.o *~

help:
	@echo "# "
	@echo "# ----- MAKE HELP -----"
	@echo "# "
	@echo "#     make     : Compila todos os arquivos e gera varios executaveis."
	@echo "#     make all : O mesmo que make."
	@echo "# "
	@echo "#     make firstBackward      : Compila somente os arquivos do metodo de primeira derivada de"
	@echo "#                                 backward difference. Gera executavel execFirstBackward."
	@echo "#     make firstForward       : Compila somente os arquivos do metodo de primeira derivada de"
	@echo "#                                 forward difference. Gera executavel execFirstForward."
	@echo "#     make firstCentral       : Compila somente os arquivos do metodo de primeira derivada de"
	@echo "#                                 central difference. Gera executavel execFirstCentral."
	@echo "#     make lagrangeDerivative : Compila somente os arquivos do metodo de Lagrange."
	@echo "#                                 Gera executavel execLagrangeDerivative."
	@echo "#     make firstDerivative    : Compila todos os arquivos dos metodos de primeira derivada."
	@echo "#                                 Gera executavel execFirstDerivative."
	@echo "#     make secondBackward   : Compila somente os arquivos do metodo de segunda derivada de"
	@echo "#                               backward difference. Gera executavel execSecondBackward."
	@echo "#     make secondForward    : Compila somente os arquivos do metodo de segunda derivada de"
	@echo "#                               forward difference. Gera executavel execSecondForward."
	@echo "#     make secondCentral    : Compila somente os arquivos do metodo de segunda derivada de"
	@echo "#                               central difference. Gera executavel execSecondCentral."
	@echo "#     make secondDerivative : Compila todos os arquivos dos metodos de segunda derivada."
	@echo "#                               Gera executavel execSecondDerivative."
	@echo "#     make richardsonBackward      : Compila somente os arquivos do metodo de extrapolacao de Richardson"
	@echo "#                                      para backward difference. Gera executavel execSecondBackward."
	@echo "#     make richardsonForward       : Compila somente os arquivos do metodo de extrapolacao de Richardson"
	@echo "#                                      para forward difference. Gera executavel execSecondForward."
	@echo "#     make richardsonCentral       : Compila somente os arquivos do metodo de extrapolacao de Richardson"
	@echo "#                                      para central difference. Gera executavel execSecondCentral."
	@echo "#     make richardsonExtrapolation : Compila todos os arquivos dos metodos de extrapolacao de Richardson."
	@echo "#                                      Gera executavel execRichardsonExtrapolation."
	@echo "#     make clean     : Elimina os arquivos criados no processo de compilacao."
	@echo "#     make cleanall  : O mesmo que make clean e elimina tambem os executaveis."
	@echo "#     make help      : Mostra esta ajuda."
	@echo "# "
	@echo "#     Para mais informacoes consulte o arquivo README."
	@echo "# "
