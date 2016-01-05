#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Infinito 10000.0

#include "Queue.h"
#include "SimulationRoutines.h"

main()
{
	int flag = 0,
		terminar = 0,
		MaximoUtentes,
		NumUtentes = 0,
		NumUtentesSistema,
		EstadoSAtend1,
		EstadoSAtend2,
		TotalUtentesFilaSAtend,
		EstadoSTriag1,
		EstadoSTriag2,
		TotalUtentesFilaSTriag,
		EstadoSMed1,
		TotalUtentesFilaSMed1,
		EstadoSMed2,
		TotalUtentesFilaSMed2,
		EstadoSMed3,
		TotalUtentesFilaSMed3,
		EstadoSMed4,
		TotalUtentesFilaSMed4,
		EstadoSExam1,
		TotalUtentesFilaSExam1,
		EstadoSExam2,
		TotalUtentesFilaSExam2,
		EstadoSExam3,
		TotalUtentesFilaSExam3,
		EstadoSExam4,
		TotalUtentesFilaSExam4,
		TipoEvento;

	float	TempoPrimeiraChegada,
		*FilaEventosChegadaSAtend,
		*FilaEventosChegadaSTriag,
		*FilaEventosChegadaSMed1,
		*FilaEventosChegadaSMed2,
		*FilaEventosChegadaSMed3,
		*FilaEventosChegadaSMed4,
		*FilaEventosChegadaSExam1,
		*FilaEventosChegadaSExam2,
		*FilaEventosChegadaSExam3,
		*FilaEventosChegadaSExam4,
		Clock,
		TempoProximaChegadaSAtend,
		TempoProximaChegadaSTriag,
		TempoProximaChegadaSMed1,
		TempoProximaChegadaSMed2,
		TempoProximaChegadaSMed3,
		TempoProximaChegadaSMed4,
		TempoPartidaSAtend1,
		TempoPartidaSAtend2,
		TempoPartidaSMed1,
		TempoPartidaSMed2,
		TempoPartidaSMed3,
		TempoPartidaSMed4,
		TempoTotalEsperaSAtend,
		TempoOcupacaoSAtend1,
		TempoOcupacaoSAtend2,
		TempoOcupacaoSMed1,
		TempoOcupacaoSMed2,
		TempoOcupacaoSMed3,
		TempoOcupacaoSMed4,
		TempoPartidaSTriag1,
		TempoPartidaSTriag2,
		TempoTotalEsperaSTriag,
		TempoTotalEsperaSMed1,
		TempoTotalEsperaSMed2,
		TempoTotalEsperaSMed3,
		TempoTotalEsperaSMed4,
		TempoOcupacaoSTriag1,
		TempoOcupacaoSTriag2,
		TempoTotalPermanencia,
		TempoTotalSistema,
		TempoProximaChegadaSMedTemp=0,
		EventosChegadaSExam1,
		TempoProximaChegadaSExam1,
		TempoPartidaSExam1,
		TempoTotalEsperaSExam1,
		TempoOcupacaoSExam1,
		UtentesFilaSExam1,
		EventosChegadaSExam2,
		TempoProximaChegadaSExam2,
		TempoPartidaSExam2,
		TempoTotalEsperaSExam2,
		TempoOcupacaoSExam2,
		UtentesFilaSExam2,
		EventosChegadaSExam3,
		TempoProximaChegadaSExam3,
		TempoPartidaSExam3,
		TempoTotalEsperaSExam3,
		TempoOcupacaoSExam3,
		UtentesFilaSExam3,
		EventosChegadaSExam4,
		TempoProximaChegadaSExam4,
		TempoPartidaSExam4,
		TempoTotalEsperaSExam4,
		TempoOcupacaoSExam4,
		UtentesFilaSExam4,
		TempoProximaChegadaSExamTemp = 0;
	printf("Com quantos Utentes quer realizar a simulacao ? ");
	scanf_s("%d", &MaximoUtentes);

	srand((unsigned int)time(NULL));

	TempoPrimeiraChegada = DeterminarTempoEntreChegadas(2.0);

	Inicializacao(TempoPrimeiraChegada,
		&NumUtentesSistema,
		&EstadoSAtend1,
		&EstadoSAtend2,
		&FilaEventosChegadaSAtend,
		&Clock,
		&TempoProximaChegadaSAtend,
		&TempoPartidaSAtend1,
		&TempoPartidaSAtend2,
		&TempoTotalEsperaSAtend,
		&TempoOcupacaoSAtend1,
		&TempoOcupacaoSAtend2,
		&TempoTotalPermanencia,
		&TotalUtentesFilaSAtend,
		&EstadoSTriag1,
		&EstadoSTriag2,
		&FilaEventosChegadaSTriag,
		&TempoProximaChegadaSTriag,
		&TempoPartidaSTriag1,
		&TempoPartidaSTriag2,
		&TempoTotalEsperaSTriag,
		&TempoOcupacaoSTriag1,
		&TempoOcupacaoSTriag2,
		&TotalUtentesFilaSTriag,
		&EstadoSMed1,
		&FilaEventosChegadaSMed1,
		&TempoProximaChegadaSMed1,
		&TempoPartidaSMed1,
		&TempoTotalEsperaSMed1,
		&TempoOcupacaoSMed1,
		&TotalUtentesFilaSMed1,
		&EstadoSMed2,
		&FilaEventosChegadaSMed2,
		&TempoProximaChegadaSMed2,
		&TempoPartidaSMed2,
		&TempoTotalEsperaSMed2,
		&TempoOcupacaoSMed2,
		&TotalUtentesFilaSMed2,
		&EstadoSMed3,
		&FilaEventosChegadaSMed3,
		&TempoProximaChegadaSMed3,
		&TempoPartidaSMed3,
		&TempoTotalEsperaSMed3,
		&TempoOcupacaoSMed3,
		&TotalUtentesFilaSMed3,
		&EstadoSMed4,
		&FilaEventosChegadaSMed4,
		&TempoProximaChegadaSMed4,
		&TempoPartidaSMed4,
		&TempoTotalEsperaSMed4,
		&TempoOcupacaoSMed4,
		&TotalUtentesFilaSMed4,
		&EstadoSExam1,
		&FilaEventosChegadaSExam1,
		&TempoProximaChegadaSExam1,
		&TempoPartidaSExam1,
		&TempoTotalEsperaSExam1,
		&TempoOcupacaoSExam1,
		&TotalUtentesFilaSExam1,
		&EstadoSExam2,
		&FilaEventosChegadaSExam2,
		&TempoProximaChegadaSExam2,
		&TempoPartidaSExam2,
		&TempoTotalEsperaSExam2,
		&TempoOcupacaoSExam2,
		&TotalUtentesFilaSExam2,
		&EstadoSExam3,
		&FilaEventosChegadaSExam3,
		&TempoProximaChegadaSExam3,
		&TempoPartidaSExam3,
		&TempoTotalEsperaSExam3,
		&TempoOcupacaoSExam3,
		&TotalUtentesFilaSExam3,
		&EstadoSExam4,
		&FilaEventosChegadaSExam4,
		&TempoProximaChegadaSExam4,
		&TempoPartidaSExam4,
		&TempoTotalEsperaSExam4,
		&TempoOcupacaoSExam4,
		&TotalUtentesFilaSExam4);

	while (flag == 0)
	{	
		GestaoTempo(TempoProximaChegadaSAtend,
					TempoPartidaSAtend1,
					TempoPartidaSAtend2,
					TempoProximaChegadaSTriag,
					TempoPartidaSTriag1,
					TempoPartidaSTriag2,
					TempoProximaChegadaSMed1,
					TempoPartidaSMed1,
					TempoProximaChegadaSMed2,
					TempoPartidaSMed2,
					TempoProximaChegadaSMed3,
					TempoPartidaSMed3,
					TempoProximaChegadaSMed4,
					TempoPartidaSMed4,
					TempoProximaChegadaSExam1,
					TempoPartidaSExam1,
					TempoProximaChegadaSExam2,
					TempoPartidaSExam2,
					TempoProximaChegadaSExam3,
					TempoPartidaSExam3,
					TempoProximaChegadaSExam4,
					TempoPartidaSExam4,
					&Clock,
					&TipoEvento);

		if (Clock < Infinito)
			TempoTotalSistema = Clock;

		printf("\n\n Clock = %f", Clock);
		printf("\n TipoEvento = %d ", TipoEvento);

		printf("\nTempoProximaChegadaSAtend = %f", TempoProximaChegadaSAtend);
		printf("\nFila espera Atendimento:  ");
		ShowQueue(FilaEventosChegadaSAtend);	
		printf("\n TempoPartidaSAtend1 = %f", TempoPartidaSAtend1);
		printf("\n TempoPartidaSAtend2 = %f", TempoPartidaSAtend2);
		printf("\n TempoProximaChegadaSTriag = %f", TempoProximaChegadaSTriag);
		printf("\nFila espera Atendimento:  ");
		ShowQueue(FilaEventosChegadaSTriag);
		printf("\n TempoPartidaSTriag1 = %f", TempoPartidaSTriag1);
		printf("\n TempoPartidaSTriag2 = %f", TempoPartidaSTriag2);		
		printf("\nTempoProximaChegadaSMed1 = %f", TempoProximaChegadaSMed1);
		printf("\nFila espera Atendimento Medico1:  ");
		ShowQueue(FilaEventosChegadaSMed1);
		printf("\n TempoPartidaSAtend1 = %f", TempoPartidaSMed1);
		printf("\nTempoProximaChegadaSMed2 = %f", TempoProximaChegadaSMed2);
		printf("\nFila espera Atendimento Medico2:  ");
		ShowQueue(FilaEventosChegadaSMed2);
		printf("\n TempoPartidaSAtend2 = %f", TempoPartidaSMed2);
		printf("\nTempoProximaChegadaSMed3 = %f", TempoProximaChegadaSMed3);
		printf("\nFila espera Atendimento Medico3:  ");
		ShowQueue(FilaEventosChegadaSMed3);
		printf("\n TempoPartidaSMed3 = %f", TempoPartidaSMed3);
		printf("\nTempoProximaChegadaSMed4 = %f", TempoProximaChegadaSMed4);
		printf("\nFila espera Atendimento Medico4:  ");
		ShowQueue(FilaEventosChegadaSMed4);
		printf("\n TempoPartidaSMed4 = %f\n", TempoPartidaSMed4);
		printf("\nTempoProximaChegadaSExam1 = %f", TempoProximaChegadaSExam1);
		printf("\nFila espera Atendimento Medico1:  ");
		ShowQueue(FilaEventosChegadaSExam1);
		printf("\n TempoPartidaSAtend1 = %f", TempoPartidaSExam1);
		printf("\nTempoProximaChegadaSExam2 = %f", TempoProximaChegadaSExam2);
		printf("\nFila espera Atendimento Medico2:  ");
		ShowQueue(FilaEventosChegadaSExam2);
		printf("\n TempoPartidaSAtend2 = %f", TempoPartidaSExam2);
		printf("\nTempoProximaChegadaSExam3 = %f", TempoProximaChegadaSExam3);
		printf("\nFila espera Atendimento Medico3:  ");
		ShowQueue(FilaEventosChegadaSExam3);
		printf("\n TempoPartidaSExam4 = %f", TempoPartidaSExam4);
		printf("\nTempoProximaChegadaSExam4 = %f", TempoProximaChegadaSExam4);
		printf("\nFila espera Atendimento Medico4:  ");
		ShowQueue(FilaEventosChegadaSExam4);
		printf("\n TempoPartidaSExam4 = %f", TempoPartidaSExam4);
		
		system("PAUSE");

		if (TipoEvento == -1)
			break;

		switch (TipoEvento)
		{
		case 0: NumUtentes++;
			EventoChegadaSistema(Clock,
				&NumUtentesSistema,
				&EstadoSAtend1,
				&EstadoSAtend2,
				&FilaEventosChegadaSAtend,
				&TempoProximaChegadaSAtend,
				&TempoPartidaSAtend1,
				&TempoPartidaSAtend2,
				&TempoOcupacaoSAtend1,
				&TempoOcupacaoSAtend2,
				&TempoTotalPermanencia,
				&TotalUtentesFilaSAtend);

			if (NumUtentes == MaximoUtentes)
				TempoProximaChegadaSAtend = Infinito;
			break;
		case 1: EventoPartida(Clock,
			&NumUtentesSistema,
			&EstadoSAtend1,
			&FilaEventosChegadaSAtend,
			&TempoPartidaSAtend1,
			&TempoProximaChegadaSTriag,
			&TempoOcupacaoSAtend1,
			&TempoTotalEsperaSAtend,
			&TempoTotalPermanencia);
			break;
		case 2: EventoPartida(Clock,
			&NumUtentesSistema,
			&EstadoSAtend2,
			&FilaEventosChegadaSAtend,
			&TempoPartidaSAtend2,
			&TempoProximaChegadaSTriag,
			&TempoOcupacaoSAtend2,
			&TempoTotalEsperaSAtend,
			&TempoTotalPermanencia);
			break;
		case 3: EventoChegadaProcServCom2Serv(Clock,
							&NumUtentesSistema,
							&EstadoSTriag1,
							&EstadoSTriag2,
							&FilaEventosChegadaSTriag,
							&TempoProximaChegadaSTriag,
							&TempoPartidaSTriag1,
							&TempoPartidaSTriag2,
							&TempoOcupacaoSTriag1,
							&TempoOcupacaoSTriag2,
							&TempoTotalPermanencia,
							&TotalUtentesFilaSTriag);
			if (NumUtentes == MaximoUtentes)
				TempoProximaChegadaSTriag = Infinito;
			break;
		case 4: 			
			EventoPartida(Clock,
							&NumUtentesSistema,
							&EstadoSTriag1,
							&FilaEventosChegadaSTriag,
							&TempoPartidaSTriag1,
							&TempoProximaChegadaSMedTemp,
							&TempoOcupacaoSTriag1,
							&TempoTotalEsperaSTriag,
							&TempoTotalPermanencia);

			SelectOneOf4Serv(TempoProximaChegadaSMedTemp,
						&TempoProximaChegadaSMed1,
						&TempoProximaChegadaSMed2,
						&TempoProximaChegadaSMed3,
						&TempoProximaChegadaSMed4);
				break;
		case 5: EventoPartida (Clock,
							&NumUtentesSistema,
							&EstadoSTriag2,
							&FilaEventosChegadaSTriag,
							&TempoPartidaSTriag2,
							&TempoProximaChegadaSMedTemp,
							&TempoOcupacaoSTriag2,
							&TempoTotalEsperaSTriag,
							&TempoTotalPermanencia);

			SelectOneOf4Serv(TempoProximaChegadaSMedTemp,
						&TempoProximaChegadaSMed1,
						&TempoProximaChegadaSMed2,
						&TempoProximaChegadaSMed3,
						&TempoProximaChegadaSMed4);
			break;
		case 6: EventoChegadaProcServCom1Serv(Clock,		//para chegar 
							&NumUtentesSistema,
							&EstadoSMed1,
							&FilaEventosChegadaSMed1,
							&TempoProximaChegadaSMed1,
							&TempoPartidaSMed1,
							&TempoOcupacaoSMed1,
							&TempoTotalPermanencia,
							&TotalUtentesFilaSMed1);
			break;
		case 7: EventoPartida (Clock,
							&NumUtentesSistema,
							&EstadoSMed1,
							&FilaEventosChegadaSMed1,
							&TempoPartidaSMed1,
							&TempoProximaChegadaSExamTemp,
							&TempoOcupacaoSMed1,
							&TempoTotalEsperaSMed1,
							&TempoTotalPermanencia);

			SelectOneOf4Serv(TempoProximaChegadaSMedTemp,
							&TempoProximaChegadaSExam1,
							&TempoProximaChegadaSExam2,
							&TempoProximaChegadaSExam3,
							&TempoProximaChegadaSExam4);
			break;
		case 8: EventoChegadaProcServCom1Serv(Clock,		//para chegar 
							&NumUtentesSistema,
							&EstadoSMed2,
							&FilaEventosChegadaSMed2,
							&TempoProximaChegadaSMed2,
							&TempoPartidaSMed2,
							&TempoOcupacaoSMed2,
							&TempoTotalPermanencia,
							&TotalUtentesFilaSMed2);
			break;
		case 9: EventoPartida (Clock,
							&NumUtentesSistema,
							&EstadoSMed2,
							&FilaEventosChegadaSMed2,
							&TempoPartidaSMed2,
							&TempoProximaChegadaSExamTemp,
							&TempoOcupacaoSMed2,
							&TempoTotalEsperaSMed2,
							&TempoTotalPermanencia);

			SelectOneOf4Serv(TempoProximaChegadaSMedTemp,
				&TempoProximaChegadaSExam1,
				&TempoProximaChegadaSExam2,
				&TempoProximaChegadaSExam3,
				&TempoProximaChegadaSExam4);
			break;
		case 10: EventoChegadaProcServCom1Serv(Clock,		//para chegar 
							&NumUtentesSistema,
							&EstadoSMed3,
							&FilaEventosChegadaSMed3,
							&TempoProximaChegadaSMed3,
							&TempoPartidaSMed3,
							&TempoOcupacaoSMed3,
							&TempoTotalPermanencia,
							&TotalUtentesFilaSMed3);

			SelectOneOf4Serv(TempoProximaChegadaSMedTemp,
				&TempoProximaChegadaSExam1,
				&TempoProximaChegadaSExam2,
				&TempoProximaChegadaSExam3,
				&TempoProximaChegadaSExam4);
			break;
		case 11: EventoPartida (Clock,
							&NumUtentesSistema,
							&EstadoSMed3,
							&FilaEventosChegadaSMed3,
							&TempoPartidaSMed3,
							&TempoProximaChegadaSExamTemp,
							&TempoOcupacaoSMed3,
							&TempoTotalEsperaSMed3,
							&TempoTotalPermanencia);
			break;
		case 12: EventoChegadaProcServCom1Serv(Clock,		//para chegar 
							&NumUtentesSistema,
							&EstadoSMed4,
							&FilaEventosChegadaSMed4,
							&TempoProximaChegadaSMed4,
							&TempoPartidaSMed4,
							&TempoOcupacaoSMed4,
							&TempoTotalPermanencia,
							&TotalUtentesFilaSMed4);

			SelectOneOf4Serv(TempoProximaChegadaSMedTemp,
				&TempoProximaChegadaSExam1,
				&TempoProximaChegadaSExam2,
				&TempoProximaChegadaSExam3,
				&TempoProximaChegadaSExam4);
			break;
		case 13: EventoPartida (Clock,
							&NumUtentesSistema,
							&EstadoSMed4,
							&FilaEventosChegadaSMed4,
							&TempoPartidaSMed4,
							&TempoProximaChegadaSExamTemp,
							&TempoOcupacaoSMed4,
							&TempoTotalEsperaSMed4,
							&TempoTotalPermanencia);
			SelectOneOf4Serv(TempoProximaChegadaSMedTemp,
				&TempoProximaChegadaSExam1,
				&TempoProximaChegadaSExam2,
				&TempoProximaChegadaSExam3,
				&TempoProximaChegadaSExam4);
			break;
		case 14: EventoChegadaProcServCom1Serv(Clock,		//para chegar 
							&NumUtentesSistema,
							&EstadoSExam1,
							&FilaEventosChegadaSExam1,
							&TempoProximaChegadaSExam1,
							&TempoPartidaSExam1,
							&TempoOcupacaoSExam1,
							&TempoTotalPermanencia,
							&TotalUtentesFilaSExam1);
			break;
		case 15: EventoPartida (Clock,
							&NumUtentesSistema,
							&EstadoSExam1,
							&FilaEventosChegadaSExam1,
							&TempoPartidaSExam1,
							&TempoProximaChegadaSMedTemp,
							&TempoOcupacaoSExam1,
							&TempoTotalEsperaSExam1,
							&TempoTotalPermanencia);
			break;
		case 16: EventoChegadaProcServCom1Serv(Clock,		//para chegar 
							&NumUtentesSistema,
							&EstadoSExam2,
							&FilaEventosChegadaSExam2,
							&TempoProximaChegadaSExam2,
							&TempoPartidaSExam2,
							&TempoOcupacaoSExam2,
							&TempoTotalPermanencia,
							&TotalUtentesFilaSExam2);
			break;
		case 17: EventoPartida (Clock,
							&NumUtentesSistema,
							&EstadoSExam2,
							&FilaEventosChegadaSExam2,
							&TempoPartidaSExam2,
							&TempoProximaChegadaSMedTemp,
							&TempoOcupacaoSExam2,
							&TempoTotalEsperaSExam2,
							&TempoTotalPermanencia);
			break;
		case 18: EventoChegadaProcServCom1Serv(Clock,		//para chegar 
							&NumUtentesSistema,
							&EstadoSExam3,
							&FilaEventosChegadaSExam3,
							&TempoProximaChegadaSExam3,
							&TempoPartidaSExam3,
							&TempoOcupacaoSExam3,
							&TempoTotalPermanencia,
							&TotalUtentesFilaSExam3);
			break;
		case 19: EventoPartida (Clock,
							&NumUtentesSistema,
							&EstadoSExam3,
							&FilaEventosChegadaSExam3,
							&TempoPartidaSExam3,
							&TempoProximaChegadaSMedTemp,
							&TempoOcupacaoSExam3,
							&TempoTotalEsperaSExam3,
							&TempoTotalPermanencia);
			break;
		case 20: EventoChegadaProcServCom1Serv(Clock,		//para chegar 
							&NumUtentesSistema,
							&EstadoSExam4,
							&FilaEventosChegadaSExam4,
							&TempoProximaChegadaSExam4,
							&TempoPartidaSExam4,
							&TempoOcupacaoSExam4,
							&TempoTotalPermanencia,
							&TotalUtentesFilaSExam4);
			break;
		case 21: EventoPartida (Clock,
							&NumUtentesSistema,
							&EstadoSExam4,
							&FilaEventosChegadaSExam4,
							&TempoPartidaSExam4,
							&TempoProximaChegadaSMedTemp,
							&TempoOcupacaoSExam4,
							&TempoTotalEsperaSExam4,
							&TempoTotalPermanencia);
			break;
		default: terminar = 1;
		}

		

		if (terminar == 1)
		{
			flag = 1;
			break;
		}

		printf("\n\nNumUtentes = %d", NumUtentes);
		printf("\n NumUtentesSistema = %d \n", NumUtentesSistema);
	}

	printf("\n\nCONTADORES ESTATISTICOS\n");
	printf("NumUtentesSistema = %d\n", NumUtentesSistema);
	printf("TotalUtentesFila = %d\n", TotalUtentesFilaSAtend);
	printf("TempoTotalSistema = %.3f\n", TempoTotalSistema);
	printf("TempoOcupacaoSAtend1 = %.3f\n", TempoOcupacaoSAtend1);
	printf("TempoOcupacaoSAtend2 = %.3f\n", TempoOcupacaoSAtend2);
	printf("TempoTotalEspera = %.3f\n", TempoTotalEsperaSAtend);
	printf("TempoTotalPermanencia = %.3f\n\n", TempoTotalPermanencia);

	ContadoresEstatisticos(NumUtentesSistema,
		TotalUtentesFilaSAtend,
		TempoOcupacaoSAtend1,
		TempoOcupacaoSAtend2,
		TempoTotalEsperaSAtend,
		TempoTotalPermanencia,
		TempoTotalSistema);

	printf("\n");
	if (EmptyQueue(FilaEventosChegadaSAtend))
		ShowQueue(FilaEventosChegadaSAtend);

	system("PAUSE");


}