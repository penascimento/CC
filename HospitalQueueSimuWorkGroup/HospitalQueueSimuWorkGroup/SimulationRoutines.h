
float DeterminarTempoEntreChegadas(float niu)
{
	float r, X;

	r = rand() / (float)RAND_MAX;
	X = -niu * log(1 - r);
	//printf("r1 = %f  -- X1 = %f \n", r, X);
	printf("\nTempoEntreChegadas = %f \n", X);
	return X;
}


float DeterminarTempoServico(float A, float B, float T0)
{
	float r, X;

	r = rand() / (float)RAND_MAX;
	X = T0 + A + (B - A) * r;
	//printf("r2 = %f  -- X2 = %f \n", r, X);
	printf("\nTempoServico = %f \n\n", X);
	return X;
}


void Inicializacao(float Time,
	int *NumClientesSistema,
	int *EstadoSAtend1,
	int *EstadoSAtend2,
	float **FilaEventosChegadaSAtend,
	float *Clock,
	float *TempoProximaChegadaSAtend,
	float *TempoPartidaSAtend1,
	float *TempoPartidaSAtend2,
	float *TempoTotalEsperaSAtend,
	float *TempoOcupacaoSAtend1,
	float *TempoOcupacaoSAtend2,
	float *TempoTotalPermanencia,
	int *TotalClientesFilaSAtend,
	int *EstadoSTriag1,
	int *EstadoSTriag2,
	float **FilaEventosChegadaSTriag,
	float *TempoProximaChegadaSTriag,
	float *TempoPartidaSTriag1,
	float *TempoPartidaSTriag2,
	float *TempoTotalEsperaSTriag,
	float *TempoOcupacaoSTriag1,
	float *TempoOcupacaoSTriag2,
	int *TotalClientesFilaSTriag,
	int *EstadoSMed1,
	float **FilaEventosChegadaSMed1,
	float *TempoProximaChegadaSMed1,
	float *TempoPartidaSMed1,
	float *TempoTotalEsperaSMed1,
	float *TempoOcupacaoSMed1,
	int *TotalClientesFilaSMed1,
	int *EstadoSMed2,
	float **FilaEventosChegadaSMed2,
	float *TempoProximaChegadaSMed2,
	float *TempoPartidaSMed2,
	float *TempoTotalEsperaSMed2,
	float *TempoOcupacaoSMed2,
	int *TotalClientesFilaSMed2,
	int *EstadoSMed3,
	float **FilaEventosChegadaSMed3,
	float *TempoProximaChegadaSMed3,
	float *TempoPartidaSMed3,
	float *TempoTotalEsperaSMed3,
	float *TempoOcupacaoSMed3,
	int *TotalClientesFilaSMed3,
	int *EstadoSMed4,
	float **FilaEventosChegadaSMed4,
	float *TempoProximaChegadaSMed4,
	float *TempoPartidaSMed4,
	float *TempoTotalEsperaSMed4,
	float *TempoOcupacaoSMed4,
	int *TotalClientesFilaSMed4 )
{
	*NumClientesSistema = 0;
	*EstadoSAtend1 = 0;  // livre / available
	*EstadoSAtend2 = 0;  // livre / available 
	*FilaEventosChegadaSAtend = CreateQueue();
	*Clock = 0.0;
	*TempoProximaChegadaSAtend = Time;
	*TempoPartidaSAtend1 = Infinito;
	*TempoPartidaSAtend2 = Infinito;
	*TempoTotalEsperaSAtend = 0.0;
	*TempoOcupacaoSAtend1 = 0.0;
	*TempoOcupacaoSAtend2 = 0.0;
	*TempoTotalPermanencia = 0.0;
	*TotalClientesFilaSAtend = 0;
	*EstadoSTriag1 = 0;  // livre / available
	*EstadoSTriag2 = 0;  // livre / available
	*FilaEventosChegadaSTriag = CreateQueue();
	*TempoProximaChegadaSTriag = Infinito;
	*TempoPartidaSTriag1 = Infinito;
	*TempoPartidaSTriag2 = Infinito;
	*TempoTotalEsperaSTriag = 0.0;
	*TempoOcupacaoSTriag1 = 0.0;
	*TempoOcupacaoSTriag2 = 0.0;
	*TotalClientesFilaSTriag = 0;
	*EstadoSMed1 = 0;  // livre / available
	*FilaEventosChegadaSMed1 = CreateQueue();
	*TempoProximaChegadaSMed1 = Infinito;
	*TempoPartidaSMed1 = Infinito;
	*TempoTotalEsperaSMed1 = 0.0;
	*TempoOcupacaoSMed1 = 0.0;
	*TotalClientesFilaSMed1 = 0;
	*EstadoSMed2 = 0;  // livre / available
	*FilaEventosChegadaSMed2 = CreateQueue();
	*TempoProximaChegadaSMed2 = Infinito;
	*TempoPartidaSMed2 = Infinito;
	*TempoTotalEsperaSMed2 = 0.0;
	*TempoOcupacaoSMed2 = 0.0;
	*TotalClientesFilaSMed2 = 0;
	*EstadoSMed3 = 0;  // livre / available
	*FilaEventosChegadaSMed3 = CreateQueue();
	*TempoProximaChegadaSMed3 = Infinito;
	*TempoPartidaSMed3 = Infinito;
	*TempoTotalEsperaSMed3 = 0.0;
	*TempoOcupacaoSMed3 = 0.0;
	*TotalClientesFilaSMed3 = 0;
	*EstadoSMed4 = 0;  // livre / available
	*FilaEventosChegadaSMed4 = CreateQueue();
	*TempoProximaChegadaSMed4 = Infinito;
	*TempoPartidaSMed4 = Infinito;
	*TempoTotalEsperaSMed4 = 0.0;
	*TempoOcupacaoSMed4 = 0.0;
	*TotalClientesFilaSMed4 = 0;
}

	int selectRandomNServices(int n) 
	{	
		return rand() % n;
	}

