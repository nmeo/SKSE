#include "PapyrusMisc.h"

#include "GameForms.h"
#include "GameObjects.h"

#include "PapyrusVM.h"
#include "PapyrusNativeFunctions.h"

namespace papyrusSoulGem
{
	UInt32 GetSoulSize(TESSoulGem* thisGem)
	{
		if (!thisGem)
			return 0;
		return thisGem->soulSize;
	}

	UInt32 GetGemSize(TESSoulGem* thisGem)
	{
		if (!thisGem)
			return 0;
		return thisGem->gemSize;
	}

	void RegisterFuncs(VMClassRegistry* registry)
	{
		registry->RegisterFunction(
			new NativeFunction0 <TESSoulGem, UInt32>("GetSoulSize", "SoulGem", papyrusSoulGem::GetGemSize, registry));

		registry->RegisterFunction(
			new NativeFunction0 <TESSoulGem, UInt32> ("GetGemSize", "SoulGem", papyrusSoulGem::GetGemSize, registry));
	}

}



namespace papyrusApparatus
{
	UInt32 GetQuality(BGSApparatus* thisApparatus)
	{
		if (!thisApparatus)
			return 0;
		return thisApparatus->quality.unk04;
	}

	void SetQuality(BGSApparatus* thisApparatus, UInt32 nuQuality)
	{
		if (thisApparatus) {
			thisApparatus->quality.unk04 = nuQuality;
		}
	}
	void RegisterFuncs(VMClassRegistry* registry)
	{
		registry->RegisterFunction(
			new NativeFunction0 <BGSApparatus, UInt32> ("GetQuality", "Apparatus", papyrusApparatus::GetQuality, registry));

		registry->RegisterFunction(
			new NativeFunction1 <BGSApparatus, void, UInt32> ("SetQuality", "Apparatus", papyrusApparatus::SetQuality, registry));
	}	
}

namespace papyrusOutfit
{
	UInt32 GetNumParts(BGSOutfit* thisOutfit)
	{
		return thisOutfit ? thisOutfit->armorOrLeveledItemArray.count : 0;
	}

	TESForm* GetNthPart(BGSOutfit* thisOutfit, UInt32 n)
	{
		TESForm* pForm = NULL;
		if (thisOutfit) {
			thisOutfit->armorOrLeveledItemArray.GetNthItem(n, pForm);
		}	
		return pForm;

	}

	void RegisterFuncs(VMClassRegistry* registry)
	{
		registry->RegisterFunction(
			new NativeFunction0 <BGSOutfit, UInt32> ("GetNumParts", "Outfit", papyrusOutfit::GetNumParts, registry));
		
		registry->RegisterFunction(
			new NativeFunction1 <BGSOutfit, TESForm*, UInt32> ("GetNthPart", "Outfit", papyrusOutfit::GetNthPart, registry));
	}
}

namespace papyrusKeyword
{
	BSFixedString GetString(BGSKeyword* thisKeyword)
	{
		return (thisKeyword) ? thisKeyword->keyword.Get() : NULL;
	}

	void RegisterFuncs(VMClassRegistry* registry)
	{
		registry->RegisterFunction(
			new NativeFunction0 <BGSKeyword, BSFixedString> ("GetString", "Keyword", papyrusKeyword::GetString, registry));
	}
}