
float DeterminarTempoEntreChegadas(float niu)
{
	float r, X;

	r = rand() / (float)RAND_MAX;
	X = -niu * log(1 - r);
	printf("r1 = %f  -- X1 = %f \n", r, X);
	return X;
}


float DeterminarTempoServico(float A, float B, float T0)
{
	float r, X;

	r = rand() / (float)RAND_MAX;
	X = T0 + A + (B - A) * r;
	printf("r2 = %f  -- X2 = %f \n", r, X);
	return X;
}


void Inicializacao(float Time,
	int *NumClientesSistema,
	int *EstadoAgente1,
	int *EstadoAgente2,
	float **FilaEventosChegada,
	float *Clock,
	float *TempoProximaChegada,
	float *TempoPartida1,
	float *TempoPartida2,
	float *TempoTotalEspera,
	float *TempoOcupacaoAgente1,
	float *TempoOcupacaoAgente2,
	float *TempoTotalPermanencia,
	int *TotalClientesFila)
{
	*NumClientesSistema = 0;
	*EstadoAgente1 = 0;  // livre / available
	*EstadoAgente2 = 0;  // livre / available 
	*FilaEventosChegada = CreateQueue();
	*Clock = 0.0;
	*TempoProximaChegada = Time;
	*TempoPartida1 = Infinito;
	*TempoPartida2 = Infinito;
	*TempoTotalEspera = 0.0;
	*TempoOcupacaoAgente1 = 0.0;
	*TempoOcupacaoAgente2 = 0.0;
	*TempoTotalPermanencia = 0.0;
	*TotalClientesFila = 0;
}

void GestaoTempo(float TempoProximaChegada,
	float TempoPartidaSAtend1,
	float TempoPartidaSAtend2,
	float TempoPartidaSTriag1,
	float TempoPartidaSTriag2,
	float TempoPartidaSMed1,
	float TempoPartidaSMed2,
	float TempoPartidaSMed3,
	float TempoPartidaSMed4,
	float TempoPartidaSExam1,
	float TempoPartidaSExam2,
	float TempoPartidaSExam3,
	float TempoPartidaSExam4,
	float *Tempo,
	int *TipoEvento)
{
	*Tempo = TempoProximaChegada;
	*TipoEvento = 0;  // Chegada ao Hospital
	if (TempoPartidaSAtend1 < *Tempo)
	{
		*Tempo = TempoPartidaSAtend1;
		*TipoEvento = 1;  // Chegada ao servico de atendimento 1
	}
	if (TempoPartidaSAtend2 < *Tempo)
	{
		*Tempo = TempoPartidaSAtend2;
		*TipoEvento = 2;  // Chegada ao servico de atendimento 2
	}
	if (TempoPartidaSTriag1 < *Tempo)
	{
		*Tempo = TempoPartidaSTriag1;
		*TipoEvento = 3;  // Chegada a Triagem 1
	}
	if (TempoPartidaSTriag2 < *Tempo)
	{
		*Tempo = TempoPartidaSTriag2;
		*TipoEvento = 4;  // Chegada a Triagem 2
	}
	if (TempoPartidaSMed1 < *Tempo)
	{
		*Tempo = TempoPartidaSMed1;
		*TipoEvento = 5;  // Chegada ao servicoMedico1
	}
	if (TempoPartidaSMed2 < *Tempo)
	{
		*Tempo = TempoPartidaSMed2;
		*TipoEvento = 6;  // Chegada ao servicoMedico2
	}
	if (TempoPartidaSMed3 < *Tempo)
	{
		*Tempo = TempoPartidaSMed3;
		*TipoEvento = 7;  // Chegada ao servicoMedico3
	}
	if (TempoPartidaSMed4 < *Tempo)
	{
		*Tempo = TempoPartidaSMed4;
		*TipoEvento = 8;  // Chegada ao servicoMedico3
	}
	if (TempoPartidaSExam1 < *Tempo)
	{
		*Tempo = TempoPartidaSExam1;
		*TipoEvento = 9;  // Chegada ao Exame1
	}
	if (TempoPartidaSExam2 < *Tempo)
	{
		*Tempo = TempoPartidaSExam2;
		*TipoEvento = 10;  // Chegada ao Exame2
	}
	if (TempoPartidaSExam3 < *Tempo)
	{
		*Tempo = TempoPartidaSExam3;
		*TipoEvento = 11;  // Chegada ao Exame3
	}
	if (TempoPartidaSExam4 < *Tempo)
	{
		*Tempo = TempoPartidaSExam4;
		*TipoEvento = 12;  // Chegada ao Exame4
	}
	if (*Tempo == Infinito)
		*TipoEvento = -1;
}

/*
void GestaoTempo(float TempoProximaChegada, float TempoPartida1, float TempoPartida2, float *Tempo, int *TipoEvento)
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
	if (*Tempo == Infinito)
		*TipoEvento = -1;
}
*/


void EventoChegada(float Tempo,
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

void EventoPartida1(float Tempo,
	int *NumClientesSistema,
	int *EstadoAgente1,
	float **FilaEventosChegada,
	float *TempoPartida1,
	float *TempoOcupacaoAgente1,
	float *TempoTotalEspera,
	float *TempoTotalPermanencia)
{
	float	TempoChegadaCliente,
		TempoEsperaCliente,
		TempoServico;

	if (EmptyQueue(*FilaEventosChegada))
	{
		*EstadoAgente1 = 0;
		*TempoPartida1 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaEventosChegada);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartida1 = Tempo + TempoServico;
		*FilaEventosChegada = RemoveQueue(*FilaEventosChegada);
		*TempoTotalEspera = *TempoTotalEspera + TempoEsperaCliente;
		*TempoOcupacaoAgente1 = *TempoOcupacaoAgente1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}


void EventoPartida2(float Tempo,
	int *NumClientesSistema,
	int *EstadoAgente2,
	float **FilaEventosChegada,
	float *TempoPartida2,
	float *TempoOcupacaoAgente2,
	float *TempoTotalEspera,
	float *TempoTotalPermanencia)
{
	float	TempoChegadaCliente,
		TempoEsperaCliente,
		TempoServico;

	if (EmptyQueue(*FilaEventosChegada))
	{
		*EstadoAgente2 = 0;
		*TempoPartida2 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaEventosChegada);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartida2 = Tempo + TempoServico;
		*FilaEventosChegada = RemoveQueue(*FilaEventosChegada);
		*TempoTotalEspera = *TempoTotalEspera + TempoEsperaCliente;
		*TempoOcupacaoAgente2 = *TempoOcupacaoAgente2 + TempoServico;
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