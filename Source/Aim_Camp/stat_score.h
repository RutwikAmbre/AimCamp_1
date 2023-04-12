// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "stat_score.generated.h"

UCLASS()
class AIM_CAMP_API Astat_Score : public AActor
{
GENERATED_BODY()

public:
Astat_Score();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats_Score")
    float Precision;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats_Score")
    int32 Hits;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats_Score")
    int32 Miss;

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdatePrecision(bool Hit);

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdateHits(int32 CurrentScore);

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdateMiss(int32 CurrentScore, int32 MaxScore);

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdateStats_ScoreBlueprint();

protected:
virtual void BeginPlay() override;

public:
virtual void Tick(float DeltaTime) override;

private:
int32 CurrentScore;
int32 MaxScore;
};
