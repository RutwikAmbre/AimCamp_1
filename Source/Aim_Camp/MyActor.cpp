// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/HUD.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyActor::AMyActor()
    : PlayerSpeed(100.0f)
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Set default values for score properties
    Speed = 0.0f;
    Precision = 0.0f;
    Accuracy = 0.0f;
    Hits = 0;
    Sphereshots = 0;
    ShotsFired = 0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    // Get a reference to the stats blueprint
    Stats_ScoreWidget = Cast<UUserWidget>(GetWorld()->GetFirstPlayerController()->GetHUD()->GetWidgetFromName(TEXT("Stats_Score")));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMyActor::UpdateSpeed(float DeltaTime)
{
    // Calculate speed score based on player's movement speed and time elapsed
    // Assuming PlayerSpeed is a float variable that needs to be defined somewhere
    Speed = PlayerSpeed * DeltaTime;
}

void AMyActor::UpdatePrecision(bool Sphereshot)
{
    // Calculate precision score based on number of sphereshots divided by number of hits
    if (Sphereshot)
    {
        Sphereshots++;
    }
    Precision = Hits > 0 ? (float)Sphereshots / (float)Hits : 0.0f;
}

void AMyActor::UpdateAccuracy(bool HitTarget)
{
    // Calculate accuracy score based on number of hits divided by number of shots fired
    ShotsFired++;
    if (HitTarget)
    {
        Hits++;
    }
    Accuracy = ShotsFired > 0 ? (float)Hits / (float)ShotsFired : 0.0f;
}

void AMyActor::UpdateHits(int32 NewHits)
{
    // Increment the number of hits
    Hits += NewHits;
}

void AMyActor::UpdateStats_ScoreBlueprint()
{
    if (Stats_ScoreWidget)
    {
        // Update the score values in the stats blueprint
        UTextBlock* SpeedTextBlock = Cast<UTextBlock>(Stats_ScoreWidget->GetWidgetFromName(TEXT("SpeedTextBlock")));
        if (SpeedTextBlock)
        {
            SpeedTextBlock->SetText(FText::AsNumber(Speed));
        }

        UTextBlock* PrecisionTextBlock = Cast<UTextBlock>(Stats_ScoreWidget->GetWidgetFromName(TEXT("PrecisionTextBlock")));
        if (PrecisionTextBlock)
        {
            PrecisionTextBlock->SetText(FText::AsNumber(Precision));
        }

        UTextBlock* AccuracyTextBlock = Cast<UTextBlock>(Stats_ScoreWidget->GetWidgetFromName(TEXT("AccuracyTextBlock")));
        if (AccuracyTextBlock)
        {
            AccuracyTextBlock->SetText(FText::AsNumber(Accuracy));
        }

        UTextBlock* HitsTextBlock = Cast<UTextBlock>(Stats_ScoreWidget->GetWidgetFromName(TEXT("HitsTextBlock")));
        if (HitsTextBlock)
        {
            HitsTextBlock->SetText(FText::AsNumber(Hits));
        }
    }
}