void SelectMedic(float TempoProximaChegadaSMedTemp, 
		float *TempoProximaChegadaSMed1, 
		float *TempoProximaChegadaSMed2, 
		float *TempoProximaChegadaSMed3, 
		float *TempoProximaChegadaSMed4) 
{
	int nextMed;
	nextMed = selectRandomNServices(4);
	switch (nextMed)
	{
	case 0:
		*TempoProximaChegadaSMed1 = TempoProximaChegadaSMedTemp;
		break;
	case 1:
		*TempoProximaChegadaSMed2 = TempoProximaChegadaSMedTemp;
		break;
	case 2:
		*TempoProximaChegadaSMed3 = TempoProximaChegadaSMedTemp;
		break;
	case 3:
		*TempoProximaChegadaSMed4 = TempoProximaChegadaSMedTemp;
		break;
	}
}

void GestaoTempo(float TempoProximaChegada, 
				float TempoPartida1, 
				float TempoPartida2, 
				float TempoPartida3, 
				float TempoPartida4, 
				float TempoPartida5, 
				//float TempoPartida6,
				//float TempoPartida7,
				//float TempoPartida8,
				//float TempoPartida9,
				//float TempoPartida10,
				//float TempoPartida11,
				//float TempoPartida12,
				float *Tempo, 
				int *TipoEvento)
{
	*Tempo = TempoProximaChegada;
	*TipoEvento = 0;  // Chegada / Arrival
	if (TempoPartida1 < *Tempo)
	{
		*Tempo = TempoPartida1;
		*TipoEvento = 1;  // Partida1 / Departure1
	}
	if (TempoPartida2 < *Tempo)
	{
		*Tempo = TempoPartida2;
		*TipoEvento = 2;  // Partida2 / Departure2
	}
	if (TempoPartida3 < *Tempo)
	{
		*Tempo = TempoPartida3;
		*TipoEvento = 3;  // chegadaTriagem 
	}
	if (TempoPartida4 < *Tempo)
	{
		*Tempo = TempoPartida4;
		*TipoEvento = 4;  // partida triagem1 
	}
	if (TempoPartida5 < *Tempo)
	{
		*Tempo = TempoPartida5;
		*TipoEvento = 5;  // partida triagem2 
	}
	//if (TempoPartida6 < *Tempo)
	//{
	//	*Tempo = TempoPartida6;
	//	*TipoEvento = 6;  // chegada Medico1
	//}
	//if (TempoPartida7 < *Tempo)
	//{
	//	*Tempo = TempoPartida7;
	//	*TipoEvento = 7;  // partida Medico1
	//}
	//if (TempoPartida8 < *Tempo)
	//{
	//	*Tempo = TempoPartida8;
	//	*TipoEvento = 8;  // chegada Medico2
	//}
	//if (TempoPartida9 < *Tempo)
	//{
	//	*Tempo = TempoPartida9;
	//	*TipoEvento = 9;  // partida Medico2
	//}
	//if (TempoPartida10 < *Tempo)
	//{
	//	*Tempo = TempoPartida10;
	//	*TipoEvento = 10;  // chegada Medico3
	//}
	//if (TempoPartida10 < *Tempo)
	//{
	//	*Tempo = TempoPartida10;
	//	*TipoEvento = 10;  // partida Medico3
	//}
	//if (TempoPartida11 < *Tempo)
	//{
	//	*Tempo = TempoPartida11;
	//	*TipoEvento = 11;  // chegada Medico4
	//}
	//if (TempoPartida12 < *Tempo)
	//{
	//	*Tempo = TempoPartida12;
	//	*TipoEvento = 12;  // partida Medico4
	//}
	if (*Tempo == Infinito)
		*TipoEvento = -1;
}


