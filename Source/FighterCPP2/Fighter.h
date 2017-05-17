// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "FighterCPP2/Spawner.h"
#include "Fighter.generated.h"

UCLASS()
class FIGHTERCPP2_API AFighter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFighter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void Die() {
		//TODO: death animation
		SpawnPlayer();
	}

	void SpawnPlayer() {
		mHealth = mMaxHealth;
		//TODO teleport player to spawn
	}

	void FighterTakeDamage(int damage, int *score) {
		mHealth = mHealth - damage;
		if (mHealth <= 0) {
			*score++; //TODO: make scores change based on some stuff
			Die();
		}
	}

	void AbilityCooldown(int abilityCooldownTime, float deltaTime);

public:
	int mHealth, mMaxHealth, mSpeed, mDamage;
	int mScore;
	bool mAbilityIsReady;
	int mAbilityCooldownTime;
	float mTimeCounter;

	UPROPERTY(EditAnywhere)
	ASpawner *mSpawner = nullptr;
	
};
