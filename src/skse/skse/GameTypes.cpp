#include "GameTypes.h"

StringCache * StringCache::GetSingleton(void)
{
	typedef StringCache * (* _GetSingleton)(void);

	return ((_GetSingleton)0x00A385D0)();
}

StringCache::Lock * StringCache::GetLock(UInt32 crc16)
{
	return &locks[crc16 & 0x1F];
}

StringCache::Ref::Ref(const char * buf)
{
	CALL_MEMBER_FN(this, ctor)(buf);
}

const char * BSString::Get(void)
{
	return m_data ? m_data : "";
}