void EventoChegadaSistema(float Tempo,
	int *NumClientesSistema,
	int *EstadoAgente1,
	int *EstadoAgente2,
	float **FilaEventosChegada,
	float *TempoProximaChegada,
	float *TempoPartida1,
	float *TempoPartida2,
	float *TempoOcupacaoAgente1,
	float *TempoOcupacaoAgente2,
	float *TempoTotalPermanencia,
	int *TotalClientesFila)
{
	float	TempoEntreChegadas,
		TempoServico;

	TempoEntreChegadas = DeterminarTempoEntreChegadas(2.0);
	*TempoProximaChegada = Tempo + TempoEntreChegadas;

	if (*EstadoAgente1 == 1)
		if (*EstadoAgente2 == 1)
		{
			*FilaEventosChegada = InsertQueue(Tempo, *FilaEventosChegada);
			*TotalClientesFila = *TotalClientesFila + 1;
		}
		else
		{
			*NumClientesSistema = *NumClientesSistema + 1;
			*EstadoAgente2 = 1;
			TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
			*TempoPartida2 = Tempo + TempoServico;
			*TempoOcupacaoAgente2 = *TempoOcupacaoAgente2 + TempoServico;
			*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
		}
	else
	{
		*NumClientesSistema = *NumClientesSistema + 1;
		*EstadoAgente1 = 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartida1 = Tempo + TempoServico;
		*TempoOcupacaoAgente1 = *TempoOcupacaoAgente1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
	}

}
void EventoChegadaProcServCom2Serv(float Tempo,
	int *NumClientesSistema,
	int *EstadoAgente1,
	int *EstadoAgente2,
	float **FilaEventosChegada,
	float *TempoProximaChegada,
	float *TempoPartida1,
	float *TempoPartida2,
	float *TempoOcupacaoAgente1,
	float *TempoOcupacaoAgente2,
	float *TempoTotalPermanencia,
	int *TotalClientesFila)
{
	float	TempoEntreChegadas,
		TempoServico;

	//TempoEntreChegadas = DeterminarTempoEntreChegadas(2.0);
	//*TempoProximaChegada = Tempo + TempoEntreChegadas;
	*TempoProximaChegada = Infinito;

	if (*EstadoAgente1 == 1)
		if (*EstadoAgente2 == 1)
		{
			*FilaEventosChegada = InsertQueue(Tempo, *FilaEventosChegada);
			*TotalClientesFila = *TotalClientesFila + 1;
		}
		else
		{
			*NumClientesSistema = *NumClientesSistema + 1;
			*EstadoAgente2 = 1;
			TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
			*TempoPartida2 = Tempo + TempoServico;
			*TempoOcupacaoAgente2 = *TempoOcupacaoAgente2 + TempoServico;
			*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
		}
	else
	{
		*NumClientesSistema = *NumClientesSistema + 1;
		*EstadoAgente1 = 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartida1 = Tempo + TempoServico;

		*TempoOcupacaoAgente1 = *TempoOcupacaoAgente1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
	}

}
void EventoChegadaProcServCom1Serv(float Tempo,
	int *NumClientesSistema,
	int *EstadoAgente,
	float **FilaEventosChegada,
	float *TempoProximaChegada,
	float *TempoPartida,
	float *TempoOcupacaoAgente,
	float *TempoTotalPermanencia,
	int *TotalClientesFila)
{
	float	TempoEntreChegadas,
		TempoServico;

	*TempoProximaChegada = Infinito;

	if (*EstadoAgente == 1)
	{
		*FilaEventosChegada = InsertQueue(Tempo, *FilaEventosChegada);
		*TotalClientesFila = *TotalClientesFila + 1;
	}
	else
	{
		*NumClientesSistema = *NumClientesSistema + 1;
		*EstadoAgente = 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartida = Tempo + TempoServico;
		*TempoOcupacaoAgente = *TempoOcupacaoAgente + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
	}
}



