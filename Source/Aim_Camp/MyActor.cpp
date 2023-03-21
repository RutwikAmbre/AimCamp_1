// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    // Find the blueprint class and store a reference to it
    static ConstructorHelpers::FClassFinder<AAIM_CampCharacter> BlueprintClass(TEXT("/Game/FirstPersonBP/Blueprints"));
    if (BlueprintClass.Succeeded())
    {
        BlueprintActorClass = BlueprintClass.Class;
    }
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

float AMyActor::CalculateSpeed()
{
    float TotalTime = /* calculate total time */;
    float TotalDistance = /* calculate total distance */;
    float Speed = TotalDistance / TotalTime;
    return Speed;
}

float AMyActor::CalculateAccuracy()
{
    int32 TotalShots = /* calculate total number of shots fired */;
    int32 TotalHits = /* calculate total number of hits */;
    if (TotalShots == 0)
    {
        return 0.0f;
    }
    float Accuracy = static_cast<float>(TotalHits) / static_cast<float>(TotalShots);
    return Accuracy;
}

float AMyActor::CalculatePrecision()
{
    float TotalDistanceFromTargets = /* calculate total distance from targets */;
    int32 TotalHits = /* calculate total number of hits */;
    if (TotalHits == 0)
    {
        return 0.0f;
    }
    float Precision = TotalDistanceFromTargets / static_cast<float>(TotalHits);
    return Precision;
}

int32 AMyActor::CalculateHits()
{
    int32 TotalHits = /* calculate total number of hits */;
    return TotalHits;
}
