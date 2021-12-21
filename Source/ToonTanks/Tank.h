#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
		ATank();

public:

private:
	UPROPERTY(VisibleAnywhere, Category = "tank", meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, Category = "tank", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;

};