void EventoPartida(float Tempo,
	int *NumClientesSistema,
	int *EstadoAgente,
	float **FilaEventosChegada,
	float *TempoPartida,
	float *tempoProServ,
	float *TempoOcupacaoAgente,
	float *TempoTotalEspera,
	float *TempoTotalPermanencia)
{
	float	TempoChegadaCliente,
		TempoEsperaCliente,
		TempoServico;

	if (EmptyQueue(*FilaEventosChegada))
	{
		*EstadoAgente = 0;
		*tempoProServ = *TempoPartida;
		*TempoPartida = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaEventosChegada);
		*FilaEventosChegada = RemoveQueue(*FilaEventosChegada);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*tempoProServ = *TempoPartida;
		*TempoPartida = Tempo + TempoServico;		
		*TempoTotalEspera = *TempoTotalEspera + TempoEsperaCliente;
		*TempoOcupacaoAgente = *TempoOcupacaoAgente + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}

void ContadoresEstatisticos(int NumClientesSistema,
	int TotalClientesFila,
	float TempoOcupacaoAgente1,
	float TempoOcupacaoAgente2,
	float TempoTotalEspera,
	float TempoTotalPermanencia,
	float TempoTotalSistema)
{
	int TaxaOcupacaoAgentes,
		TaxaOcupacaoAgente1,
		TaxaOcupacaoAgente2;
	float	NumMedioClientesFila,
		TempoMedioEsperaClientes,
		TempoMedioPermanenciaClientes;

	TaxaOcupacaoAgentes = (TempoOcupacaoAgente1 + TempoOcupacaoAgente2) / (2 * TempoTotalSistema) * 100;
	TaxaOcupacaoAgente1 = TempoOcupacaoAgente1 / TempoTotalSistema * 100;
	TaxaOcupacaoAgente2 = TempoOcupacaoAgente2 / TempoTotalSistema * 100;
	NumMedioClientesFila = TotalClientesFila / (float)NumClientesSistema;
	TempoMedioEsperaClientes = TempoTotalEspera / NumClientesSistema;
	TempoMedioPermanenciaClientes = TempoTotalPermanencia / NumClientesSistema;

	printf("TaxaOcupacaoAgentes = %d%%\n", TaxaOcupacaoAgentes);
	printf("TaxaOcupacaoAgente1 = %d%%\n", TaxaOcupacaoAgente1);
	printf("TaxaOcupacaoAgente2 = %d%%\n", TaxaOcupacaoAgente2);
	printf("NumMedioClientesFila = %.3f\n", NumMedioClientesFila);
	printf("TempoMedioEsperaClientes = %.3f\n", TempoMedioEsperaClientes);
	printf("TempoMedioPermanaenciaClientes = %.3f\n", TempoMedioPermanenciaClientes);
}