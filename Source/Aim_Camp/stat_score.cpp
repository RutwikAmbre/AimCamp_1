// Fill out your copyright notice in the Description page of Project Settings.


#include "stat_score.h"

Astat_Score::Astat_Score()
{
PrimaryActorTick.bCanEverTick = true;
Precision = 0.0f;
Hits = 0;
Miss = 0;
CurrentScore = 0;
MaxScore = 0;
}

void Astat_Score::BeginPlay()
{
Super::BeginPlay();
}

void Astat_Score::Tick(float DeltaTime)
{
Super::Tick(DeltaTime);
}

void Astat_Score::UpdatePrecision(bool Hit)
{
if (Hit)
{
Hits++;
}
Precision = MaxScore > 0 ? (float)Hits / (float)MaxScore : 0.0f;
}

void Astat_Score::UpdateHits(int32 NewCurrentScore)
{
Hits += NewCurrentScore;
}

void Astat_Score::UpdateMiss(int32 NewCurrentScore, int32 NewMaxScore)
{
Miss = NewMaxScore - NewCurrentScore;
}

void Astat_Score::UpdateStats_ScoreBlueprint()
{
    
}




