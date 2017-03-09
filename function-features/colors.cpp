#include <boost/assign/list_of.hpp> 
#include <map>

#include <Instruction.h>
#include <Operation.h>
#include <entryIDs.h>

#include "colors.h"

using namespace Dyninst::InstructionAPI;
using namespace graphlets;

namespace {

std::map<entryID,BranchColor::branch_color> branchmap =
boost::assign::map_list_of
(e_jb,BranchColor::JB)
(e_jb_jnaej_j,BranchColor::JB_JNAEJ)
(e_jbe,BranchColor::JBE)
(e_jcxz_jec,BranchColor::JCXZ)
(e_jl,BranchColor::JL)
(e_jle,BranchColor::JLE)
(e_jmp,BranchColor::JMP)
(e_jmpe,BranchColor::JMPE)
(e_jnb,BranchColor::JNB)
(e_jnb_jae_j,BranchColor::JNB_JAE)
(e_jnbe,BranchColor::JNBE)
(e_jnl,BranchColor::JNL)
(e_jnle,BranchColor::JNLE)
(e_jno,BranchColor::JNO)
(e_jnp,BranchColor::JNP)
(e_jns,BranchColor::JNS)
(e_jnz,BranchColor::JNZ)
(e_jo,BranchColor::JO)
(e_jp,BranchColor::JP)
(e_js,BranchColor::JS)
(e_jz,BranchColor::JZ)
(e_loop,BranchColor::LOOP)
(e_loope,BranchColor::LOOPE)
(e_loopn,BranchColor::LOOPN)
;

std::map<entryID,InsnColor::insn_color> colormap = 
boost::assign::map_list_of
(e_jb,InsnColor::BRANCH)
(e_jb_jnaej_j,InsnColor::BRANCH)
(e_jbe,InsnColor::BRANCH)
(e_jcxz_jec,InsnColor::BRANCH)
(e_jl,InsnColor::BRANCH)
(e_jle,InsnColor::BRANCH)
(e_jmp,InsnColor::JUMP)
(e_jmpe,InsnColor::JUMP)
(e_jnb,InsnColor::BRANCH)
(e_jnb_jae_j,InsnColor::BRANCH)
(e_jnbe,InsnColor::BRANCH)
(e_jnl,InsnColor::BRANCH)
(e_jnle,InsnColor::BRANCH)
(e_jno,InsnColor::BRANCH)
(e_jnp,InsnColor::BRANCH)
(e_jns,InsnColor::BRANCH)
(e_jnz,InsnColor::BRANCH)
(e_jo,InsnColor::BRANCH)
(e_jp,InsnColor::BRANCH)
(e_js,InsnColor::BRANCH)
(e_jz,InsnColor::BRANCH)
(e_loop,InsnColor::BRANCH)
(e_loope,InsnColor::BRANCH)
(e_loopn,InsnColor::BRANCH)
(e_call,InsnColor::CALL)
(e_cmp,InsnColor::TEST)
(e_cmppd,InsnColor::TEST)
(e_cmpps,InsnColor::TEST)
(e_cmpsb,InsnColor::TEST)
(e_cmpsd,InsnColor::TEST)
(e_cmpss,InsnColor::TEST)
(e_cmpsw,InsnColor::TEST)
(e_cmpxch,InsnColor::TEST)
(e_cmpxch8b,InsnColor::TEST)
(e_ret_far,InsnColor::CALL)
(e_ret_near,InsnColor::CALL)
(e_prefetch,InsnColor::MOV)
(e_prefetchNTA,InsnColor::MOV)
(e_prefetchT0,InsnColor::MOV)
(e_prefetchT1,InsnColor::MOV)
(e_prefetchT2,InsnColor::MOV)
(e_prefetch_w,InsnColor::MOV)
(e_prefetchw,InsnColor::MOV)
(e_No_Entry,InsnColor::NOCOLOR)
(e_aaa,InsnColor::ARITH)
(e_aad,InsnColor::ARITH)
(e_aam,InsnColor::ARITH)
(e_aas,InsnColor::ARITH)
(e_adc,InsnColor::ARITH)
(e_add,InsnColor::ARITH)
(e_addpd,InsnColor::ARITH)
(e_addps,InsnColor::ARITH)
(e_addsd,InsnColor::ARITH)
(e_addss,InsnColor::ARITH)
(e_addsubpd,InsnColor::ARITH)
(e_addsubps,InsnColor::ARITH)
(e_and,InsnColor::LOGIC)
(e_andnpd,InsnColor::LOGIC)
(e_andnps,InsnColor::LOGIC)
(e_andpd,InsnColor::LOGIC)
(e_andps,InsnColor::LOGIC)
(e_arpl,InsnColor::SYS)
(e_bound,InsnColor::TEST)
(e_bsf,InsnColor::ARITH)
(e_bsr,InsnColor::ARITH)
(e_bswap,InsnColor::ARITH)
(e_bt,InsnColor::TEST)
(e_btc,InsnColor::TEST)
(e_btr,InsnColor::TEST)
(e_bts,InsnColor::TEST)
(e_cbw,InsnColor::ARITH)
(e_cdq,InsnColor::ARITH)
(e_clc,InsnColor::ARITH)
(e_cld,InsnColor::ARITH)
(e_clflush,InsnColor::SYS)
(e_cli,InsnColor::SYS)
(e_clts,InsnColor::SYS)
(e_cmc,InsnColor::TEST)
(e_cmovbe,InsnColor::MOV)
(e_cmove,InsnColor::MOV)
(e_cmovnae,InsnColor::MOV)
(e_cmovnb,InsnColor::MOV)
(e_cmovnbe,InsnColor::MOV)
(e_cmovne,InsnColor::MOV)
(e_cmovng,InsnColor::MOV)
(e_cmovnge,InsnColor::MOV)
(e_cmovnl,InsnColor::MOV)
(e_cmovno,InsnColor::MOV)
(e_cmovns,InsnColor::MOV)
(e_cmovo,InsnColor::MOV)
(e_cmovpe,InsnColor::MOV)
(e_cmovpo,InsnColor::MOV)
(e_cmovs,InsnColor::MOV)
(e_comisd,InsnColor::CMP)
(e_comiss,InsnColor::CMP)
(e_cpuid,InsnColor::SYS)
(e_cvtdq2pd,InsnColor::STRING)
(e_cvtdq2ps,InsnColor::STRING)
(e_cvtpd2dq,InsnColor::STRING)
(e_cvtpd2pi,InsnColor::STRING)
(e_cvtpd2ps,InsnColor::STRING)
(e_cvtpi2pd,InsnColor::STRING)
(e_cvtpi2ps,InsnColor::STRING)
(e_cvtps2dq,InsnColor::STRING)
(e_cvtps2pd,InsnColor::STRING)
(e_cvtps2pi,InsnColor::STRING)
(e_cvtsd2si,InsnColor::STRING)
(e_cvtsd2ss,InsnColor::STRING)
(e_cvtsi2sd,InsnColor::STRING)
(e_cvtsi2ss,InsnColor::STRING)
(e_cvtss2sd,InsnColor::STRING)
(e_cvtss2si,InsnColor::STRING)
(e_cvttpd2dq,InsnColor::STRING)
(e_cvttpd2pi,InsnColor::STRING)
(e_cvttps2dq,InsnColor::STRING)
(e_cvttps2pi,InsnColor::STRING)
(e_cvttsd2si,InsnColor::STRING)
(e_cvttss2si,InsnColor::STRING)
(e_cwd,InsnColor::ARITH)
(e_cwde,InsnColor::ARITH)
(e_daa,InsnColor::ARITH)
(e_das,InsnColor::ARITH)
(e_dec,InsnColor::ARITH)
(e_div,InsnColor::ARITH)
(e_divpd,InsnColor::ARITH)
(e_divps,InsnColor::ARITH)
(e_divsd,InsnColor::ARITH)
(e_divss,InsnColor::ARITH)
(e_emms,InsnColor::SYS)
(e_enter,InsnColor::CALL)
(e_extrq,InsnColor::FLOATING)
(e_fadd,InsnColor::FLOATING)
(e_faddp,InsnColor::FLOATING)
(e_f2xm1,InsnColor::FLOATING)
(e_fbld,InsnColor::FLOATING)
(e_fbstp,InsnColor::FLOATING)
(e_fchs,InsnColor::FLOATING)
(e_fcmovb,InsnColor::FLOATING)
(e_fcmovbe,InsnColor::FLOATING)
(e_fcmove,InsnColor::FLOATING)
(e_fcmovne,InsnColor::FLOATING)
(e_fcmovu,InsnColor::FLOATING)
(e_fcmovnu,InsnColor::FLOATING)
(e_fcmovnb,InsnColor::FLOATING)
(e_fcmovnbe,InsnColor::FLOATING)
(e_fcom,InsnColor::FLOATING)
(e_fcomi,InsnColor::FLOATING)
(e_fcomip,InsnColor::FLOATING)
(e_fcomp,InsnColor::FLOATING)
(e_fcompp,InsnColor::FLOATING)
(e_fdiv,InsnColor::FLOATING)
(e_fdivp,InsnColor::FLOATING)
(e_fdivr,InsnColor::FLOATING)
(e_fdivrp,InsnColor::FLOATING)
(e_femms,InsnColor::FLOATING)
(e_ffree,InsnColor::FLOATING)
(e_fiadd,InsnColor::FLOATING)
(e_ficom,InsnColor::FLOATING)
(e_ficomp,InsnColor::FLOATING)
(e_fidiv,InsnColor::FLOATING)
(e_fidivr,InsnColor::FLOATING)
(e_fild,InsnColor::FLOATING)
(e_fimul,InsnColor::FLOATING)
(e_fist,InsnColor::FLOATING)
(e_fistp,InsnColor::FLOATING)
(e_fisttp,InsnColor::FLOATING)
(e_fisub,InsnColor::FLOATING)
(e_fisubr,InsnColor::FLOATING)
(e_fld,InsnColor::FLOATING)
(e_fld1,InsnColor::FLOATING)
(e_fldcw,InsnColor::FLOATING)
(e_fldenv,InsnColor::FLOATING)
(e_fmul,InsnColor::FLOATING)
(e_fmulp,InsnColor::FLOATING)
(e_fnop,InsnColor::FLOATING)
(e_fprem,InsnColor::FLOATING)
(e_frstor,InsnColor::FLOATING)
(e_fsave,InsnColor::FLOATING)
(e_fst,InsnColor::FLOATING)
(e_fstcw,InsnColor::FLOATING)
(e_fstenv,InsnColor::FLOATING)
(e_fstp,InsnColor::FLOATING)
(e_fstsw,InsnColor::FLOATING)
(e_fsub,InsnColor::FLOATING)
(e_fsubp,InsnColor::FLOATING)
(e_fsubr,InsnColor::FLOATING)
(e_fsubrp,InsnColor::FLOATING)
(e_fucom,InsnColor::FLOATING)
(e_fucomp,InsnColor::FLOATING)
(e_fucomi,InsnColor::FLOATING)
(e_fucomip,InsnColor::FLOATING)
(e_fucompp,InsnColor::FLOATING)
(e_fxch,InsnColor::FLOATING)
(e_fxrstor,InsnColor::FLOATING)
(e_fxsave,InsnColor::FLOATING)
(e_haddpd,InsnColor::FLOATING)
(e_haddps,InsnColor::FLOATING)
(e_hlt,InsnColor::SYS)
(e_hsubpd,InsnColor::SYS)
(e_hsubps,InsnColor::SYS)
(e_idiv,InsnColor::ARITH)
(e_imul,InsnColor::ARITH)
(e_in,InsnColor::MOV)
(e_inc,InsnColor::ARITH)
(e_insb,InsnColor::MOV)
(e_insd,InsnColor::MOV)
(e_insertq,InsnColor::FLOATING)
(e_insw,InsnColor::MOV)
(e_int,InsnColor::SYS)
(e_int3,InsnColor::SYS)
(e_int1,InsnColor::SYS)
(e_int80,InsnColor::SYS)
(e_into,InsnColor::SYS)
(e_invd,InsnColor::SYS)
(e_invlpg,InsnColor::SYS)
(e_iret,InsnColor::SYS)
(e_lahf,InsnColor::FLAGS)
(e_lar,InsnColor::SYS)
(e_lddqu,InsnColor::SYS)
(e_ldmxcsr,InsnColor::SYS)
(e_lds,InsnColor::MOV)
(e_lea,InsnColor::LEA)
(e_leave,InsnColor::CALL)
(e_les,InsnColor::MOV)
(e_lfence,InsnColor::LOGIC)
(e_lfs,InsnColor::MOV)
(e_lgdt,InsnColor::SYS)
(e_lgs,InsnColor::MOV)
(e_lidt,InsnColor::SYS)
(e_lldt,InsnColor::SYS)
(e_lmsw,InsnColor::SYS)
(e_lodsb,InsnColor::MOV)
(e_lodsd,InsnColor::MOV)
(e_lodsw,InsnColor::MOV)
(e_lsl,InsnColor::MOV)
(e_lss,InsnColor::MOV)
(e_ltr,InsnColor::SYS)
(e_maskmovdqu,InsnColor::MOV)
(e_maskmovq,InsnColor::MOV)
(e_maxpd,InsnColor::FLOATING)
(e_maxps,InsnColor::FLOATING)
(e_maxsd,InsnColor::FLOATING)
(e_maxss,InsnColor::FLOATING)
(e_mfence,InsnColor::SYS)
(e_minpd,InsnColor::FLOATING)
(e_minps,InsnColor::FLOATING)
(e_minsd,InsnColor::FLOATING)
(e_minss,InsnColor::FLOATING)
(e_mmxud,InsnColor::FLOATING)
(e_mov,InsnColor::MOV)
(e_movapd,InsnColor::MOV)
(e_movaps,InsnColor::MOV)
(e_movd,InsnColor::MOV)
(e_movddup,InsnColor::MOV)
(e_movdq2q,InsnColor::MOV)
(e_movdqa,InsnColor::MOV)
(e_movdqu,InsnColor::MOV)
(e_movhpd,InsnColor::MOV)
(e_movhps,InsnColor::MOV)
(e_movhps_movlhps,InsnColor::MOV)
(e_movlpd,InsnColor::MOV)
(e_movlps,InsnColor::MOV)
(e_movlps_movhlps,InsnColor::MOV)
(e_movmskpd,InsnColor::MOV)
(e_movmskps,InsnColor::MOV)
(e_movntdq,InsnColor::MOV)
(e_movnti,InsnColor::MOV)
(e_movntpd,InsnColor::MOV)
(e_movntps,InsnColor::MOV)
(e_movntq,InsnColor::MOV)
(e_movntsd,InsnColor::MOV)
(e_movntss,InsnColor::MOV)
(e_movq,InsnColor::MOV)
(e_movq2dq,InsnColor::MOV)
(e_movsb,InsnColor::MOV)
(e_movsd,InsnColor::MOV)
(e_movshdup,InsnColor::MOV)
(e_movsldup,InsnColor::MOV)
(e_movss,InsnColor::MOV)
(e_movsw,InsnColor::MOV)
(e_movsx,InsnColor::MOV)
(e_movsxd,InsnColor::MOV)
(e_movupd,InsnColor::MOV)
(e_movups,InsnColor::MOV)
(e_movzx,InsnColor::MOV)
(e_mul,InsnColor::ARITH)
(e_mulpd,InsnColor::ARITH)
(e_mulps,InsnColor::ARITH)
(e_mulsd,InsnColor::ARITH)
(e_mulss,InsnColor::ARITH)
(e_neg,InsnColor::ARITH)
(e_nop,InsnColor::BRANCH)
(e_not,InsnColor::LOGIC)
(e_or,InsnColor::LOGIC)
(e_orpd,InsnColor::LOGIC)
(e_orps,InsnColor::LOGIC)
(e_out,InsnColor::MOV)
(e_outsb,InsnColor::MOV)
(e_outsd,InsnColor::MOV)
(e_outsw,InsnColor::MOV)
(e_packssdw,InsnColor::ARITH)
(e_packsswb,InsnColor::ARITH)
(e_packuswb,InsnColor::ARITH)
(e_paddb,InsnColor::ARITH)
(e_paddd,InsnColor::ARITH)
(e_paddq,InsnColor::ARITH)
(e_paddsb,InsnColor::ARITH)
(e_paddsw,InsnColor::ARITH)
(e_paddusb,InsnColor::ARITH)
(e_paddusw,InsnColor::ARITH)
(e_paddw,InsnColor::ARITH)
(e_pand,InsnColor::LOGIC)
(e_pandn,InsnColor::LOGIC)
(e_pavgb,InsnColor::ARITH)
(e_pavgw,InsnColor::ARITH)
(e_pcmpeqb,InsnColor::CMP)
(e_pcmpeqd,InsnColor::CMP)
(e_pcmpeqw,InsnColor::CMP)
(e_pcmpgdt,InsnColor::CMP)
(e_pcmpgtb,InsnColor::CMP)
(e_pcmpgtw,InsnColor::CMP)
(e_pextrw,InsnColor::MOV)
(e_pinsrw,InsnColor::MOV)
(e_pmaddwd,InsnColor::ARITH)
(e_pmaxsw,InsnColor::ARITH)
(e_pmaxub,InsnColor::ARITH)
(e_pminsw,InsnColor::MOV)
(e_pminub,InsnColor::MOV)
(e_pmovmskb,InsnColor::MOV)
(e_pmulhuw,InsnColor::ARITH)
(e_pmulhw,InsnColor::ARITH)
(e_pmullw,InsnColor::ARITH)
(e_pmuludq,InsnColor::ARITH)
(e_pop,InsnColor::STACK)
(e_popa,InsnColor::STACK)
(e_popad,InsnColor::STACK)
(e_popf,InsnColor::STACK)
(e_popfd,InsnColor::STACK)
(e_popcnt,InsnColor::STACK)
(e_por,InsnColor::STACK)
(e_psadbw,InsnColor::ARITH)
(e_pshufd,InsnColor::ARITH)
(e_pshufhw,InsnColor::ARITH)
(e_pshuflw,InsnColor::ARITH)
(e_pshufw,InsnColor::ARITH)
(e_pslld,InsnColor::ARITH)
(e_pslldq,InsnColor::ARITH)
(e_psllq,InsnColor::ARITH)
(e_psllw,InsnColor::ARITH)
(e_psrad,InsnColor::ARITH)
(e_psraw,InsnColor::ARITH)
(e_psrld,InsnColor::ARITH)
(e_psrldq,InsnColor::ARITH)
(e_psrlq,InsnColor::ARITH)
(e_psrlw,InsnColor::ARITH)
(e_psubb,InsnColor::ARITH)
(e_psubd,InsnColor::ARITH)
(e_psubsb,InsnColor::ARITH)
(e_psubsw,InsnColor::ARITH)
(e_psubusb,InsnColor::ARITH)
(e_psubusw,InsnColor::ARITH)
(e_psubw,InsnColor::ARITH)
(e_punpckhbw,InsnColor::ARITH)
(e_punpckhdq,InsnColor::ARITH)
(e_punpckhqd,InsnColor::ARITH)
(e_punpckhwd,InsnColor::ARITH)
(e_punpcklbw,InsnColor::ARITH)
(e_punpcklqd,InsnColor::ARITH)
(e_punpcklqld,InsnColor::ARITH)
(e_punpcklwd,InsnColor::ARITH)
(e_push,InsnColor::STACK)
(e_pusha,InsnColor::STACK)
(e_pushad,InsnColor::STACK)
(e_pushf,InsnColor::FLAGS)
(e_pushfd,InsnColor::FLAGS)
(e_pxor,InsnColor::LOGIC)
(e_rcl,InsnColor::LOGIC)
(e_rcpps,InsnColor::LOGIC)
(e_rcpss,InsnColor::LOGIC)
(e_rcr,InsnColor::ARITH)
(e_rdmsr,InsnColor::SYS)
(e_rdpmc,InsnColor::SYS)
(e_rdtsc,InsnColor::SYS)
(e_rol,InsnColor::ARITH)
(e_ror,InsnColor::ARITH)
(e_rsm,InsnColor::ARITH)
(e_rsqrtps,InsnColor::FLOATING)
(e_rsqrtss,InsnColor::FLOATING)
(e_sahf,InsnColor::ARITH)
(e_salc,InsnColor::ARITH)
(e_sar,InsnColor::ARITH)
(e_sbb,InsnColor::ARITH)
(e_scasb,InsnColor::STRING)
(e_scasd,InsnColor::STRING)
(e_scasw,InsnColor::STRING)
(e_setb,InsnColor::CMP)
(e_setbe,InsnColor::CMP)
(e_setl,InsnColor::CMP)
(e_setle,InsnColor::CMP)
(e_setnb,InsnColor::CMP)
(e_setnbe,InsnColor::CMP)
(e_setnl,InsnColor::CMP)
(e_setnle,InsnColor::CMP)
(e_setno,InsnColor::CMP)
(e_setnp,InsnColor::CMP)
(e_setns,InsnColor::CMP)
(e_setnz,InsnColor::CMP)
(e_seto,InsnColor::CMP)
(e_setp,InsnColor::CMP)
(e_sets,InsnColor::CMP)
(e_setz,InsnColor::CMP)
(e_sfence,InsnColor::SYS)
(e_sgdt,InsnColor::SYS)
(e_shl_sal,InsnColor::ARITH)
(e_shld,InsnColor::ARITH)
(e_shr,InsnColor::ARITH)
(e_shrd,InsnColor::ARITH)
(e_shufpd,InsnColor::ARITH)
(e_shufps,InsnColor::ARITH)
(e_sidt,InsnColor::SYS)
(e_sldt,InsnColor::SYS)
(e_smsw,InsnColor::SYS)
(e_sqrtpd,InsnColor::FLOATING)
(e_sqrtps,InsnColor::FLOATING)
(e_sqrtsd,InsnColor::FLOATING)
(e_sqrtss,InsnColor::FLOATING)
(e_stc,InsnColor::FLAGS)
(e_std,InsnColor::FLAGS)
(e_sti,InsnColor::FLAGS)
(e_stmxcsr,InsnColor::SYS)
(e_stosb,InsnColor::STRING)
(e_stosd,InsnColor::STRING)
(e_stosw,InsnColor::STRING)
(e_str,InsnColor::SYS)
(e_sub,InsnColor::ARITH)
(e_subpd,InsnColor::ARITH)
(e_subps,InsnColor::ARITH)
(e_subsd,InsnColor::ARITH)
(e_subss,InsnColor::ARITH)
(e_syscall,InsnColor::SYS)
(e_sysenter,InsnColor::SYS)
(e_sysexit,InsnColor::SYS)
(e_sysret,InsnColor::SYS)
(e_test,InsnColor::CMP)
(e_ucomisd,InsnColor::CMP)
(e_ucomiss,InsnColor::CMP)
(e_ud,InsnColor::HALT)
(e_ud2,InsnColor::HALT)
(e_ud2grp10,InsnColor::HALT)
(e_unpckhpd,InsnColor::FLOATING)
(e_unpckhps,InsnColor::FLOATING)
(e_unpcklpd,InsnColor::FLOATING)
(e_unpcklps,InsnColor::FLOATING)
(e_verr,InsnColor::SYS)
(e_verw,InsnColor::SYS)
(e_vmread,InsnColor::SYS)
(e_vmwrite,InsnColor::SYS)
(e_vsyscall,InsnColor::SYS)
(e_wait,InsnColor::FLOATING)
(e_wbinvd,InsnColor::SYS)
(e_wrmsr,InsnColor::SYS)
(e_xadd,InsnColor::ARITH)
(e_xchg,InsnColor::MOV)
(e_xlat,InsnColor::MOV)
(e_xor,InsnColor::LOGIC)
(e_xorpd,InsnColor::LOGIC)
(e_xorps,InsnColor::LOGIC)
(e_fp_generic,InsnColor::FLOATING)
(e_3dnow_generic,InsnColor::FLOATING)
;

}

