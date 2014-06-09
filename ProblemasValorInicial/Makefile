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

EXECALL	  = execAll
EXECRK    = execRungeKutta
EXECEULER = execForwardEuler
EXECRK2   = execRungeKutta2nd
EXECRK3   = execRungeKutta3rd
EXECRK4   = execRungeKutta4th
EXECADAMS = execAdamsPc
EXECPC3	  = execAdamsPc3rd
EXECPC4	  = execAdamsPc4th

RUNGEKUTTA = RungeKutta.cpp 
ADAMSPREDICTORCORRECTOR = AdamsPredictorCorrector.cpp

METHODS	= \
	$(RUNGEKUTTA) \
	$(ADAMSPREDICTORCORRECTOR)

RM		= rm -rf

%.o: %.cpp
	$(CC) $(CFLAGS) $<


# Executaveis

$(EXECALL): \
	$(EXECRK) \
	$(EXECEULER) \
	$(EXECRK2) \
	$(EXECRK3) \
	$(EXECRK4) \
	$(EXECADAMS) \
	$(EXECPC3) \
	$(EXECPC4)
	
$(EXECRK): $(RUNGEKUTTA:.cpp = .o) mainRungeKutta.cpp
	$(CC) $^ -o $@
	
$(EXECEULER): $(RUNGEKUTTA:.cpp = .o) mainForwardEuler.cpp
	$(CC) $^ -o $@
	
$(EXECRK2): $(RUNGEKUTTA:.cpp = .o) mainRungeKutta2.cpp
	$(CC) $^ -o $@
	
$(EXECRK3): $(RUNGEKUTTA:.cpp = .o) mainRungeKutta3.cpp
	$(CC) $^ -o $@
	
$(EXECRK4): $(RUNGEKUTTA:.cpp = .o) mainRungeKutta4.cpp
	$(CC) $^ -o $@
	
$(EXECADAMS): $(ADAMSPREDICTORCORRECTOR:.cpp = .o) $(RUNGEKUTTA:.cpp = .o) mainAdamsPredictorCorrector.cpp
	$(CC) $^ -o $@
	
$(EXECPC3): $(ADAMSPREDICTORCORRECTOR:.cpp = .o) $(RUNGEKUTTA:.cpp = .o) mainAdamsPc3.cpp
	$(CC) $^ -o $@
	
$(EXECPC4): $(ADAMSPREDICTORCORRECTOR:.cpp = .o) $(RUNGEKUTTA:.cpp = .o) mainAdamsPc4.cpp
	$(CC) $^ -o $@
	
	
# make's individuais

all: $(EXECALL)

rungeKutta: $(EXECRK)

forwardEuler: $(EXECEULER)

rungeKutta2nd: $(EXECRK2)

rungeKutta3rd: $(EXECRK3)

rungeKutta4th: $(EXECRK4)

adamsPc: $(EXECADAMS)

adamsPc3rd: $(EXECPC3)

adamsPc4th: $(EXECPC4)


# outra opcoes

.PHONY: clean cleanall

clean:
	$(RM) *.o *~

cleanall:
	$(RM) $(EXECRK) $(EXECEULER) $(EXECRK2) $(EXECRK3) $(EXECRK4) $(EXECADAMS) $(EXECPC3) $(EXECPC4) *.o *~

help:
	@echo "# "
	@echo "# ----- MAKE HELP -----"
	@echo "# "
	@echo "#     make     : Compila todos os arquivos e gera varios executaveis."
	@echo "#     make all : O mesmo que make."
	@echo "# "
	@echo "#     make rungeKutta    : Compila os arquivos do metodo de Runge-Kutta para qualquer ordem."
	@echo "#                            Gera executavel execRungeKutta."
	@echo "#     make forwardEuler  : Compila os arquivos do metodo de Forward Euler."
	@echo "#                            Gera executavel execForwardEuler."
	@echo "#     make rungeKutta2nd : Compila os arquivos do metodo de Runge-Kutta segunda ordem."
	@echo "#                            Gera executavel execRungeKutta2nd."
	@echo "#     make rungeKutta3rd : Compila os arquivos do metodo de Runge-Kutta terceira ordem."
	@echo "#                            Gera executavel execRungeKutta3rd."
	@echo "#     make rungeKutta4th : Compila os arquivos do metodo de Runge-Kutta quarta ordem."
	@echo "#                            Gera executavel execRungeKutta4th."
	@echo "#     make adamsPc       : Compila os arquivos do metodo Preditor-corretor de Adams qualquer ordem."
	@echo "#                            Gera executavel execAdamsPc3rd."
	@echo "#     make adamsPc3rd    : Compila os arquivos do metodo Preditor-corretor de Adams terceira ordem."
	@echo "#                            Gera executavel execAdamsPc3rd."
	@echo "#     make adamsPc4th    : Compila os arquivos do metodo Preditor-corretor de Adams quarta ordem."
	@echo "#                            Gera executavel execAdamsPc4th."
	@echo "#     make clean     : Elimina os arquivos criados no processo de compilacao."
	@echo "#     make cleanall  : O mesmo que make clean e elimina tambem os executaveis."
	@echo "#     make help      : Mostra esta ajuda."
	@echo "# "
	@echo "#     Para mais informacoes consulte o arquivo README."
	@echo "# "
