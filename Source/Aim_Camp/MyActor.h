// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "MyActor.generated.h"

UCLASS()
class AIM_CAMP_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats_Score")
    float Speed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats_Score")
    float Precision;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats_Score")
    float Accuracy;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats_Score")
    int32 Hits;

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdateSpeed(float DeltaTime);

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdatePrecision(bool Sphereshot);

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdateAccuracy(bool HitTarget);

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdateHits(int32 NewHits);

    UFUNCTION(BlueprintCallable, Category = "Stats_Score")
    void UpdateStats_ScoreBlueprint();

    float PlayerSpeed;

private:
    int32 Sphereshots;
    int32 ShotsFired;

    UUserWidget* Stats_ScoreWidget;
};