InsnColor::insn_color
InsnColor::lookup(Instruction::Ptr insn)
{
    std::map<entryID,InsnColor::insn_color>::iterator it = colormap.find(insn->getOperation().getID());
    if(it != colormap.end())
        return (*it).second;
    else
        return NOCOLOR;
}

BranchColor::branch_color
BranchColor::lookup(Instruction::Ptr insn)
{
    std::map<entryID,BranchColor::branch_color>::iterator it = 
        branchmap.find(insn->getOperation().getID());
    if(it != branchmap.end())
        return (*it).second;
    else
        return NOBRANCH;
}

static std::string inttostring(int i) {
    std::stringstream ret;
    ret << i;
    return ret.str();
}

std::string BranchColor::compact() const { 
    return inttostring(s_); 
} 

std::string InsnColor::compact() const { 
    return inttostring(s_); 
} 

std::map<unsigned short, InsnColor*> InsnColor::insnColorMap;

InsnColor* InsnColor::ColorLookup(unsigned short color) {
    if (insnColorMap.find(color) == insnColorMap.end()) {
        insnColorMap[color] = new InsnColor(color);
    }
    return insnColorMap[color];
}

std::map<std::string, LibCallColor*> LibCallColor::libCallColorMap;

LibCallColor* LibCallColor::ColorLookup(std::string &name) {
    if (libCallColorMap.find(name) == libCallColorMap.end()) {
        libCallColorMap[name] = new LibCallColor(name);
    }
    return libCallColorMap[name];
}

LocalCallColor LocalCallColor::localCallColor;
LocalCallColor* LocalCallColor::ColorLookup() {
    return &localCallColor;
}

