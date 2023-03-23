// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

#include "Kismet/KismetMathLibrary.h" // Required for FMath::Lerp function

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Set default values for score properties
    Speed = 0.0f;
    Precision = 0.0f;
    Accuracy = 0.0f;
    Hits = 0;

    // Set default values for lerp speed properties
    SpeedLerpSpeed = 0.5f;
    PrecisionLerpSpeed = 0.5f;
    AccuracyLerpSpeed = 0.5f;
    HitsLerpSpeed = 0.5f;
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

    // Update the score values
    UpdateScore(DeltaTime);
}

float AMyActor::CalculateSpeed()
{
    // Calculate the total time and total distance traveled here
    float TotalTime = 0.0f;
    float TotalDistance = 0.0f;

    // Replace these values with your actual calculation
    TotalTime = 10.0f;
    TotalDistance = 100.0f;

    float Speed = TotalDistance / TotalTime;
    return Speed;
}

float AMyActor::CalculateAccuracy()
{
    // Calculate the total number of shots fired and total number of hits here
    int32 TotalShots = 0;
    int32 TotalHits = 0;

    // Replace these values with your actual calculation
    TotalShots = 100;
    TotalHits = 80;

    if (TotalShots == 0)
    {
        return 0.0f;
    }

    float Accuracy = static_cast<float>(TotalHits) / static_cast<float>(TotalShots);
    return Accuracy;
}

float AMyActor::CalculatePrecision()
{
    // Calculate the total distance from targets and total number of hits here
    float TotalDistanceFromTargets = 0.0f;
    int32 TotalHits = 0;
    
    // Iterate through all targets and calculate distance from each hit target
    for (auto Target : Targets)
    {
        if (Target->bIsHit)
        {
            TotalHits++;
            TotalDistanceFromTargets += FVector::Dist(Target->GetActorLocation(), GetActorLocation());
        }
    }
    
    if (TotalHits == 0)
    {
        return 0.0f;
    }
    
    float Precision = TotalDistanceFromTargets / static_cast<float>(TotalHits);
    return Precision;
}

void AMyActor::UpdateScore(float DeltaTime)
{
// Calculate new score values using lerping
    Speed = FMath::Lerp(Speed, CalculateSpeed(), SpeedLerpSpeed * DeltaTime);
    Precision = FMath::Lerp(Precision, CalculatePrecision(), PrecisionLerpSpeed * DeltaTime);
    Accuracy = FMath::Lerp(Accuracy, CalculateAccuracy(), AccuracyLerpSpeed * DeltaTime);
    Hits = FMath::Lerp(Hits, static_cast<float>(Hits), HitsLerpSpeed * DeltaTime);
}

void AMyActor::UpdateStatsBlueprint()
{
    // Get a reference to the stats blueprint
    UUserWidget* StatsWidget = Cast<UUserWidget>(GetWorld()->GetFirstPlayerController()->GetHUD()->GetWidgetFromName(TEXT("Stats_Score")));

    if (StatsWidget)
    {
        // Update the score values in the stats blueprint
        UTextBlock* SpeedTextBlock = Cast<UTextBlock>(StatsWidget->GetWidgetFromName(TEXT("SpeedTextBlock")));
        if (SpeedTextBlock)
        {
            SpeedTextBlock->SetText(FText::AsNumber(Speed));
        }

        UTextBlock* PrecisionTextBlock = Cast<UTextBlock>(StatsWidget->GetWidgetFromName(TEXT("PrecisionTextBlock")));
        if (PrecisionTextBlock)
        {
            PrecisionTextBlock->SetText(FText::AsNumber(Precision));
        }

        UTextBlock* AccuracyTextBlock = Cast<UTextBlock>(StatsWidget->GetWidgetFromName(TEXT("AccuracyTextBlock")));
        if (AccuracyTextBlock)
        {
            AccuracyTextBlock->SetText(FText::AsNumber(Accuracy));
        }

        UTextBlock* HitsTextBlock = Cast<UTextBlock>(StatsWidget->GetWidgetFromName(TEXT("HitsTextBlock")));
        if (HitsTextBlock)
        {
            HitsTextBlock->SetText(FText::AsNumber(Hits));
        }
    }
}
