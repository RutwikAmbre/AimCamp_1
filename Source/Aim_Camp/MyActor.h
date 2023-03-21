// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class AIM_CAMP_API AMyActor : public AActor
{
    GENERATED_BODY()
    
public:
    // Sets default values for this actor's properties
    AMyActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Declare a UPROPERTY for a float property called "Speed"
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
    float Speed;

    // Declare a UPROPERTY for a float property called "Precision"
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
    float Precision;

    // Declare a UPROPERTY for a float property called "Accuracy"
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
    float Accuracy;

    // Declare a UPROPERTY for an integer property called "Hits"
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
    int32 Hits;
    
    // Declare the functions used to calculate the score values
    float CalculateSpeed();
    float CalculateAccuracy();
    float CalculatePrecision();
    int32 CalculateHits();

    // Declare the lerp speed variables used to smooth the score updates
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
    float SpeedLerpSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
    float AccuracyLerpSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
    float PrecisionLerpSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
    float HitsLerpSpeed;

    // Function to update the score values
    UFUNCTION(BlueprintCallable, Category = "Score")
    void UpdateScore(float DeltaTime);
    
    
};
