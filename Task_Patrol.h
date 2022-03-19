
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Task_Patrol.generated.h"
class UBehaviorTreeComponent;
UCLASS()
class MATHANDAI_API UTask_Patrol : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_Patrol(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
