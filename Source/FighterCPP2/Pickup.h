// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FighterCPP2/Fighter.h"
#include "Pickup.generated.h"


//TODO: figure out unreal enums
//UENUM(BlueprintType)
//enum class EPickupEnum : int
//{
//	HEALTH = 1,
//	SPEED,
//	DAMAGE
//};

UCLASS()
class FIGHTERCPP2_API APickup : public AActor
{
	GENERATED_BODY()



public:	
	// Sets default values for this actor's properties
	APickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	void OnPickup(AFighter &fighter);
	void CoolDown(int endTime, float deltaTime, float timeCounter = 0.0f);
	void APickup::AddModifier();
	void APickup::RemoveModifier();
	void APickup::StartCoolDown();

public:
	UPROPERTY(EditAnywhere)
	int mAttribute;
	UPROPERTY(EditAnywhere)
	int mModifier;
	UPROPERTY(EditAnywhere)
	int mTime;
	UPROPERTY(EditAnywhere)
	int mPickupType;
	UPROPERTY(EditAnywhere)
	bool mHasCoolDown;
	UPROPERTY(EditAnywhere)
	AFighter *mFighter = nullptr;
	bool mIsCoolDown;
	float mTimeCountdown;
};



/*
ShopItem(int price, char* name, char* desc, Attribute EditingAttribute, int modify, int inUse = 0, int aquired = 0, int decayRate = 1)
: mPrice(price), mName(name), mDesc(desc),  mAquired(aquired), mAttribute(EditingAttribute), mModify(modify), mInuse(inUse), mDecay(decayRate)
{}
*/