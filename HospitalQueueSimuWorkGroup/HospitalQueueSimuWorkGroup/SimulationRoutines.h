
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
	int *EstadoSAtend1,
	int *EstadoSAtend2,
	int *EstadoSTriag1,
	int *EstadoSTriag2,
	int *EstadoSMed1,
	int *EstadoSMed2,
	int *EstadoSMed3,
	int *EstadoSMed4,
	int *EstadoSExam1,
	int *EstadoSExam2,
	int *EstadoSExam3,
	int *EstadoSExam4,
	float **FilaSAtend,
	float **FilaSTriag,
	float **FilaSMed1,
	float **FilaSMed2,
	float **FilaSMed3,
	float **FilaSMed4,
	float **FilaSExam1,
	float **FilaSExam2,
	float **FilaSExam3,
	float **FilaSExam4,
	float *Clock,
	float *TempoProximaChegada,
	float *TempoPartidaSAtend1,
	float *TempoPartidaSAtend2,	
	float *TempoPartidaSTriag1,
	float *TempoPartidaSTriag2,
	float *TempoPartidaSMed1,
	float *TempoPartidaSMed2,
	float *TempoPartidaSMed3,
	float *TempoPartidaSMed4,	
	float *TempoPartidaSExam1,
	float *TempoPartidaSExam2,
	float *TempoPartidaSExam3,
	float *TempoPartidaSExam4,
	float *TempoTotalSAtend,
	float *TempoTotalSTriag,
	float *TempoTotalSMed,
	float *TempoTotalSExam,
	float *TempoOcupacaoSAtend1,
	float *TempoOcupacaoSAtend2,
	float *TempoOcupacaoSTriag1,
	float *TempoOcupacaoSTriag2,
	float *TempoOcupacaoSMed1,
	float *TempoOcupacaoSMed2,
	float *TempoOcupacaoSMed3,
	float *TempoOcupacaoSMed4,
	float *TempoOcupacaoSExam1,
	float *TempoOcupacaoSExam2,
	float *TempoOcupacaoSExam3,
	float *TempoOcupacaoSExam4,
	float *TempoTotalPermanencia,
	int *TotalClientesFilaSAtend,
	int *TotalClientesFilaSTriag,
	int *TotalClientesFilaSMed,
	int *TotalClientesFilaSExam)
{
	*NumClientesSistema = 0;
	*EstadoSAtend1 = 0;  // livre / available
	*EstadoSAtend2 = 0;  // livre / available 
	*EstadoSTriag1 = 0;  // livre / available
	*EstadoSTriag2 = 0;  // livre / available 
	*EstadoSMed1 = 0;  // livre / available
	*EstadoSMed2 = 0;  // livre / available 
	*EstadoSMed3 = 0;  // livre / available
	*EstadoSMed4 = 0;  // livre / available 

	*FilaSAtend = CreateQueue();
	*FilaSTriag = CreateQueue();
	*FilaSMed1 = CreateQueue();
	*FilaSMed2 = CreateQueue();
	*FilaSMed3 = CreateQueue();
	*FilaSMed4 = CreateQueue();
	*FilaSExam1 = CreateQueue();
	*FilaSExam2 = CreateQueue();
	*FilaSExam3 = CreateQueue();
	*FilaSExam4 = CreateQueue();

	*Clock = 0.0;
	*TempoProximaChegada = Time;
	*TempoPartidaSAtend1 = Infinito;
	*TempoPartidaSAtend2 = Infinito;
	*TempoPartidaSTriag1 = Infinito;
	*TempoPartidaSTriag2 = Infinito;
	*TempoPartidaSMed1 = Infinito;
	*TempoPartidaSMed2 = Infinito;
	*TempoPartidaSMed3 = Infinito;
	*TempoPartidaSMed4 = Infinito;
	*TempoPartidaSExam1 = Infinito;
	*TempoPartidaSExam2 = Infinito;
	*TempoPartidaSExam3 = Infinito;
	*TempoPartidaSExam4 = Infinito;
	*TempoTotalSAtend = 0.0;
	*TempoTotalSTriag = 0.0;
	*TempoTotalSMed = 0.0;
	*TempoTotalSExam = 0.0;
	*TempoOcupacaoSAtend1 = 0.0;
	*TempoOcupacaoSAtend2 = 0.0;
	*TempoOcupacaoSTriag1 = 0.0;
	*TempoOcupacaoSTriag2 = 0.0;
	*TempoOcupacaoSMed1 = 0.0;
	*TempoOcupacaoSMed2 = 0.0;
	*TempoOcupacaoSMed3 = 0.0;
	*TempoOcupacaoSMed4 = 0.0;
	*TempoOcupacaoSExam1 = 0.0;
	*TempoOcupacaoSExam2 = 0.0;
	*TempoOcupacaoSExam3 = 0.0;
	*TempoOcupacaoSExam4 = 0.0;
	*TempoTotalPermanencia = 0.0;
	*TotalClientesFilaSAtend = 0;
	*TotalClientesFilaSTriag = 0;
	*TotalClientesFilaSMed = 0;
	*TotalClientesFilaSExam = 0;
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

void EventoChegadaSAtend(float Tempo,
						int *NumClientesSistema,
						int *EstadoSAtend1,
						int *EstadoSAtend2,
						float **FilaSAtend,
						float *TempoProximaChegada,
						float *TempoPartidaSAtend1,
						float *TempoPartidaSAtend2,
						float *TempoOcupacaoSAtend1,
						float *TempoOcupacaoSAtend2,
						float *TempoTotalPermanencia,
						int *TotalClientesFilaSAtend)

{
	float	TempoEntreChegadas,
		TempoServico;

	TempoEntreChegadas = DeterminarTempoEntreChegadas(2.0);
	*TempoProximaChegada = Tempo + TempoEntreChegadas;


	if (*EstadoSAtend1 == 1)
		if (*EstadoSAtend2 == 1)
		{
			*FilaSAtend = InsertQueue(Tempo, *FilaSAtend);
			*TotalClientesFilaSAtend = *TotalClientesFilaSAtend + 1;
		}
		else
		{
			*NumClientesSistema = *NumClientesSistema + 1;
			*EstadoSAtend2 = 1;
			TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
			*TempoPartidaSAtend2 = Tempo + TempoServico;
			*TempoOcupacaoSAtend2 = *TempoOcupacaoSAtend2 + TempoServico;
			*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
		}
	else
	{
		*NumClientesSistema = *NumClientesSistema + 1;
		*EstadoSAtend1 = 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSAtend1 = Tempo + TempoServico;
		*TempoOcupacaoSAtend1 = *TempoOcupacaoSAtend1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
	}

}

void EventoPartidaSAtend1(float Tempo, 
						int *NumClientesSistema, 
						int *EstadoSAtend1,
						float **FilaSAtend, 
						float *TempoPartidaSAtend1,
						float *TempoOcupacaoSAtend1, 
						float *TempoTotalSAtend, 
						float *TempoTotalPermanencia)
{
	float TempoChegadaCliente, TempoEsperaCliente, TempoServico;

	if (EmptyQueue(*FilaSAtend))
	{
		*EstadoSAtend1 = 0;
		*TempoPartidaSAtend1 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaSAtend);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSAtend1 = Tempo + TempoServico;
		*FilaSAtend = RemoveQueue(*FilaSAtend);
		*TempoTotalSAtend = *TempoTotalSAtend + TempoEsperaCliente;
		*TempoOcupacaoSAtend1 = *TempoOcupacaoSAtend1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}

void EventoPartidaSAtend2(float Tempo, 
						int *NumClientesSistema, 
						int *EstadoSAtend2,
						float **FilaSAtend,
						float *TempoPartidaSAtend2,
						float *TempoOcupacaoSAtend2, 
						float *TempoTotalSAtend, 
						float *TempoTotalPermanencia)
{
	float TempoChegadaCliente, TempoEsperaCliente, TempoServico;

	if (EmptyQueue(*FilaSAtend))
	{
		*EstadoSAtend2 = 0;
		*TempoPartidaSAtend2 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaSAtend);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSAtend2 = Tempo + TempoServico;
		*FilaSAtend = RemoveQueue(*FilaSAtend);
		*TempoTotalSAtend = *TempoTotalSAtend + TempoEsperaCliente;
		*TempoOcupacaoSAtend2 = *TempoOcupacaoSAtend2 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}

void EventoPartidaSTriag1(float Tempo, 
						int *NumClientesSistema, 
						int *EstadoSTriag1,
						float **FilaSTriag,
						float *TempoPartidaSTriag1,
						float *TempoOcupacaoSTriag1, 
						float *TempoTotalSTriag, 
						float *TempoTotalPermanencia)
{
	float TempoChegadaCliente, TempoEsperaCliente, TempoServico;

	if (EmptyQueue(*FilaSTriag))
	{
		*EstadoSTriag1 = 0;
		*TempoPartidaSTriag1 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaSTriag);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSTriag1 = Tempo + TempoServico;
		*FilaSTriag = RemoveQueue(*FilaSTriag);
		*TempoTotalSTriag = *TempoTotalSTriag + TempoEsperaCliente;
		*TempoOcupacaoSTriag1 = *TempoOcupacaoSTriag1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}


void EventoPartidaSTriag2(float Tempo, 
						int *NumClientesSistema, 
						int *EstadoSTriag2,
						float **FilaSTriag,
						float *TempoPartidaSTriag2,
						float *TempoOcupacaoSTriag2, 
						float *TempoTotalSTriag, 
						float *TempoTotalPermanencia)
{
	float TempoChegadaCliente, TempoEsperaCliente, TempoServico;

	if (EmptyQueue(*FilaSTriag))
	{
		*EstadoSTriag2 = 0;
		*TempoPartidaSTriag2 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaSTriag);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSTriag2 = Tempo + TempoServico;
		*FilaSTriag = RemoveQueue(*FilaSTriag);
		*TempoTotalSTriag = *TempoTotalSTriag + TempoServico;
		*TempoOcupacaoSTriag2 = *TempoOcupacaoSTriag2 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}


void EventoPartidaSMed1(float Tempo, 
	int *NumClientesSistema, 
	int *EstadoSMed1,
	float **FilaSMed1,
	float *TempoPartidaSMed1,
	float *TempoOcupacaoSMed1, 
	float *TempoTotalSMed, 
	float *TempoTotalPermanencia)
{
	float TempoChegadaCliente, TempoEsperaCliente, TempoServico;

	if (EmptyQueue(*FilaSMed1))
	{
		*EstadoSMed1 = 0;
		*TempoPartidaSMed1 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaSMed1);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSMed1 = Tempo + TempoServico;
		*FilaSMed1 = RemoveQueue(*FilaSMed1);
		*TempoTotalSMed = *TempoTotalSMed + TempoEsperaCliente;
		*TempoOcupacaoSMed1 = *TempoOcupacaoSMed1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}


void EventoPartidaSMed2(float Tempo, 
	int *NumClientesSistema, 
	int *EstadoSMed2,
	float **FilaSMed2,
	float *TempoPartidaSMed2,
	float *TempoOcupacaoSMed2, 
	float *TempoTotalSMed, 
	float *TempoTotalPermanencia)
{
	float TempoChegadaCliente, TempoEsperaCliente, TempoServico;

	if (EmptyQueue(*FilaSMed2))
	{
		*EstadoSMed2 = 0;
		*TempoPartidaSMed2 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaSMed2);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSMed2 = Tempo + TempoServico;
		*FilaSMed2 = RemoveQueue(*FilaSMed2);
		*TempoTotalSMed = *TempoTotalSMed + TempoEsperaCliente;
		*TempoOcupacaoSMed2 = *TempoOcupacaoSMed2 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}


void EventoPartidaSMed3(float Tempo, 
						int *NumClientesSistema, 
						int *EstadoSMed3,
						float **FilaSMed3,
						float *TempoPartidaSMed3,
						float *TempoOcupacaoSMed3, 
						float *TempoTotalSMed, 
						float *TempoTotalPermanencia)
{
	float TempoChegadaCliente, TempoEsperaCliente, TempoServico;

	if (EmptyQueue(*FilaSMed3))
	{
		*EstadoSMed3 = 0;
		*TempoPartidaSMed3 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaSMed3);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSMed3 = Tempo + TempoServico;
		*FilaSMed3 = RemoveQueue(*FilaSMed3);
		*TempoTotalSMed = *TempoTotalSMed + TempoEsperaCliente;
		*TempoOcupacaoSMed3 = *TempoOcupacaoSMed3 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}


void EventoPartidaSMed4(float Tempo, 
						int *NumClientesSistema, 
						int *EstadoSMed4,
						float **FilaSMed4,
						float *TempoPartidaSMed4,
						float *TempoOcupacaoSMed4, 
						float *TempoTotalSMed, 
						float *TempoTotalPermanencia)
{
	float TempoChegadaCliente, TempoEsperaCliente, TempoServico;

	if (EmptyQueue(*FilaSMed4))
	{
		*EstadoSMed4 = 0;
		*TempoPartidaSMed4 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaSMed4);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSMed4 = Tempo + TempoServico;
		*FilaSMed4 = RemoveQueue(*FilaSMed4);
		*TempoTotalSMed = *TempoTotalSMed + TempoEsperaCliente;
		*TempoOcupacaoSMed4 = *TempoOcupacaoSMed4 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}



void EventoPartidaSExam1(float Tempo, 
						int *NumClientesSistema, 
						int *EstadoSExam1,
						float **FilaSExam1,
						float *TempoPartidaSExam1,
						float *TempoOcupacaoSExam1, 
						float *TempoTotalSExam, 
						float *TempoTotalPermanencia)
{
	float TempoChegadaCliente, TempoEsperaCliente, TempoServico;

	if (EmptyQueue(*FilaSExam1))
	{
		*EstadoSExam1 = 0;
		*TempoPartidaSExam1 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaSExam1);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSExam1 = Tempo + TempoServico;
		*FilaSExam1 = RemoveQueue(*FilaSExam1);
		*TempoTotalSExam = *TempoTotalSExam + TempoEsperaCliente;
		*TempoOcupacaoSExam1 = *TempoOcupacaoSExam1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}


void EventoPartidaSExam2(float Tempo, 
						int *NumClientesSistema, 
						int *EstadoSExam2,
						float **FilaSExam2,
						float *TempoPartidaSExam2,
						float *TempoOcupacaoSExam2, 
						float *TempoTotalSExam, 
						float *TempoTotalPermanencia)
{
	float TempoChegadaCliente, TempoEsperaCliente, TempoServico;

	if (EmptyQueue(*FilaSExam2))
	{
		*EstadoSExam2 = 0;
		*TempoPartidaSExam2 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaSExam2);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSExam2 = Tempo + TempoServico;
		*FilaSExam2 = RemoveQueue(*FilaSExam2);
		*TempoTotalSExam = *TempoTotalSExam + TempoEsperaCliente;
		*TempoOcupacaoSExam2 = *TempoOcupacaoSExam2 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}


void EventoPartidaSExam3(float Tempo, 
						int *NumClientesSistema, 
						int *EstadoSExam3,
						float **FilaSExam3,
						float *TempoPartidaSExam3,
						float *TempoOcupacaoSExam3, 
						float *TempoTotalSExam, 
						float *TempoTotalPermanencia)
{
	float TempoChegadaCliente, TempoEsperaCliente, TempoServico;

	if (EmptyQueue(*FilaSExam3))
	{
		*EstadoSExam3 = 0;
		*TempoPartidaSExam3 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaSExam3);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSExam3 = Tempo + TempoServico;
		*FilaSExam3 = RemoveQueue(*FilaSExam3);
		*TempoTotalSExam = *TempoTotalSExam + TempoEsperaCliente;
		*TempoOcupacaoSExam3 = *TempoOcupacaoSExam3 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}

void EventoPartidaSExam4(float Tempo, 
						int *NumClientesSistema, 
						int *EstadoSExam4,
						float **FilaSExam4,
						float *TempoPartidaSExam4,
						float *TempoOcupacaoSExam4, 
						float *TempoTotalSExam, 
						float *TempoTotalPermanencia)
{
	float TempoChegadaCliente, TempoEsperaCliente, TempoServico;

	if (EmptyQueue(*FilaSExam4))
	{
		*EstadoSExam4 = 0;
		*TempoPartidaSExam4 = Infinito;
	}
	else
	{
		TempoChegadaCliente = Front(*FilaSExam4);
		TempoEsperaCliente = Tempo - TempoChegadaCliente;
		*NumClientesSistema = *NumClientesSistema + 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSExam4 = Tempo + TempoServico;
		*FilaSExam4 = RemoveQueue(*FilaSExam4);
		*TempoTotalSExam = *TempoTotalSExam + TempoEsperaCliente;
		*TempoOcupacaoSExam4 = *TempoOcupacaoSExam4 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
	}
}

void EventoChegadaSTriag(float Tempo,
						int *NumClientesSistema,
						int *EstadoSTriag1,
						int *EstadoSTriag2,
						float **FilaSTriag,
						float *TempoProximaChegada,
						float *TempoPartidaSTriag1,
						float *TempoPartidaSTriag2,
						float *TempoOcupacaoSTriag1,
						float *TempoOcupacaoSTriag2,
						float *TempoTotalPermanencia,
						int *TotalClientesFilaSTriag)
{
	float	TempoEntreChegadas,
			TempoServico;

	TempoEntreChegadas = DeterminarTempoEntreChegadas(2.0);
	*TempoProximaChegada = Tempo + TempoEntreChegadas;

	if (*EstadoSTriag1 == 1)
		if (*EstadoSTriag2 == 1)
		{
			*FilaSTriag = InsertQueue(Tempo, *FilaSTriag);
			*TotalClientesFilaSTriag = *TotalClientesFilaSTriag + 1;
		}
		else
		{
			*NumClientesSistema = *NumClientesSistema + 1;
			*EstadoSTriag2 = 1;
			TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
			*TempoPartidaSTriag2 = Tempo + TempoServico;
			*TempoOcupacaoSTriag2 = *TempoOcupacaoSTriag2 + TempoServico;
			*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
		}
	else
	{
		*NumClientesSistema = *NumClientesSistema + 1;
		*EstadoSTriag1 = 1;
		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
		*TempoPartidaSTriag1 = Tempo + TempoServico;
		*TempoOcupacaoSTriag1 = *TempoOcupacaoSTriag1 + TempoServico;
		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
	}

}




//void EventoChegada(float Tempo,
//	int *NumClientesSistema,
//	int *EstadoAgente1,
//	int *EstadoAgente2,
//	float **FilaEventosChegada,
//	float *TempoProximaChegada,
//	float *TempoPartida1,
//	float *TempoPartida2,
//	float *TempoOcupacaoAgente1,
//	float *TempoOcupacaoAgente2,
//	float *TempoTotalPermanencia,
//	int *TotalClientesFila)
//{
//	float	TempoEntreChegadas,
//		TempoServico;
//
//	TempoEntreChegadas = DeterminarTempoEntreChegadas(2.0);
//	*TempoProximaChegada = Tempo + TempoEntreChegadas;
//
//	if (*EstadoAgente1 == 1)
//		if (*EstadoAgente2 == 1)
//		{
//			*FilaEventosChegada = InsertQueue(Tempo, *FilaEventosChegada);
//			*TotalClientesFila = *TotalClientesFila + 1;
//		}
//		else
//		{
//			*NumClientesSistema = *NumClientesSistema + 1;
//			*EstadoAgente2 = 1;
//			TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
//			*TempoPartida2 = Tempo + TempoServico;
//			*TempoOcupacaoAgente2 = *TempoOcupacaoAgente2 + TempoServico;
//			*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
//		}
//	else
//	{
//		*NumClientesSistema = *NumClientesSistema + 1;
//		*EstadoAgente1 = 1;
//		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
//		*TempoPartida1 = Tempo + TempoServico;
//		*TempoOcupacaoAgente1 = *TempoOcupacaoAgente1 + TempoServico;
//		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico;
//	}
//
//}

//void EventoPartida1(float Tempo,
//	int *NumClientesSistema,
//	int *EstadoAgente1,
//	float **FilaEventosChegada,
//	float *TempoPartida1,
//	float *TempoOcupacaoAgente1,
//	float *TempoTotalEspera,
//	float *TempoTotalPermanencia)
//{
//	float	TempoChegadaCliente,
//		TempoEsperaCliente,
//		TempoServico;
//
//	if (EmptyQueue(*FilaEventosChegada))
//	{
//		*EstadoAgente1 = 0;
//		*TempoPartida1 = Infinito;
//	}
//	else
//	{
//		TempoChegadaCliente = Front(*FilaEventosChegada);
//		TempoEsperaCliente = Tempo - TempoChegadaCliente;
//		*NumClientesSistema = *NumClientesSistema + 1;
//		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
//		*TempoPartida1 = Tempo + TempoServico;
//		*FilaEventosChegada = RemoveQueue(*FilaEventosChegada);
//		*TempoTotalEspera = *TempoTotalEspera + TempoEsperaCliente;
//		*TempoOcupacaoAgente1 = *TempoOcupacaoAgente1 + TempoServico;
//		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
//	}
//}


//void EventoPartida2(float Tempo,
//	int *NumClientesSistema,
//	int *EstadoAgente2,
//	float **FilaEventosChegada,
//	float *TempoPartida2,
//	float *TempoOcupacaoAgente2,
//	float *TempoTotalEspera,
//	float *TempoTotalPermanencia)
//{
//	float	TempoChegadaCliente,
//		TempoEsperaCliente,
//		TempoServico;
//
//	if (EmptyQueue(*FilaEventosChegada))
//	{
//		*EstadoAgente2 = 0;
//		*TempoPartida2 = Infinito;
//	}
//	else
//	{
//		TempoChegadaCliente = Front(*FilaEventosChegada);
//		TempoEsperaCliente = Tempo - TempoChegadaCliente;
//		*NumClientesSistema = *NumClientesSistema + 1;
//		TempoServico = DeterminarTempoServico(0.5, 2.0, 1);
//		*TempoPartida2 = Tempo + TempoServico;
//		*FilaEventosChegada = RemoveQueue(*FilaEventosChegada);
//		*TempoTotalEspera = *TempoTotalEspera + TempoEsperaCliente;
//		*TempoOcupacaoAgente2 = *TempoOcupacaoAgente2 + TempoServico;
//		*TempoTotalPermanencia = *TempoTotalPermanencia + TempoServico + TempoEsperaCliente;
//	}
//}


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