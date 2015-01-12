#include <crtlib/include/crtlib.h>

u32 log2_u32(u32 val)
{
	int res = 0;
	while (val > 0) {
		res++;
		val >>= 1;
	}
	return res;
}
EXPORT_SYMBOL(log2_u32);

u32 rand_u32_up(u32 up)
{
	u32 v, log;
	
	if (up == 0)
		return 0;

	if ((up & (up -1)) == 0)
		return (u32)(rand_u64() & (up - 1));

	log = log2_u32(up);
	while ((v = ((u32)rand_u64() & (( 1 << log) - 1))) >= up);
	return v;
}
EXPORT_SYMBOL(rand_u32_up);

u32 rand_u32_min_max(u32 min, u32 max)
{
	if (min > max)
		return (u32)-1;
	else if (min == max)
		return min;
	else
		return min + rand_u32_up(max - min + 1);
}
EXPORT_SYMBOL(rand_u32_min_max);

u32 rand_u32(void)
{
	u32 cand;
	if (crt_random_buf(&cand, sizeof(cand)))
		return -1;
	return cand;
}
EXPORT_SYMBOL(rand_u32);

u64 rand_u64(void)
{
	u64 cand;
	if (crt_random_buf(&cand, sizeof(cand)))
		return -1;
	return cand;
}
EXPORT_SYMBOL(rand_u64);
