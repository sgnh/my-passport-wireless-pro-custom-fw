// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:802                    Version flow no.:1.1.66
#ifndef _CRT_REG_H_INCLUDED_
#define _CRT_REG_H_INCLUDED_

//#define  _CRT_USE_STRUCT
#ifdef _CRT_USE_STRUCT

typedef struct
{
    unsigned int    vercode:32;
}SC_verid;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    div_emb:2;
    unsigned int    cap_emb:2;
    unsigned int    reserved_1:3;
    unsigned int    en_emb:1;
    unsigned int    det_ddr2_off:1;
    unsigned int    main_pow_on:1;
    unsigned int    main_por_en:1;
    unsigned int    det_ddr_off:1;
    unsigned int    por_v33set_l:2;
    unsigned int    por_v11set_l:2;
    unsigned int    por_reser:4;
    unsigned int    reserved_2:1;
    unsigned int    ldov11_sel:2;
    unsigned int    stbldo_pow:1;
}SC_lv_rst;

typedef struct
{
    unsigned int    boption_rst_bypass:1;
    unsigned int    boption_efuse:1;
    unsigned int    boption_debounce_n:1;
    unsigned int    boption_gpu:1;
    unsigned int    boption_arm:1;
    unsigned int    boption_6:1;
    unsigned int    boption_5:1;
    unsigned int    boption_4:1;
    unsigned int    boption_3:1;
    unsigned int    boption_2:1;
    unsigned int    boption_1:1;
    unsigned int    boption_0:1;
    unsigned int    at_speed_pll_done:1;
    unsigned int    porl_host_s_en_n:1;
    unsigned int    porl_at_speed_scan:1;
    unsigned int    porl_boot_mode_n:1;
    unsigned int    reserved_0:7;
    unsigned int    porl_test_mode:5;
    unsigned int    porl_test_en_n:1;
    unsigned int    porl_pll_en:1;
    unsigned int    porl_ejtag_en_n:1;
    unsigned int    reserved_1:1;
}SC_pol;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    efuse_isln_en:1;
    unsigned int    ddr_isln_en:1;
    unsigned int    getn_isln_en:1;
    unsigned int    rstn_mt:1;
    unsigned int    mt_isln_en:1;
}ST_ctrl0;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    mcu_imem_bisr_rstn:1;
}ST_bisr0;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    mcu_imem_bisr_remap:1;
}ST_bisr1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    mcu_imem_bisr_done:1;
}ST_bisr2;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rstn_getn:1;
    unsigned int    rstn_i2c0_off:1;
    unsigned int    rstn_uart0_off:1;
    unsigned int    rstn_irda_off:1;
    unsigned int    rstn_pwm:1;
    unsigned int    rstn_pad_mux:1;
    unsigned int    rstn_iso_misc_off:1;
    unsigned int    rstn_iso_misc:1;
}ST_srst0;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    rstn_osc:1;
    unsigned int    rstn_rtc:1;
    unsigned int    rstn_emcu_top:1;
    unsigned int    rstn_emcu_core:1;
    unsigned int    rstn_hdmi_det:1;
    unsigned int    rstn_cec:1;
    unsigned int    rstn_syncp:1;
    unsigned int    reserved_1:1;
    unsigned int    rstn_cbus:1;
    unsigned int    rstn_alu:1;
    unsigned int    rstn_irda:1;
    unsigned int    rstn_ddc:1;
    unsigned int    rstn_lsadc:1;
}ST_srst1;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    clken_getn:1;
    unsigned int    clken_getn_phy:1;
    unsigned int    clken_i2c0_off:1;
    unsigned int    clken_uart0_off:1;
    unsigned int    clken_irda_off:1;
    unsigned int    clken_pwm:1;
    unsigned int    clken_pad_mux:1;
    unsigned int    clken_iso_misc_off:1;
    unsigned int    clken_iso_misc:1;
}ST_clken0;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    clken_osc:1;
    unsigned int    clken_rtc:1;
    unsigned int    clken_emcu_core:1;
    unsigned int    clken_hdmi_det:1;
    unsigned int    clken_cec:1;
    unsigned int    clken_syncp:1;
    unsigned int    reserved_1:1;
    unsigned int    clken_cbus:1;
    unsigned int    clken_alu:1;
    unsigned int    clken_irda:1;
    unsigned int    clken_ddc:1;
    unsigned int    clken_lsadc:1;
}ST_clken1;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    bus_div_en:1;
    unsigned int    bus_div_apply:1;
    unsigned int    bus_div_busy:1;
    unsigned int    reserved_1:1;
    unsigned int    bus_div_sel:3;
    unsigned int    reserved_2:11;
    unsigned int    bus_clksel:1;
}ST_busclk;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    emcu_div_en:1;
    unsigned int    emcu_div_apply:1;
    unsigned int    emcu_div_busy:1;
    unsigned int    reserved_1:1;
    unsigned int    emcu_div_sel:3;
    unsigned int    reserved_2:11;
    unsigned int    reserved_3:1;
}ST_emcuclk;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    wow_gmac_clksel:1;
    unsigned int    wow_clksel:1;
    unsigned int    osc_clksel:1;
    unsigned int    uart_clksel:1;
}ST_clkmux;

typedef struct
{
    unsigned int    st2_isln_en:1;
    unsigned int    reserved_0:23;
    unsigned int    st2_wakeup_tim:4;
    unsigned int    st2_de_iso_ps_tim:4;
}ST_alu_0;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    stie_self_wakeup:1;
    unsigned int    stie_rtc:1;
    unsigned int    stie_cec:1;
    unsigned int    stie_cbus:1;
    unsigned int    stie_iso_misc:1;
}ALU_ie;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    stip_self_wakeup:1;
    unsigned int    stip_rtc:1;
    unsigned int    stip_cec:1;
    unsigned int    stip_cbus:1;
    unsigned int    stip_iso_misc:1;
}ALU_ip;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    stpass_self_wakeup:1;
    unsigned int    stpass_rtc:1;
    unsigned int    stpass_cec:1;
    unsigned int    stpass_cbus:1;
    unsigned int    stpass_iso_misc:1;
}ALU_pass;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    rtc_scpu_ie:1;
    unsigned int    cec_scpu_ie:1;
    unsigned int    cbus_scpu_ie:1;
    unsigned int    hdmi_clk_det_scpu_ie:1;
    unsigned int    syncp_scpu_ie:1;
    unsigned int    iso_misc_off_scpu_ie:1;
    unsigned int    iso_misc_scpu_ie:1;
}STB_irq_all;

typedef struct
{
    unsigned int    reserved_0:9;
    unsigned int    osc_sw_s:7;
    unsigned int    reserved_1:2;
    unsigned int    osc_status:2;
    unsigned int    osc_cnt_diff:8;
    unsigned int    reserved_2:1;
    unsigned int    osc_rstb_emb:1;
    unsigned int    osc_tracking_mode:1;
    unsigned int    osc_tracking_en:1;
}ST_ring_osc_0;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    s_emb:7;
    unsigned int    dummy180600e8_11_9:3;
    unsigned int    osc_cnt_diff_max_clr:1;
    unsigned int    osc_cnt_diff_max:8;
}ST_ring_osc_1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    alu_test_mode_en:1;
    unsigned int    alu_dbg_sel:7;
    unsigned int    crt_dbg_sel:4;
    unsigned int    reserved_1:14;
    unsigned int    dbg_div_sel:2;
}ST_dbg_1;

typedef struct
{
    unsigned int    wdog_data1:32;
}WDOG_data1;

typedef struct
{
    unsigned int    wdog_data2:32;
}WDOG_data2;

typedef struct
{
    unsigned int    wdog_data3:32;
}WDOG_data3;

typedef struct
{
    unsigned int    wdog_data4:32;
}WDOG_data4;

typedef struct
{
    unsigned int    wdog_data5:32;
}WDOG_data5;

typedef struct
{
    unsigned int    wdog_data6:32;
}WDOG_data6;

typedef struct
{
    unsigned int    wdog_data7:32;
}WDOG_data7;

typedef struct
{
    unsigned int    wdog_data8:32;
}WDOG_data8;

typedef struct
{
    unsigned int    wdog_data9:32;
}WDOG_data9;

typedef struct
{
    unsigned int    wdog_data10:32;
}WDOG_data10;

typedef struct
{
    unsigned int    wdog_data11:32;
}WDOG_data11;

typedef struct
{
    unsigned int    wdog_data12:32;
}WDOG_data12;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    rstn_vde2:1;
    unsigned int    rstn_ve2_p2:1;
    unsigned int    rstn_ve2:1;
    unsigned int    rstn_vcpu2:1;
    unsigned int    rstn_vde:1;
    unsigned int    rstn_ve_p2:1;
    unsigned int    rstn_ve:1;
    unsigned int    rstn_vcpu:1;
    unsigned int    rstn_ae:1;
    unsigned int    rstn_scpu:1;
    unsigned int    rstn_pllreg:1;
}SYS_srst0;

typedef struct
{
    unsigned int    rstn_tvsb1:1;
    unsigned int    rstn_tvsb2:1;
    unsigned int    rstn_tvsb3:1;
    unsigned int    rstn_tvsb2_dc2:1;
    unsigned int    rstn_tvsb3_dc2:1;
    unsigned int    reserved_0:1;
    unsigned int    rstn_dcphy:1;
    unsigned int    rstn_dcu:1;
    unsigned int    rstn_if_demod:1;
    unsigned int    rstn_vdec:1;
    unsigned int    rstn_vdec2:1;
    unsigned int    rstn_vbis0:1;
    unsigned int    rstn_audio2_dac:1;
    unsigned int    rstn_audio_adc:1;
    unsigned int    rstn_audio_dac:1;
    unsigned int    rstn_audio:1;
    unsigned int    rstn_ifadc:1;
    unsigned int    reserved_1:2;
    unsigned int    rstn_me:1;
    unsigned int    rstn_apll_adc:1;
    unsigned int    rstn_hdmi:1;
    unsigned int    reserved_2:1;
    unsigned int    rstn_tp:1;
    unsigned int    rstn_cp:1;
    unsigned int    rstn_md:1;
    unsigned int    rstn_se:1;
    unsigned int    reserved_3:1;
    unsigned int    rstn_3d_gde:1;
    unsigned int    rstn_vodma:1;
    unsigned int    rstn_dispim:1;
    unsigned int    rstn_disp:1;
}SYS_srst1;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    reserved_1:1;
    unsigned int    rstn_tm:1;
    unsigned int    rstn_atvin2:1;
    unsigned int    rstn_atvin:1;
    unsigned int    rstn_osdcmp:1;
    unsigned int    rstn_etn:1;
    unsigned int    rstn_cr:1;
    unsigned int    reserved_2:1;
    unsigned int    rstn_bistreg:1;
    unsigned int    rstn_usb_arb:1;
    unsigned int    dummy18000108_19:1;
    unsigned int    rstn_usb3_mac:1;
    unsigned int    dummy18000108_17:1;
    unsigned int    reserved_3:1;
    unsigned int    dummy18000108_15_13:3;
    unsigned int    rstn_padmux:1;
    unsigned int    rstn_dtv_demod:1;
    unsigned int    rstn_misc:1;
    unsigned int    rstn_pwm:1;
    unsigned int    rstn_uart1:1;
    unsigned int    rstn_uart2:1;
    unsigned int    rstn_uart3:1;
    unsigned int    rstn_gpio:1;
    unsigned int    rstn_i2c1:1;
    unsigned int    rstn_i2c2:1;
    unsigned int    rstn_nf:1;
    unsigned int    rstn_sc:1;
    unsigned int    rstn_pc:1;
}SYS_srst2;

typedef struct
{
    unsigned int    rstn_scpu_dbg:1;
    unsigned int    reserved_0:5;
    unsigned int    rstn_dcphy2:1;
    unsigned int    rstn_dcu2:1;
    unsigned int    reserved_1:5;
    unsigned int    rstn_irtx:1;
    unsigned int    rstn_ddc:1;
    unsigned int    rstn_sd:1;
    unsigned int    reserved_2:8;
    unsigned int    rstn_usb2_phy_p3:1;
    unsigned int    rstn_usb2_phy_p2:1;
    unsigned int    rstn_usb2_phy_p1:1;
    unsigned int    rstn_usb2_phy_p0:1;
    unsigned int    reserved_3:1;
    unsigned int    rstn_usb3_phy:1;
    unsigned int    rstn_usb3_p0_mdio:1;
    unsigned int    reserved_4:1;
}SYS_srst3;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    reserved_1:1;
    unsigned int    clken_ve2_p2:1;
    unsigned int    clken_ve2:1;
    unsigned int    clken_vcpu2:1;
    unsigned int    reserved_2:1;
    unsigned int    clken_ve_p2:1;
    unsigned int    clken_ve:1;
    unsigned int    clken_vcpu:1;
    unsigned int    reserved_3:1;
    unsigned int    clken_scpu:1;
    unsigned int    clken_pllreg:1;
}SYS_clken0;

typedef struct
{
    unsigned int    clken_tvsb1:1;
    unsigned int    clken_tvsb2:1;
    unsigned int    clken_tvsb3:1;
    unsigned int    clken_tvsb2_dc2:1;
    unsigned int    clken_tvsb3_dc2:1;
    unsigned int    dummy18000114_26:1;
    unsigned int    clken_dcphy:1;
    unsigned int    clken_dcu:1;
    unsigned int    clken_if_demod:1;
    unsigned int    clken_vdec:1;
    unsigned int    dummy18000114_21:1;
    unsigned int    clken_vbis0:1;
    unsigned int    clken_audio_daad_128fs:1;
    unsigned int    clken_audio_daad_256fs:1;
    unsigned int    clken_audio_pre512fs:1;
    unsigned int    clken_audio:1;
    unsigned int    clken_ifadc:1;
    unsigned int    dummy18000114_14_13:2;
    unsigned int    clken_me:1;
    unsigned int    clken_apll_adc:1;
    unsigned int    clken_hdmi:1;
    unsigned int    reserved_0:1;
    unsigned int    clken_tp:1;
    unsigned int    clken_cp:1;
    unsigned int    clken_md:1;
    unsigned int    clken_se:1;
    unsigned int    dummy18000114_4:1;
    unsigned int    clken_3d_gde:1;
    unsigned int    clken_vodma:1;
    unsigned int    clken_dispim:1;
    unsigned int    clken_disp:1;
}SYS_clken1;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    clken_spds:1;
    unsigned int    clken_tm:1;
    unsigned int    clken_atvin_vd:1;
    unsigned int    clken_atvin_ifd:1;
    unsigned int    clken_osdcmp:1;
    unsigned int    clken_etn:1;
    unsigned int    clken_cr:1;
    unsigned int    clken_efuse:1;
    unsigned int    clken_bistreg:1;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    clken_usb:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    clken_audio2_512fs:1;
    unsigned int    clken_audio2_daad_256fs:1;
    unsigned int    clken_audio2_daad_128fs:1;
    unsigned int    clken_padmux:1;
    unsigned int    clken_dtv_demod:1;
    unsigned int    clken_misc:1;
    unsigned int    clken_pwm:1;
    unsigned int    clken_uart1:1;
    unsigned int    clken_uart2:1;
    unsigned int    clken_uart3:1;
    unsigned int    clken_gpio:1;
    unsigned int    clken_i2c1:1;
    unsigned int    clken_i2c2:1;
    unsigned int    clken_nf:1;
    unsigned int    clken_sc:1;
    unsigned int    clken_pc:1;
}SYS_clken2;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    clken_dcphy2:1;
    unsigned int    clken_dcu2:1;
    unsigned int    reserved_1:5;
    unsigned int    clken_irtx:1;
    unsigned int    clken_ddc:1;
    unsigned int    clken_sd:1;
    unsigned int    reserved_2:16;
}SYS_clken3;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    ejtag_mode:1;
    unsigned int    reserved_1:3;
    unsigned int    acpu_clksel:1;
}SYS_cpusel;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    epi_dbg_clksel:1;
    unsigned int    epi_div_clksel:1;
    unsigned int    sd_clksel:3;
    unsigned int    reserved_1:2;
    unsigned int    atvin_clk_sel:1;
    unsigned int    atvin_vd_clk_sel:1;
    unsigned int    reserved_2:1;
    unsigned int    cr_clksel:3;
    unsigned int    reserved_3:3;
    unsigned int    vdec_x27_clksel:1;
    unsigned int    reserved_4:2;
    unsigned int    vbis0_yppsel:1;
    unsigned int    inv_vbis0_clk:1;
    unsigned int    reserved_5:3;
    unsigned int    uart_clksel:1;
}SYS_clksel;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    nf_clksel:3;
    unsigned int    reserved_1:3;
    unsigned int    dtv_demod_multi_req_disable:1;
    unsigned int    demod_i2c_saddr_sel:1;
    unsigned int    aud_dtv_freq_sel:3;
}SYS_clkdiv;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    arm_wd_en:1;
    unsigned int    reserved_1:4;
    unsigned int    arm_wd_cnt:12;
}SYS_arm_wd;

typedef struct
{
    unsigned int    dummy1800021c_31_2:30;
    unsigned int    gpu_core2_clken:1;
    unsigned int    tvsb1_dc2_sel:1;
}SYS_tvsb1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    efuse_ready:1;
}EFUSE_ctrl0;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    atv_iso_en:1;
    unsigned int    atv_wek_status:1;
    unsigned int    atv_str_status:1;
    unsigned int    atv_wek_pow:1;
    unsigned int    atv_str_pow:1;
    unsigned int    reserved_1:3;
    unsigned int    dtv_iso_en:1;
    unsigned int    dtv_wek_status:1;
    unsigned int    dtv_str_status:1;
    unsigned int    dtv_wek_pow:1;
    unsigned int    dtv_str_pow:1;
}POWER_ctrl0;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    tm_enable:1;
    unsigned int    tm_data_valid:1;
    unsigned int    tm_data_sampled:1;
    unsigned int    tm_reverse_cmp_out:1;
    unsigned int    reserved_1:2;
    unsigned int    tm_data_out:6;
    unsigned int    tm_pwron_dly:16;
}TM_ctrl0;

typedef struct
{
    unsigned int    tm_compare_dly:16;
    unsigned int    tm_sample_dly:16;
}TM_ctrl1;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    tm_sbg:3;
    unsigned int    tm_sos:3;
    unsigned int    tm_sinl:2;
    unsigned int    reserved_1:2;
}TM_ctrl2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    data_in:20;
    unsigned int    reserved_1:2;
    unsigned int    data_in_ready:1;
    unsigned int    wire_sel:1;
    unsigned int    ro_sel:3;
    unsigned int    dss_rst_n:1;
}SS_12t_lvt_0;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    count_out:20;
    unsigned int    reserved_1:2;
    unsigned int    wsort_go:1;
    unsigned int    ready:1;
}SS_12t_lvt_1;

typedef struct
{
    unsigned int    rvt_12t_dss_rst_n:1;
    unsigned int    reserved_0:3;
    unsigned int    rvt_12t_ro_sel:3;
    unsigned int    rvt_12t_wire_sel:1;
    unsigned int    reserved_1:3;
    unsigned int    rvt_12t_ready:1;
    unsigned int    rvt_12t_count_out:20;
}SS_12t_rvt_0;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    rvt_12t_data_in_ready:1;
    unsigned int    rvt_12t_data_in:20;
    unsigned int    reserved_1:2;
    unsigned int    rvt_12t_data_read_ack:1;
    unsigned int    rvt_12t_wsort_go:1;
}SS_12t_rvt_1;

typedef struct
{
    unsigned int    lvt_9t_dss_rst_n:1;
    unsigned int    reserved_0:3;
    unsigned int    lvt_9t_ro_sel:3;
    unsigned int    lvt_9t_wire_sel:1;
    unsigned int    reserved_1:3;
    unsigned int    lvt_9t_ready:1;
    unsigned int    lvt_9t_count_out:20;
}SS_9t_lvt_0;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    lvt_9t_data_in_ready:1;
    unsigned int    lvt_9t_data_in:20;
    unsigned int    reserved_1:2;
    unsigned int    lvt_9t_data_read_ack:1;
    unsigned int    lvt_9t_wsort_go:1;
}SS_9t_lvt_1;

typedef struct
{
    unsigned int    rvt_9t_dss_rst_n:1;
    unsigned int    reserved_0:3;
    unsigned int    rvt_9t_ro_sel:3;
    unsigned int    rvt_9t_wire_sel:1;
    unsigned int    reserved_1:3;
    unsigned int    rvt_9t_ready:1;
    unsigned int    rvt_9t_count_out:20;
}SS_9t_rvt_0;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    rvt_9t_data_in_ready:1;
    unsigned int    rvt_9t_data_in:20;
    unsigned int    reserved_1:2;
    unsigned int    rvt_9t_data_read_ack:1;
    unsigned int    rvt_9t_wsort_go:1;
}SS_9t_rvt_1;

typedef struct
{
    unsigned int    rlvt_7t_dss_rst_n:1;
    unsigned int    reserved_0:3;
    unsigned int    rlvt_7t_ro_sel:3;
    unsigned int    rlvt_7t_wire_sel:1;
    unsigned int    reserved_1:3;
    unsigned int    rlvt_7t_ready:1;
    unsigned int    rlvt_7t_count_out:20;
}SS_7t_0;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    rlvt_7t_data_in_ready:1;
    unsigned int    rlvt_7t_data_in:20;
    unsigned int    reserved_1:2;
    unsigned int    rlvt_7t_data_read_ack:1;
    unsigned int    rlvt_7t_wsort_go:1;
}SS_7t_1;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    dbg0_div_sel:2;
    unsigned int    reserved_1:4;
    unsigned int    top_ssc_dbg_sel:3;
    unsigned int    reserved_2:1;
    unsigned int    crt_dbg_sel:8;
}SC_debug_0;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pllscpu_cp:2;
    unsigned int    pllscpu_n:2;
    unsigned int    pllscpu_m:8;
    unsigned int    pllscpu_ip:3;
    unsigned int    pllscpu_o:2;
    unsigned int    pllscpu_wdset:1;
    unsigned int    pllscpu_wdrst:1;
    unsigned int    pllscpu_cs:2;
    unsigned int    pllscpu_rs:3;
}SYS_pll_scpu1;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    pllscpu_vcorb:1;
    unsigned int    pllscpu_oeb:1;
    unsigned int    pllscpu_rstb:1;
    unsigned int    pllscpu_pow:1;
}SYS_pll_scpu2;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    pllacpu_tst:1;
    unsigned int    reserved_1:2;
    unsigned int    pllacpu_n:2;
    unsigned int    reserved_2:1;
    unsigned int    pllacpu_m:7;
    unsigned int    pllacpu_ip:3;
    unsigned int    pllacpu_o:2;
    unsigned int    pllacpu_wdset:1;
    unsigned int    pllacpu_wdrst:1;
    unsigned int    pllacpu_cs:2;
    unsigned int    pllacpu_rs:3;
}SYS_pll_acpu1;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    pllacpu_oeb:1;
    unsigned int    pllacpu_rstb:1;
    unsigned int    pllacpu_pow:1;
}SYS_pll_acpu2;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    pllvcpu_tst:1;
    unsigned int    reserved_1:2;
    unsigned int    pllvcpu_n:2;
    unsigned int    reserved_2:1;
    unsigned int    pllvcpu_m:7;
    unsigned int    pllvcpu_ip:3;
    unsigned int    pllvcpu_o:2;
    unsigned int    pllvcpu_wdset:1;
    unsigned int    pllvcpu_wdrst:1;
    unsigned int    pllvcpu_cs:2;
    unsigned int    pllvcpu_rs:3;
}SYS_pll_vcpu1;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    pllvcpu_oeb:1;
    unsigned int    pllvcpu_rstb:1;
    unsigned int    pllvcpu_pow:1;
}SYS_pll_vcpu2;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    pllcpu_reg:2;
}SYS_pll_cpu;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pllbus_n:2;
    unsigned int    pllbus_m:7;
    unsigned int    pllbus_ip:3;
    unsigned int    reserved_1:1;
    unsigned int    pllbus_rs:3;
    unsigned int    reserved_2:1;
    unsigned int    pllbus_cs:2;
    unsigned int    reserved_3:1;
    unsigned int    pllbus_cp:2;
    unsigned int    pllbus_r3:3;
    unsigned int    pllbus_c3:2;
}SYS_pll_bus1;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    dummy18000424_18:1;
    unsigned int    pllbus_pi_rl:2;
    unsigned int    pllbus_pi_rs:2;
    unsigned int    pllbus_pi_bias:2;
    unsigned int    dummy18000424_11:1;
    unsigned int    pllbus_wdmode:2;
    unsigned int    dummy18000424_8_6:3;
    unsigned int    pllbus_fupdn:1;
    unsigned int    pllbus_psen:1;
    unsigned int    pllbus_vcorb:1;
    unsigned int    dummy18000424_2:1;
    unsigned int    pllbus_tst:1;
    unsigned int    pllbus_pstst:1;
}SYS_pll_bus2;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    pllbus_o:1;
    unsigned int    pllbus_oeb:1;
    unsigned int    pllbus_rstb:1;
    unsigned int    pllbus_pow:1;
}SYS_pll_bus3;

typedef struct
{
    unsigned int    bus_ssc_sse:1;
    unsigned int    bus_ssc_ckinv:1;
    unsigned int    bus_ssc_sss:6;
    unsigned int    reserved_0:1;
    unsigned int    bus_ssc_ssn:7;
    unsigned int    bus_ssc_ssfpv:8;
    unsigned int    reserved_1:6;
    unsigned int    bus_ssc_stms:2;
}SC_buspll_ssc;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pllbus_n_h:2;
    unsigned int    pllbus_m_h:7;
    unsigned int    pllbus_ip_h:3;
    unsigned int    reserved_1:1;
    unsigned int    pllbus_rs_h:3;
    unsigned int    reserved_2:1;
    unsigned int    pllbus_cs_h:2;
    unsigned int    reserved_3:1;
    unsigned int    pllbus_cp_h:2;
    unsigned int    pllbus_r3_h:3;
    unsigned int    pllbus_c3_h:2;
}SYS_pll_h_bus1;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    dummy18000434_18:1;
    unsigned int    pllbus_pi_rl_h:2;
    unsigned int    pllbus_pi_rs_h:2;
    unsigned int    pllbus_pi_bias_h:2;
    unsigned int    dummy18000434_11:1;
    unsigned int    pllbus_wdmode_h:2;
    unsigned int    dummy18000434_8_6:3;
    unsigned int    pllbus_fupdn_h:1;
    unsigned int    pllbus_psen_h:1;
    unsigned int    pllbus_vcorb_h:1;
    unsigned int    dummy18000434_2:1;
    unsigned int    pllbus_tst_h:1;
    unsigned int    pllbus_pstst_h:1;
}SYS_pll_h_bus2;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    pllbus_o_h:1;
    unsigned int    pllbus_oeb_h:1;
    unsigned int    pllbus_rstb_h:1;
    unsigned int    pllbus_pow_h:1;
}SYS_pll_h_bus3;

typedef struct
{
    unsigned int    bush_ssc_sse:1;
    unsigned int    bush_ssc_ckinv:1;
    unsigned int    bush_ssc_sss:6;
    unsigned int    reserved_0:1;
    unsigned int    bush_ssc_ssn:7;
    unsigned int    bush_ssc_ssfpv:8;
    unsigned int    reserved_1:6;
    unsigned int    bush_ssc_stms:2;
}SC_bushpll_ssc;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pllbus_n_2:2;
    unsigned int    pllbus_m_2:7;
    unsigned int    pllbus_ip_2:3;
    unsigned int    reserved_1:1;
    unsigned int    pllbus_rs_2:3;
    unsigned int    reserved_2:1;
    unsigned int    pllbus_cs_2:2;
    unsigned int    reserved_3:1;
    unsigned int    pllbus_cp_2:2;
    unsigned int    pllbus_r3_2:3;
    unsigned int    pllbus_c3_2:2;
}SYS_pll_2_bus1;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    dummy18000444_18:1;
    unsigned int    pllbus_pi_rl_2:2;
    unsigned int    pllbus_pi_rs_2:2;
    unsigned int    pllbus_pi_bias_2:2;
    unsigned int    dummy18000444_11:1;
    unsigned int    pllbus_wdmode_2:2;
    unsigned int    dummy18000444_8_6:3;
    unsigned int    pllbus_fupdn_2:1;
    unsigned int    pllbus_psen_2:1;
    unsigned int    pllbus_vcorb_2:1;
    unsigned int    dummy18000444_2:1;
    unsigned int    pllbus_tst_2:1;
    unsigned int    pllbus_pstst_2:1;
}SYS_pll_2_bus2;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    pllbus_o_2:1;
    unsigned int    pllbus_oeb_2:1;
    unsigned int    pllbus_rstb_2:1;
    unsigned int    pllbus_pow_2:1;
}SYS_pll_2_bus3;

typedef struct
{
    unsigned int    bus2_ssc_sse:1;
    unsigned int    bus2_ssc_ckinv:1;
    unsigned int    bus2_ssc_sss:6;
    unsigned int    reserved_0:1;
    unsigned int    bus2_ssc_ssn:7;
    unsigned int    bus2_ssc_ssfpv:8;
    unsigned int    reserved_1:6;
    unsigned int    bus2_ssc_stms:2;
}SC_bus2pll_ssc;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    pllgpu_n:2;
    unsigned int    reserved_1:1;
    unsigned int    pllgpu_m:7;
    unsigned int    pllgpu_ip:3;
    unsigned int    pllgpu_o:2;
    unsigned int    pllgpu_wdset:1;
    unsigned int    pllgpu_wdrst:1;
    unsigned int    pllgpu_cs:2;
    unsigned int    pllgpu_rs:3;
}SYS_pll_gpu1;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    pllgpu_tst:1;
    unsigned int    pllgpu_oeb:1;
    unsigned int    pllgpu_rstb:1;
    unsigned int    pllgpu_pow:1;
}SYS_pll_gpu2;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    pllgpu_n_2:2;
    unsigned int    reserved_1:1;
    unsigned int    pllgpu_m_2:7;
    unsigned int    pllgpu_ip_2:3;
    unsigned int    pllgpu_o_2:2;
    unsigned int    pllgpu_wdset_2:1;
    unsigned int    pllgpu_wdrst_2:1;
    unsigned int    pllgpu_cs_2:2;
    unsigned int    pllgpu_rs_2:3;
}SYS_pll_2_gpu1;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    pllgpu_tst_2:1;
    unsigned int    pllgpu_oeb_2:1;
    unsigned int    pllgpu_rstb_2:1;
    unsigned int    pllgpu_pow_2:1;
}SYS_pll_2_gpu2;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    pllvodma_n:2;
    unsigned int    reserved_1:1;
    unsigned int    pllvodma_m:7;
    unsigned int    pllvodma_ip:3;
    unsigned int    pllvodma_o:2;
    unsigned int    pllvodma_wdset:1;
    unsigned int    pllvodma_wdrst:1;
    unsigned int    pllvodma_cs:2;
    unsigned int    pllvodma_rs:3;
}SYS_pll_vodma1;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    pllvodma_tst:1;
    unsigned int    pllvodma_oeb:1;
    unsigned int    pllvodma_rstb:1;
    unsigned int    pllvodma_pow:1;
}SYS_pll_vodma2;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    pllbus_reser:4;
    unsigned int    reserved_1:2;
    unsigned int    pllbus_reg:2;
    unsigned int    reserved_2:2;
    unsigned int    pllbustst_div:2;
    unsigned int    reserved_3:3;
    unsigned int    pllbustst_sel:5;
}SYS_pllbus_tst;

typedef struct
{
    unsigned int    plldds_n:2;
    unsigned int    plldds_m:7;
    unsigned int    plldds_ip:3;
    unsigned int    plldds_rs:3;
    unsigned int    plldds_cs:2;
    unsigned int    plldds_cp:2;
    unsigned int    plldds_r3:3;
    unsigned int    plldds_c3:2;
    unsigned int    plldds_pi_rl:2;
    unsigned int    plldds_pi_rs:2;
    unsigned int    plldds_pi_bias:2;
    unsigned int    plldds_wdmode:2;
}SYS_pll_disp_sd1;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    dummy18000474_28_25:4;
    unsigned int    pcr_a_smooth_en:1;
    unsigned int    dummy18000474_23:1;
    unsigned int    pcr_a_phase_sel:1;
    unsigned int    dummy18000474_21:1;
    unsigned int    pcr_a_ctl_en:1;
    unsigned int    dummy18000474_19:1;
    unsigned int    plldds_fupdn:1;
    unsigned int    dummy18000474_17:1;
    unsigned int    plldds_ddsen:1;
    unsigned int    dummy18000474_15:1;
    unsigned int    plldds_vcorb:1;
    unsigned int    dummy18000474_13:1;
    unsigned int    plldds_tst:1;
    unsigned int    plldds_pstst:1;
    unsigned int    dummy18000474_10:1;
    unsigned int    reserved_1:10;
}SYS_pll_disp_sd2;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    dummy18000478_30:1;
    unsigned int    psaud1_fupdn:1;
    unsigned int    psaud1_div:1;
    unsigned int    dummy18000478_27:1;
    unsigned int    psaud1_tst:1;
    unsigned int    psaud1_psen:1;
    unsigned int    dummy18000478_24:1;
    unsigned int    psaud2_fupdn:1;
    unsigned int    psaud2_div:1;
    unsigned int    psaud2_tst:1;
    unsigned int    psaud2_psen:1;
    unsigned int    reserved_1:16;
    unsigned int    psaud1_oeb:1;
    unsigned int    psaud1_rstb:1;
    unsigned int    psaud2_oeb:1;
    unsigned int    psaud2_rstb:1;
}SYS_pll_disp_sd3;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    plldds_o:2;
    unsigned int    reserved_1:1;
    unsigned int    plldds_oeb:1;
    unsigned int    plldds_rstb:1;
    unsigned int    plldds_pow:1;
}SYS_pll_disp_sd4;

typedef struct
{
    unsigned int    plldds_pcr_acc:16;
    unsigned int    plldds_pcr_overflow:16;
}SYS_pll_disp_sd5;

typedef struct
{
    unsigned int    n_pcr_a_n_nxt:16;
    unsigned int    pcr_a_n_nxt:16;
}SYS_pll_disp_sd6;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pcr_a_n_nxt_add:8;
    unsigned int    pcr_a_n_nxt_add_period:16;
}SYS_pll_disp_sd7;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    swsce:1;
    unsigned int    reserved_1:1;
    unsigned int    tme:1;
    unsigned int    reserved_2:2;
    unsigned int    tmps:1;
    unsigned int    psc:1;
    unsigned int    reserved_3:3;
    unsigned int    swcs:7;
    unsigned int    reserved_4:7;
    unsigned int    sd:1;
    unsigned int    su:1;
}AI_clkcr;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dpll_m:8;
    unsigned int    reserved_1:5;
    unsigned int    dpll_n:3;
    unsigned int    reserved_2:1;
    unsigned int    dpll_ip:3;
    unsigned int    reserved_3:1;
    unsigned int    dpll_rs:3;
    unsigned int    dpll_cp:2;
    unsigned int    dpll_cs:2;
}SYS_pll_disp1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dpll_reser:4;
    unsigned int    dpll_reg:2;
    unsigned int    dpll_fupdn:1;
    unsigned int    dpll_stop:1;
    unsigned int    reserved_1:2;
    unsigned int    dpll_reserve:1;
    unsigned int    dpll_bpphs:1;
    unsigned int    reserved_2:1;
    unsigned int    dpll_bpn:1;
    unsigned int    dpll_o:2;
    unsigned int    reserved_3:5;
    unsigned int    dpll_rstb:1;
    unsigned int    dpll_wdrst:1;
    unsigned int    dpll_wdset:1;
    unsigned int    dpll_clksel:1;
    unsigned int    dpll_freeze:1;
    unsigned int    dpll_vcorstb:1;
    unsigned int    dpll_pwdn:1;
}SYS_pll_disp2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vby1_dpll_m:8;
    unsigned int    reserved_1:5;
    unsigned int    vby1_dpll_n:3;
    unsigned int    reserved_2:1;
    unsigned int    vby1_dpll_ip:3;
    unsigned int    reserved_3:1;
    unsigned int    vby1_dpll_rs:3;
    unsigned int    vby1_dpll_cp:2;
    unsigned int    vby1_dpll_cs:2;
}SYS_pll_vby11;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vby1_dpll_reser:4;
    unsigned int    vby1_dpll_reg:2;
    unsigned int    vby1_dpll_fupdn:1;
    unsigned int    vby1_dpll_stop:1;
    unsigned int    reserved_1:2;
    unsigned int    vby1_dpll_reserve:1;
    unsigned int    vby1_dpll_bpphs:1;
    unsigned int    reserved_2:1;
    unsigned int    vby1_dpll_bpn:1;
    unsigned int    vby1_dpll_o:2;
    unsigned int    reserved_3:5;
    unsigned int    vby1_dpll_rstb:1;
    unsigned int    vby1_dpll_wdrst:1;
    unsigned int    vby1_dpll_wdset:1;
    unsigned int    vby1_dpll_clksel:1;
    unsigned int    vby1_dpll_freeze:1;
    unsigned int    vby1_dpll_vcorstb:1;
    unsigned int    vby1_dpll_pwdn:1;
}SYS_pll_vby12;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    plletn_n:2;
    unsigned int    reserved_1:1;
    unsigned int    plletn_m:7;
    unsigned int    reserved_2:1;
    unsigned int    plletn_ip:3;
    unsigned int    plletn_o:4;
    unsigned int    reserved_3:2;
    unsigned int    plletn_wdmode:2;
    unsigned int    plletn_lf_cp:2;
    unsigned int    plletn_lf_rs:2;
}SYS_pll_etn1;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    plletn_ldo_sel:2;
    unsigned int    plletn_ldo_pow:1;
    unsigned int    reserved_1:2;
    unsigned int    plletn_rstb:1;
    unsigned int    plletn_pow:1;
}SYS_pll_etn2;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    pllvodma_wdout:1;
    unsigned int    pllgpu2_wdout:1;
    unsigned int    pllvby1_wdout:1;
    unsigned int    pllaud_status:1;
    unsigned int    pll512fs_wdout:1;
    unsigned int    pllbush_wdout:1;
    unsigned int    pllgpu_wdout:1;
    unsigned int    plldif_wdout:1;
    unsigned int    pllbus2_wdout:1;
    unsigned int    plletn_wdout:1;
    unsigned int    reserved_1:1;
    unsigned int    pllbus_wdout:1;
    unsigned int    plldisp_wdout:1;
    unsigned int    reserved_2:1;
    unsigned int    plldds_wdout:1;
    unsigned int    pllvcpu_wdout:1;
    unsigned int    pllacpu_wdout:1;
    unsigned int    pllscpu_wdout:1;
}SYS_pll_wd_out;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    pll512fs_n:3;
    unsigned int    reserved_1:1;
    unsigned int    pll512fs_m:7;
    unsigned int    pll512fs_bpn:1;
    unsigned int    pll512fs_bps:1;
    unsigned int    pll512fs_cs:2;
    unsigned int    reserved_2:1;
    unsigned int    pll512fs_ip:3;
    unsigned int    pll512fs_s:3;
    unsigned int    pll512fs_q:3;
    unsigned int    pll512fs_rs:3;
    unsigned int    pll512fs_tst:1;
    unsigned int    pll512fs_wdrst:1;
    unsigned int    pll512fs_wdset:1;
}SYS_pll_512fs1;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    pll512fs_oeb:1;
    unsigned int    pll512fs_rstb:1;
    unsigned int    pll512fs_pow:1;
}SYS_pll_512fs2;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    plldif_n:2;
    unsigned int    reserved_1:1;
    unsigned int    plldif_m:7;
    unsigned int    reserved_2:1;
    unsigned int    plldif_ip:3;
    unsigned int    plldif_lf_rs:2;
    unsigned int    plldif_lf_cp:2;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:11;
}SYS_pll_dif1;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:2;
    unsigned int    plldif_wdmode:2;
    unsigned int    reserved_3:2;
    unsigned int    plldif_divdig_sel:2;
    unsigned int    reserved_4:2;
    unsigned int    plldif_divadc_sel:2;
}SYS_pll_dif2;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    plldif_pd_d2s:1;
    unsigned int    plldif_vco_rstb:1;
    unsigned int    plldif_rstb:1;
    unsigned int    plldif_pow:1;
}SYS_pll_dif3;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pll27x_wdmode:2;
    unsigned int    reserved_1:2;
    unsigned int    pll27x_lf_cp:2;
    unsigned int    reserved_2:2;
    unsigned int    pll27x_lf_rs:2;
    unsigned int    reserved_3:1;
    unsigned int    pll27x_ip:3;
    unsigned int    reserved_4:3;
    unsigned int    pll27x_m_sel:1;
    unsigned int    reserved_5:2;
    unsigned int    pll27x_n:2;
    unsigned int    reserved_6:1;
    unsigned int    pll27x_m:7;
}SYS_pll_27x1;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:2;
    unsigned int    reserved_4:1;
    unsigned int    xixo_load:1;
    unsigned int    xixo_drive_sel:2;
    unsigned int    reserved_5:1;
    unsigned int    pll27x_pow_ldo11v:1;
    unsigned int    pll27x_ldo11v_sel:2;
    unsigned int    reserved_6:1;
    unsigned int    pll27x_pow_ldo:1;
    unsigned int    pll27x_ldo_sel:2;
    unsigned int    reserved_7:2;
    unsigned int    pll27x_ps_54m_delay:2;
    unsigned int    reserved_8:2;
    unsigned int    pll27x_ps_psel_pulse_w:1;
    unsigned int    pll27x_ps_duty_sel:1;
}SYS_pll_27x2;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    pll27x_reserve:10;
    unsigned int    reserved_1:3;
    unsigned int    pll27x_ps_en:1;
    unsigned int    reserved_2:1;
    unsigned int    pll27x_vcorstb:1;
    unsigned int    pll27x_rstb:1;
    unsigned int    pll27x_pow:1;
}SYS_pll_27x3;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    pll27x_d16_en:1;
    unsigned int    pll27x_pll_tst:3;
    unsigned int    pll27x_en_tst:1;
    unsigned int    reserved_1:2;
    unsigned int    pll27x_ck108m_div:2;
    unsigned int    pll27x_yppadc_cko_sel:2;
    unsigned int    pll27x_yppadc_cko_en:1;
    unsigned int    pll27x_yppadc_ck54m_en:1;
    unsigned int    pll27x_ifadc_cko_sel:2;
    unsigned int    pll27x_ifadc_div:1;
    unsigned int    pll27x_ifadc_cko_en:1;
    unsigned int    reserved_2:2;
    unsigned int    reserved_3:1;
    unsigned int    ckin_pllaud_mux:1;
    unsigned int    reserved_4:3;
    unsigned int    ck_ifadc_mux:1;
}SYS_pll_27x4;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    pllaud_ip:3;
    unsigned int    reserved_1:1;
    unsigned int    pllaud_rs:3;
    unsigned int    reserved_2:1;
    unsigned int    pllaud_cs:2;
    unsigned int    reserved_3:3;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:1;
    unsigned int    pllaud_wdrst:1;
    unsigned int    pllaud_wdset:1;
    unsigned int    pllaud_tst:1;
}SYS_pll_aud1;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    pllaud_rstb:1;
    unsigned int    pllaud_oeb1:1;
    unsigned int    pllaud_oeb2:1;
    unsigned int    pllaud_pwdn:1;
}SYS_pll_aud3;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    bb_micbias_clksel:2;
}SYS_pll_aud4;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    psaud_psen:1;
    unsigned int    psaud_en:1;
    unsigned int    psaud_tst:1;
    unsigned int    psaud_ctrl:1;
}SYS_pll_psaud1;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    psaud_div:4;
}SYS_pll_psaud2;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    reg_pll_dbug_en:1;
    unsigned int    reg_oeb5:1;
    unsigned int    reg_oeb4:1;
    unsigned int    reg_oeb3:1;
    unsigned int    reg_oeb2:1;
    unsigned int    reg_oeb1:1;
    unsigned int    reg_oeb0:1;
    unsigned int    reg_pll_rstb_in:1;
    unsigned int    reg_pll_en:1;
}SYS_pll_ddr1;

typedef struct
{
    unsigned int    reg_en_post_pi:7;
    unsigned int    reg_reserved:4;
    unsigned int    reg_post_pi_rs:1;
    unsigned int    reg_pll_sel_cpmode:1;
    unsigned int    reg_pdiv:2;
    unsigned int    reg_cco_kvco:1;
    unsigned int    reg_icp:4;
    unsigned int    reg_post_pi_bias:2;
    unsigned int    reg_post_pi_rl:2;
    unsigned int    reg_pll_ldo_vsel:2;
    unsigned int    reg_lpf_sr:3;
    unsigned int    reg_lpf_cp:1;
    unsigned int    reg_loop_pi_isel:2;
}SYS_pll_ddr2;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    reg_post_pi_sel3:6;
    unsigned int    reserved_1:2;
    unsigned int    reg_post_pi_sel2:6;
    unsigned int    reserved_2:2;
    unsigned int    reg_post_pi_sel1:6;
    unsigned int    reserved_3:2;
    unsigned int    reg_post_pi_sel0:6;
}SYS_pll_ddr3;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    reg_post_pi_sel6:6;
    unsigned int    reserved_1:2;
    unsigned int    reg_post_pi_sel5:6;
    unsigned int    reserved_2:2;
    unsigned int    reg_post_pi_sel4:6;
}SYS_pll_ddr4;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    reg_f390k:2;
    unsigned int    reg_wd_enable:1;
    unsigned int    reg_time2_rst_width:2;
    unsigned int    reg_time_rdy_ckout:2;
    unsigned int    reg_time0_ck:3;
}SYS_pll_ddr_ssc1;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    reg_sel_mode:1;
    unsigned int    reg_n_code:8;
    unsigned int    reserved_1:3;
    unsigned int    reg_f_code:13;
    unsigned int    reserved_2:1;
    unsigned int    reg_en_ssc:1;
    unsigned int    reg_bypass_pi:1;
    unsigned int    reg_en_center_in:1;
}SYS_pll_ddr_ssc2;

typedef struct
{
    unsigned int    reg_weighting_sel:3;
    unsigned int    reg_sel_order:1;
    unsigned int    reg_tbase:12;
    unsigned int    reserved_0:3;
    unsigned int    reg_step_in:13;
}SYS_pll_ddr_ssc3;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    reg_ck3_div2_ph:1;
    unsigned int    reg_ck2x3_sel:1;
    unsigned int    reserved_1:2;
    unsigned int    reg_ck2_div2_ph:1;
    unsigned int    reg_ck2x2_sel:1;
    unsigned int    reserved_2:2;
    unsigned int    reg_ck1_div2_ph:1;
    unsigned int    reg_ck2x1_sel:1;
}SYS_pll_ddr5;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    reg_pll_dbug_en:1;
    unsigned int    reg_oeb5:1;
    unsigned int    reg_oeb4:1;
    unsigned int    reg_oeb3:1;
    unsigned int    reg_oeb2:1;
    unsigned int    reg_oeb1:1;
    unsigned int    reg_oeb0:1;
    unsigned int    reg_pll_rstb_in:1;
    unsigned int    reg_pll_en:1;
}SYS_pll_ddr1_2;

typedef struct
{
    unsigned int    reg_en_post_pi:7;
    unsigned int    reg_reserved:4;
    unsigned int    reg_post_pi_rs:1;
    unsigned int    reg_pll_sel_cpmode:1;
    unsigned int    reg_pdiv:2;
    unsigned int    reg_cco_kvco:1;
    unsigned int    reg_icp:4;
    unsigned int    reg_post_pi_bias:2;
    unsigned int    reg_post_pi_rl:2;
    unsigned int    reg_pll_ldo_vsel:2;
    unsigned int    reg_lpf_sr:3;
    unsigned int    reg_lpf_cp:1;
    unsigned int    reg_loop_pi_isel:2;
}SYS_pll_ddr2_2;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    reg_post_pi_sel3:6;
    unsigned int    reserved_1:2;
    unsigned int    reg_post_pi_sel2:6;
    unsigned int    reserved_2:2;
    unsigned int    reg_post_pi_sel1:6;
    unsigned int    reserved_3:2;
    unsigned int    reg_post_pi_sel0:6;
}SYS_pll_ddr3_2;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    reg_post_pi_sel6:6;
    unsigned int    reserved_1:2;
    unsigned int    reg_post_pi_sel5:6;
    unsigned int    reserved_2:2;
    unsigned int    reg_post_pi_sel4:6;
}SYS_pll_ddr4_2;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    reg_f390k:2;
    unsigned int    reg_wd_enable:1;
    unsigned int    reg_time2_rst_width:2;
    unsigned int    reg_time_rdy_ckout:2;
    unsigned int    reg_time0_ck:3;
}SYS_pll_ddr_ssc1_2;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    reg_sel_mode:1;
    unsigned int    reg_n_code:8;
    unsigned int    reserved_1:3;
    unsigned int    reg_f_code:13;
    unsigned int    reserved_2:1;
    unsigned int    reg_en_ssc:1;
    unsigned int    reg_bypass_pi:1;
    unsigned int    reg_en_center_in:1;
}SYS_pll_ddr_ssc2_2;

typedef struct
{
    unsigned int    reg_weighting_sel:3;
    unsigned int    reg_sel_order:1;
    unsigned int    reg_tbase:12;
    unsigned int    reserved_0:3;
    unsigned int    reg_step_in:13;
}SYS_pll_ddr_ssc3_2;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    reg_ck3_div2_ph:1;
    unsigned int    reg_ck2x3_sel:1;
    unsigned int    reserved_1:2;
    unsigned int    reg_ck2_div2_ph:1;
    unsigned int    reg_ck2x2_sel:1;
    unsigned int    reserved_2:2;
    unsigned int    reg_ck1_div2_ph:1;
    unsigned int    reg_ck2x1_sel:1;
}SYS_pll_ddr5_2;

typedef struct
{
    unsigned int    dclk_field_flag_mode_en:1;
    unsigned int    dclk_filed_flag_slt:3;
    unsigned int    dclk_offset_11_0:12;
    unsigned int    dclk_new_en:1;
    unsigned int    dclk_ss_test:1;
    unsigned int    dclk_freq_syn_slt:6;
    unsigned int    dclk_ss_rag:4;
    unsigned int    dummy18000640_3:1;
    unsigned int    dclk_ss_load:1;
    unsigned int    dummy18000640_1:1;
    unsigned int    dclk_ss_en:1;
}SYS_dclkss;

typedef struct
{
    unsigned int    sscg_mcode_slow_modify_valid:1;
    unsigned int    sscg_mcode_slow_modify_stable:1;
    unsigned int    sscg_mcode_slow_modify_pixel:12;
    unsigned int    sscg_offset_slow_modify_valid:1;
    unsigned int    sscg_offset_slow_modify_stable:1;
    unsigned int    sscg_offset_slow_modify_pixel:12;
    unsigned int    in_frame_tracking_offset_inverse:1;
    unsigned int    in_frame_tracking_ypbpr_en:1;
    unsigned int    in_frame_tracking_vd_dec_en:1;
    unsigned int    in_frame_tracking_general_en:1;
}DPLL_in_fsync_tracking_ctrl;

typedef struct
{
    unsigned int    in_frame_tracking_neg_th:12;
    unsigned int    in_frame_tracking_pos_th:12;
    unsigned int    in_frame_tracking_mul:8;
}DPLL_in_fsync_tracking_ctrl2;

typedef struct
{
    unsigned int    sscg_offset_over_flag:1;
    unsigned int    sscg_profile_over_underflow_flag:1;
    unsigned int    sscg_profile_protection:1;
    unsigned int    sscg_offset_over_th_max:13;
    unsigned int    dpll_mcode_protection:1;
    unsigned int    dpll_mcode_protection_ready_width:2;
    unsigned int    sscg_offset_over_th_value:13;
}DPLL_in_fsync_tracking_debug;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    frc2fsync_speedup_m_code:3;
    unsigned int    reserved_1:5;
    unsigned int    frc2fsync_speedup_offset:11;
}DCLK_frc2fsync_speedup;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    final_m_code:10;
    unsigned int    reserved_1:3;
    unsigned int    final_profile:13;
}DPLL_status_ro;

typedef struct
{
    unsigned int    final_profile_force_64n_en:2;
    unsigned int    dclk_ss_async_protection:1;
    unsigned int    reserved_0:14;
    unsigned int    dclk_ss_fmdiv:7;
    unsigned int    reserved_1:1;
    unsigned int    dclk_ss_protection_cnt_max:7;
}DCLKSS_freq;

typedef struct
{
    unsigned int    dummy1800065c_31_30:2;
    unsigned int    dclk_ss_shuffle_en:1;
    unsigned int    dclk_profile_remap_en:1;
    unsigned int    dclk_profile_remap_1:12;
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_0:12;
}DCLKSS_profile0;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_3:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_2:12;
}DCLKSS_profile1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_5:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_4:12;
}DCLKSS_profile2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_7:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_6:12;
}DCLKSS_profile3;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_9:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_8:12;
}DCLKSS_profile4;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_11:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_10:12;
}DCLKSS_profile5;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_13:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_12:12;
}DCLKSS_profile6;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_15:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_14:12;
}DCLKSS_profile7;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_17:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_16:12;
}DCLKSS_profile8;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_19:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_18:12;
}DCLKSS_profile9;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_21:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_20:12;
}DCLKSS_profile10;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_23:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_22:12;
}DCLKSS_profile11;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_25:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_24:12;
}DCLKSS_profile12;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_27:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_26:12;
}DCLKSS_profile13;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_profile_remap_29:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_28:12;
}DCLKSS_profile14;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    dclk_profile_remap_31:13;
    unsigned int    reserved_1:4;
    unsigned int    dclk_profile_remap_30:12;
}DCLKSS_profile15;
#endif


#define SC_VERID                                                      0x18060000
#define SC_VERID_reg_addr                                             "0xb8060000"
#define SC_VERID_reg                                                  0xb8060000
#define SC_VERID_inst_addr                                            "0x0000"
#define SC_VERID_inst                                                 0x0000
#define SC_VERID_vercode_shift                                        (0)
#define SC_VERID_vercode_mask                                         (0xFFFFFFFF)
#define SC_VERID_vercode(data)                                        (0xFFFFFFFF&(data))
#define SC_VERID_get_vercode(data)                                    (0xFFFFFFFF&(data))


#define SC_LV_RST                                                     0x18060004
#define SC_LV_RST_reg_addr                                            "0xb8060004"
#define SC_LV_RST_reg                                                 0xb8060004
#define SC_LV_RST_inst_addr                                           "0x0001"
#define SC_LV_RST_inst                                                0x0001
#define SC_LV_RST_div_emb_shift                                       (22)
#define SC_LV_RST_cap_emb_shift                                       (20)
#define SC_LV_RST_en_emb_shift                                        (16)
#define SC_LV_RST_det_ddr2_off_shift                                  (15)
#define SC_LV_RST_main_pow_on_shift                                   (14)
#define SC_LV_RST_main_por_en_shift                                   (13)
#define SC_LV_RST_det_ddr_off_shift                                   (12)
#define SC_LV_RST_por_v33set_l_shift                                  (10)
#define SC_LV_RST_por_v11set_l_shift                                  (8)
#define SC_LV_RST_por_reser_shift                                     (4)
#define SC_LV_RST_ldov11_sel_shift                                    (1)
#define SC_LV_RST_stbldo_pow_shift                                    (0)
#define SC_LV_RST_div_emb_mask                                        (0x00C00000)
#define SC_LV_RST_cap_emb_mask                                        (0x00300000)
#define SC_LV_RST_en_emb_mask                                         (0x00010000)
#define SC_LV_RST_det_ddr2_off_mask                                   (0x00008000)
#define SC_LV_RST_main_pow_on_mask                                    (0x00004000)
#define SC_LV_RST_main_por_en_mask                                    (0x00002000)
#define SC_LV_RST_det_ddr_off_mask                                    (0x00001000)
#define SC_LV_RST_por_v33set_l_mask                                   (0x00000C00)
#define SC_LV_RST_por_v11set_l_mask                                   (0x00000300)
#define SC_LV_RST_por_reser_mask                                      (0x000000F0)
#define SC_LV_RST_ldov11_sel_mask                                     (0x00000006)
#define SC_LV_RST_stbldo_pow_mask                                     (0x00000001)
#define SC_LV_RST_div_emb(data)                                       (0x00C00000&((data)<<22))
#define SC_LV_RST_cap_emb(data)                                       (0x00300000&((data)<<20))
#define SC_LV_RST_en_emb(data)                                        (0x00010000&((data)<<16))
#define SC_LV_RST_det_ddr2_off(data)                                  (0x00008000&((data)<<15))
#define SC_LV_RST_main_pow_on(data)                                   (0x00004000&((data)<<14))
#define SC_LV_RST_main_por_en(data)                                   (0x00002000&((data)<<13))
#define SC_LV_RST_det_ddr_off(data)                                   (0x00001000&((data)<<12))
#define SC_LV_RST_por_v33set_l(data)                                  (0x00000C00&((data)<<10))
#define SC_LV_RST_por_v11set_l(data)                                  (0x00000300&((data)<<8))
#define SC_LV_RST_por_reser(data)                                     (0x000000F0&((data)<<4))
#define SC_LV_RST_ldov11_sel(data)                                    (0x00000006&((data)<<1))
#define SC_LV_RST_stbldo_pow(data)                                    (0x00000001&(data))
#define SC_LV_RST_get_div_emb(data)                                   ((0x00C00000&(data))>>22)
#define SC_LV_RST_get_cap_emb(data)                                   ((0x00300000&(data))>>20)
#define SC_LV_RST_get_en_emb(data)                                    ((0x00010000&(data))>>16)
#define SC_LV_RST_get_det_ddr2_off(data)                              ((0x00008000&(data))>>15)
#define SC_LV_RST_get_main_pow_on(data)                               ((0x00004000&(data))>>14)
#define SC_LV_RST_get_main_por_en(data)                               ((0x00002000&(data))>>13)
#define SC_LV_RST_get_det_ddr_off(data)                               ((0x00001000&(data))>>12)
#define SC_LV_RST_get_por_v33set_l(data)                              ((0x00000C00&(data))>>10)
#define SC_LV_RST_get_por_v11set_l(data)                              ((0x00000300&(data))>>8)
#define SC_LV_RST_get_por_reser(data)                                 ((0x000000F0&(data))>>4)
#define SC_LV_RST_get_ldov11_sel(data)                                ((0x00000006&(data))>>1)
#define SC_LV_RST_get_stbldo_pow(data)                                (0x00000001&(data))


#define SC_POL                                                        0x18060008
#define SC_POL_reg_addr                                               "0xb8060008"
#define SC_POL_reg                                                    0xb8060008
#define SC_POL_inst_addr                                              "0x0002"
#define SC_POL_inst                                                   0x0002
#define SC_POL_boption_rst_bypass_shift                               (31)
#define SC_POL_boption_efuse_shift                                    (30)
#define SC_POL_boption_debounce_n_shift                               (29)
#define SC_POL_boption_gpu_shift                                      (28)
#define SC_POL_boption_arm_shift                                      (27)
#define SC_POL_boption_6_shift                                        (26)
#define SC_POL_boption_5_shift                                        (25)
#define SC_POL_boption_4_shift                                        (24)
#define SC_POL_boption_3_shift                                        (23)
#define SC_POL_boption_2_shift                                        (22)
#define SC_POL_boption_1_shift                                        (21)
#define SC_POL_boption_0_shift                                        (20)
#define SC_POL_at_speed_pll_done_shift                                (19)
#define SC_POL_porl_host_s_en_n_shift                                 (18)
#define SC_POL_porl_at_speed_scan_shift                               (17)
#define SC_POL_porl_boot_mode_n_shift                                 (16)
#define SC_POL_porl_test_mode_shift                                   (4)
#define SC_POL_porl_test_en_n_shift                                   (3)
#define SC_POL_porl_pll_en_shift                                      (2)
#define SC_POL_porl_ejtag_en_n_shift                                  (1)
#define SC_POL_boption_rst_bypass_mask                                (0x80000000)
#define SC_POL_boption_efuse_mask                                     (0x40000000)
#define SC_POL_boption_debounce_n_mask                                (0x20000000)
#define SC_POL_boption_gpu_mask                                       (0x10000000)
#define SC_POL_boption_arm_mask                                       (0x08000000)
#define SC_POL_boption_6_mask                                         (0x04000000)
#define SC_POL_boption_5_mask                                         (0x02000000)
#define SC_POL_boption_4_mask                                         (0x01000000)
#define SC_POL_boption_3_mask                                         (0x00800000)
#define SC_POL_boption_2_mask                                         (0x00400000)
#define SC_POL_boption_1_mask                                         (0x00200000)
#define SC_POL_boption_0_mask                                         (0x00100000)
#define SC_POL_at_speed_pll_done_mask                                 (0x00080000)
#define SC_POL_porl_host_s_en_n_mask                                  (0x00040000)
#define SC_POL_porl_at_speed_scan_mask                                (0x00020000)
#define SC_POL_porl_boot_mode_n_mask                                  (0x00010000)
#define SC_POL_porl_test_mode_mask                                    (0x000001F0)
#define SC_POL_porl_test_en_n_mask                                    (0x00000008)
#define SC_POL_porl_pll_en_mask                                       (0x00000004)
#define SC_POL_porl_ejtag_en_n_mask                                   (0x00000002)
#define SC_POL_boption_rst_bypass(data)                               (0x80000000&((data)<<31))
#define SC_POL_boption_efuse(data)                                    (0x40000000&((data)<<30))
#define SC_POL_boption_debounce_n(data)                               (0x20000000&((data)<<29))
#define SC_POL_boption_gpu(data)                                      (0x10000000&((data)<<28))
#define SC_POL_boption_arm(data)                                      (0x08000000&((data)<<27))
#define SC_POL_boption_6(data)                                        (0x04000000&((data)<<26))
#define SC_POL_boption_5(data)                                        (0x02000000&((data)<<25))
#define SC_POL_boption_4(data)                                        (0x01000000&((data)<<24))
#define SC_POL_boption_3(data)                                        (0x00800000&((data)<<23))
#define SC_POL_boption_2(data)                                        (0x00400000&((data)<<22))
#define SC_POL_boption_1(data)                                        (0x00200000&((data)<<21))
#define SC_POL_boption_0(data)                                        (0x00100000&((data)<<20))
#define SC_POL_at_speed_pll_done(data)                                (0x00080000&((data)<<19))
#define SC_POL_porl_host_s_en_n(data)                                 (0x00040000&((data)<<18))
#define SC_POL_porl_at_speed_scan(data)                               (0x00020000&((data)<<17))
#define SC_POL_porl_boot_mode_n(data)                                 (0x00010000&((data)<<16))
#define SC_POL_porl_test_mode(data)                                   (0x000001F0&((data)<<4))
#define SC_POL_porl_test_en_n(data)                                   (0x00000008&((data)<<3))
#define SC_POL_porl_pll_en(data)                                      (0x00000004&((data)<<2))
#define SC_POL_porl_ejtag_en_n(data)                                  (0x00000002&((data)<<1))
#define SC_POL_get_boption_rst_bypass(data)                           ((0x80000000&(data))>>31)
#define SC_POL_get_boption_efuse(data)                                ((0x40000000&(data))>>30)
#define SC_POL_get_boption_debounce_n(data)                           ((0x20000000&(data))>>29)
#define SC_POL_get_boption_gpu(data)                                  ((0x10000000&(data))>>28)
#define SC_POL_get_boption_arm(data)                                  ((0x08000000&(data))>>27)
#define SC_POL_get_boption_6(data)                                    ((0x04000000&(data))>>26)
#define SC_POL_get_boption_5(data)                                    ((0x02000000&(data))>>25)
#define SC_POL_get_boption_4(data)                                    ((0x01000000&(data))>>24)
#define SC_POL_get_boption_3(data)                                    ((0x00800000&(data))>>23)
#define SC_POL_get_boption_2(data)                                    ((0x00400000&(data))>>22)
#define SC_POL_get_boption_1(data)                                    ((0x00200000&(data))>>21)
#define SC_POL_get_boption_0(data)                                    ((0x00100000&(data))>>20)
#define SC_POL_get_at_speed_pll_done(data)                            ((0x00080000&(data))>>19)
#define SC_POL_get_porl_host_s_en_n(data)                             ((0x00040000&(data))>>18)
#define SC_POL_get_porl_at_speed_scan(data)                           ((0x00020000&(data))>>17)
#define SC_POL_get_porl_boot_mode_n(data)                             ((0x00010000&(data))>>16)
#define SC_POL_get_porl_test_mode(data)                               ((0x000001F0&(data))>>4)
#define SC_POL_get_porl_test_en_n(data)                               ((0x00000008&(data))>>3)
#define SC_POL_get_porl_pll_en(data)                                  ((0x00000004&(data))>>2)
#define SC_POL_get_porl_ejtag_en_n(data)                              ((0x00000002&(data))>>1)


#define ST_CTRL0                                                      0x18060010
#define ST_CTRL0_reg_addr                                             "0xb8060010"
#define ST_CTRL0_reg                                                  0xb8060010
#define ST_CTRL0_inst_addr                                            "0x0004"
#define ST_CTRL0_inst                                                 0x0004
#define ST_CTRL0_efuse_isln_en_shift                                  (4)
#define ST_CTRL0_ddr_isln_en_shift                                    (3)
#define ST_CTRL0_getn_isln_en_shift                                   (2)
#define ST_CTRL0_rstn_mt_shift                                        (1)
#define ST_CTRL0_mt_isln_en_shift                                     (0)
#define ST_CTRL0_efuse_isln_en_mask                                   (0x00000010)
#define ST_CTRL0_ddr_isln_en_mask                                     (0x00000008)
#define ST_CTRL0_getn_isln_en_mask                                    (0x00000004)
#define ST_CTRL0_rstn_mt_mask                                         (0x00000002)
#define ST_CTRL0_mt_isln_en_mask                                      (0x00000001)
#define ST_CTRL0_efuse_isln_en(data)                                  (0x00000010&((data)<<4))
#define ST_CTRL0_ddr_isln_en(data)                                    (0x00000008&((data)<<3))
#define ST_CTRL0_getn_isln_en(data)                                   (0x00000004&((data)<<2))
#define ST_CTRL0_rstn_mt(data)                                        (0x00000002&((data)<<1))
#define ST_CTRL0_mt_isln_en(data)                                     (0x00000001&(data))
#define ST_CTRL0_get_efuse_isln_en(data)                              ((0x00000010&(data))>>4)
#define ST_CTRL0_get_ddr_isln_en(data)                                ((0x00000008&(data))>>3)
#define ST_CTRL0_get_getn_isln_en(data)                               ((0x00000004&(data))>>2)
#define ST_CTRL0_get_rstn_mt(data)                                    ((0x00000002&(data))>>1)
#define ST_CTRL0_get_mt_isln_en(data)                                 (0x00000001&(data))


#define ST_BISR0                                                      0x18060014
#define ST_BISR0_reg_addr                                             "0xb8060014"
#define ST_BISR0_reg                                                  0xb8060014
#define ST_BISR0_inst_addr                                            "0x0005"
#define ST_BISR0_inst                                                 0x0005
#define ST_BISR0_mcu_imem_bisr_rstn_shift                             (0)
#define ST_BISR0_mcu_imem_bisr_rstn_mask                              (0x00000001)
#define ST_BISR0_mcu_imem_bisr_rstn(data)                             (0x00000001&(data))
#define ST_BISR0_get_mcu_imem_bisr_rstn(data)                         (0x00000001&(data))


#define ST_BISR1                                                      0x18060018
#define ST_BISR1_reg_addr                                             "0xb8060018"
#define ST_BISR1_reg                                                  0xb8060018
#define ST_BISR1_inst_addr                                            "0x0006"
#define ST_BISR1_inst                                                 0x0006
#define ST_BISR1_mcu_imem_bisr_remap_shift                            (0)
#define ST_BISR1_mcu_imem_bisr_remap_mask                             (0x00000001)
#define ST_BISR1_mcu_imem_bisr_remap(data)                            (0x00000001&(data))
#define ST_BISR1_get_mcu_imem_bisr_remap(data)                        (0x00000001&(data))


#define ST_BISR2                                                      0x1806001c
#define ST_BISR2_reg_addr                                             "0xb806001c"
#define ST_BISR2_reg                                                  0xb806001c
#define ST_BISR2_inst_addr                                            "0x0007"
#define ST_BISR2_inst                                                 0x0007
#define ST_BISR2_mcu_imem_bisr_done_shift                             (0)
#define ST_BISR2_mcu_imem_bisr_done_mask                              (0x00000001)
#define ST_BISR2_mcu_imem_bisr_done(data)                             (0x00000001&(data))
#define ST_BISR2_get_mcu_imem_bisr_done(data)                         (0x00000001&(data))


#define ST_SRST0                                                      0x18060030
#define ST_SRST0_reg_addr                                             "0xb8060030"
#define ST_SRST0_reg                                                  0xb8060030
#define ST_SRST0_inst_addr                                            "0x000C"
#define ST_SRST0_inst                                                 0x000C
#define ST_SRST0_rstn_getn_shift                                      (7)
#define ST_SRST0_rstn_i2c0_off_shift                                  (6)
#define ST_SRST0_rstn_uart0_off_shift                                 (5)
#define ST_SRST0_rstn_irda_off_shift                                  (4)
#define ST_SRST0_rstn_pwm_shift                                       (3)
#define ST_SRST0_rstn_pad_mux_shift                                   (2)
#define ST_SRST0_rstn_iso_misc_off_shift                              (1)
#define ST_SRST0_rstn_iso_misc_shift                                  (0)
#define ST_SRST0_rstn_getn_mask                                       (0x00000080)
#define ST_SRST0_rstn_i2c0_off_mask                                   (0x00000040)
#define ST_SRST0_rstn_uart0_off_mask                                  (0x00000020)
#define ST_SRST0_rstn_irda_off_mask                                   (0x00000010)
#define ST_SRST0_rstn_pwm_mask                                        (0x00000008)
#define ST_SRST0_rstn_pad_mux_mask                                    (0x00000004)
#define ST_SRST0_rstn_iso_misc_off_mask                               (0x00000002)
#define ST_SRST0_rstn_iso_misc_mask                                   (0x00000001)
#define ST_SRST0_rstn_getn(data)                                      (0x00000080&((data)<<7))
#define ST_SRST0_rstn_i2c0_off(data)                                  (0x00000040&((data)<<6))
#define ST_SRST0_rstn_uart0_off(data)                                 (0x00000020&((data)<<5))
#define ST_SRST0_rstn_irda_off(data)                                  (0x00000010&((data)<<4))
#define ST_SRST0_rstn_pwm(data)                                       (0x00000008&((data)<<3))
#define ST_SRST0_rstn_pad_mux(data)                                   (0x00000004&((data)<<2))
#define ST_SRST0_rstn_iso_misc_off(data)                              (0x00000002&((data)<<1))
#define ST_SRST0_rstn_iso_misc(data)                                  (0x00000001&(data))
#define ST_SRST0_get_rstn_getn(data)                                  ((0x00000080&(data))>>7)
#define ST_SRST0_get_rstn_i2c0_off(data)                              ((0x00000040&(data))>>6)
#define ST_SRST0_get_rstn_uart0_off(data)                             ((0x00000020&(data))>>5)
#define ST_SRST0_get_rstn_irda_off(data)                              ((0x00000010&(data))>>4)
#define ST_SRST0_get_rstn_pwm(data)                                   ((0x00000008&(data))>>3)
#define ST_SRST0_get_rstn_pad_mux(data)                               ((0x00000004&(data))>>2)
#define ST_SRST0_get_rstn_iso_misc_off(data)                          ((0x00000002&(data))>>1)
#define ST_SRST0_get_rstn_iso_misc(data)                              (0x00000001&(data))


#define ST_SRST1                                                      0x18060034
#define ST_SRST1_reg_addr                                             "0xb8060034"
#define ST_SRST1_reg                                                  0xb8060034
#define ST_SRST1_inst_addr                                            "0x000D"
#define ST_SRST1_inst                                                 0x000D
#define ST_SRST1_rstn_osc_shift                                       (12)
#define ST_SRST1_rstn_rtc_shift                                       (11)
#define ST_SRST1_rstn_emcu_top_shift                                  (10)
#define ST_SRST1_rstn_emcu_core_shift                                 (9)
#define ST_SRST1_rstn_hdmi_det_shift                                  (8)
#define ST_SRST1_rstn_cec_shift                                       (7)
#define ST_SRST1_rstn_syncp_shift                                     (6)
#define ST_SRST1_rstn_cbus_shift                                      (4)
#define ST_SRST1_rstn_alu_shift                                       (3)
#define ST_SRST1_rstn_irda_shift                                      (2)
#define ST_SRST1_rstn_ddc_shift                                       (1)
#define ST_SRST1_rstn_lsadc_shift                                     (0)
#define ST_SRST1_rstn_osc_mask                                        (0x00001000)
#define ST_SRST1_rstn_rtc_mask                                        (0x00000800)
#define ST_SRST1_rstn_emcu_top_mask                                   (0x00000400)
#define ST_SRST1_rstn_emcu_core_mask                                  (0x00000200)
#define ST_SRST1_rstn_hdmi_det_mask                                   (0x00000100)
#define ST_SRST1_rstn_cec_mask                                        (0x00000080)
#define ST_SRST1_rstn_syncp_mask                                      (0x00000040)
#define ST_SRST1_rstn_cbus_mask                                       (0x00000010)
#define ST_SRST1_rstn_alu_mask                                        (0x00000008)
#define ST_SRST1_rstn_irda_mask                                       (0x00000004)
#define ST_SRST1_rstn_ddc_mask                                        (0x00000002)
#define ST_SRST1_rstn_lsadc_mask                                      (0x00000001)
#define ST_SRST1_rstn_osc(data)                                       (0x00001000&((data)<<12))
#define ST_SRST1_rstn_rtc(data)                                       (0x00000800&((data)<<11))
#define ST_SRST1_rstn_emcu_top(data)                                  (0x00000400&((data)<<10))
#define ST_SRST1_rstn_emcu_core(data)                                 (0x00000200&((data)<<9))
#define ST_SRST1_rstn_hdmi_det(data)                                  (0x00000100&((data)<<8))
#define ST_SRST1_rstn_cec(data)                                       (0x00000080&((data)<<7))
#define ST_SRST1_rstn_syncp(data)                                     (0x00000040&((data)<<6))
#define ST_SRST1_rstn_cbus(data)                                      (0x00000010&((data)<<4))
#define ST_SRST1_rstn_alu(data)                                       (0x00000008&((data)<<3))
#define ST_SRST1_rstn_irda(data)                                      (0x00000004&((data)<<2))
#define ST_SRST1_rstn_ddc(data)                                       (0x00000002&((data)<<1))
#define ST_SRST1_rstn_lsadc(data)                                     (0x00000001&(data))
#define ST_SRST1_get_rstn_osc(data)                                   ((0x00001000&(data))>>12)
#define ST_SRST1_get_rstn_rtc(data)                                   ((0x00000800&(data))>>11)
#define ST_SRST1_get_rstn_emcu_top(data)                              ((0x00000400&(data))>>10)
#define ST_SRST1_get_rstn_emcu_core(data)                             ((0x00000200&(data))>>9)
#define ST_SRST1_get_rstn_hdmi_det(data)                              ((0x00000100&(data))>>8)
#define ST_SRST1_get_rstn_cec(data)                                   ((0x00000080&(data))>>7)
#define ST_SRST1_get_rstn_syncp(data)                                 ((0x00000040&(data))>>6)
#define ST_SRST1_get_rstn_cbus(data)                                  ((0x00000010&(data))>>4)
#define ST_SRST1_get_rstn_alu(data)                                   ((0x00000008&(data))>>3)
#define ST_SRST1_get_rstn_irda(data)                                  ((0x00000004&(data))>>2)
#define ST_SRST1_get_rstn_ddc(data)                                   ((0x00000002&(data))>>1)
#define ST_SRST1_get_rstn_lsadc(data)                                 (0x00000001&(data))


#define ST_CLKEN0                                                     0x18060040
#define ST_CLKEN0_reg_addr                                            "0xb8060040"
#define ST_CLKEN0_reg                                                 0xb8060040
#define ST_CLKEN0_inst_addr                                           "0x0010"
#define ST_CLKEN0_inst                                                0x0010
#define ST_CLKEN0_clken_getn_shift                                    (8)
#define ST_CLKEN0_clken_getn_phy_shift                                (7)
#define ST_CLKEN0_clken_i2c0_off_shift                                (6)
#define ST_CLKEN0_clken_uart0_off_shift                               (5)
#define ST_CLKEN0_clken_irda_off_shift                                (4)
#define ST_CLKEN0_clken_pwm_shift                                     (3)
#define ST_CLKEN0_clken_pad_mux_shift                                 (2)
#define ST_CLKEN0_clken_iso_misc_off_shift                            (1)
#define ST_CLKEN0_clken_iso_misc_shift                                (0)
#define ST_CLKEN0_clken_getn_mask                                     (0x00000100)
#define ST_CLKEN0_clken_getn_phy_mask                                 (0x00000080)
#define ST_CLKEN0_clken_i2c0_off_mask                                 (0x00000040)
#define ST_CLKEN0_clken_uart0_off_mask                                (0x00000020)
#define ST_CLKEN0_clken_irda_off_mask                                 (0x00000010)
#define ST_CLKEN0_clken_pwm_mask                                      (0x00000008)
#define ST_CLKEN0_clken_pad_mux_mask                                  (0x00000004)
#define ST_CLKEN0_clken_iso_misc_off_mask                             (0x00000002)
#define ST_CLKEN0_clken_iso_misc_mask                                 (0x00000001)
#define ST_CLKEN0_clken_getn(data)                                    (0x00000100&((data)<<8))
#define ST_CLKEN0_clken_getn_phy(data)                                (0x00000080&((data)<<7))
#define ST_CLKEN0_clken_i2c0_off(data)                                (0x00000040&((data)<<6))
#define ST_CLKEN0_clken_uart0_off(data)                               (0x00000020&((data)<<5))
#define ST_CLKEN0_clken_irda_off(data)                                (0x00000010&((data)<<4))
#define ST_CLKEN0_clken_pwm(data)                                     (0x00000008&((data)<<3))
#define ST_CLKEN0_clken_pad_mux(data)                                 (0x00000004&((data)<<2))
#define ST_CLKEN0_clken_iso_misc_off(data)                            (0x00000002&((data)<<1))
#define ST_CLKEN0_clken_iso_misc(data)                                (0x00000001&(data))
#define ST_CLKEN0_get_clken_getn(data)                                ((0x00000100&(data))>>8)
#define ST_CLKEN0_get_clken_getn_phy(data)                            ((0x00000080&(data))>>7)
#define ST_CLKEN0_get_clken_i2c0_off(data)                            ((0x00000040&(data))>>6)
#define ST_CLKEN0_get_clken_uart0_off(data)                           ((0x00000020&(data))>>5)
#define ST_CLKEN0_get_clken_irda_off(data)                            ((0x00000010&(data))>>4)
#define ST_CLKEN0_get_clken_pwm(data)                                 ((0x00000008&(data))>>3)
#define ST_CLKEN0_get_clken_pad_mux(data)                             ((0x00000004&(data))>>2)
#define ST_CLKEN0_get_clken_iso_misc_off(data)                        ((0x00000002&(data))>>1)
#define ST_CLKEN0_get_clken_iso_misc(data)                            (0x00000001&(data))


#define ST_CLKEN1                                                     0x18060044
#define ST_CLKEN1_reg_addr                                            "0xb8060044"
#define ST_CLKEN1_reg                                                 0xb8060044
#define ST_CLKEN1_inst_addr                                           "0x0011"
#define ST_CLKEN1_inst                                                0x0011
#define ST_CLKEN1_clken_osc_shift                                     (11)
#define ST_CLKEN1_clken_rtc_shift                                     (10)
#define ST_CLKEN1_clken_emcu_core_shift                               (9)
#define ST_CLKEN1_clken_hdmi_det_shift                                (8)
#define ST_CLKEN1_clken_cec_shift                                     (7)
#define ST_CLKEN1_clken_syncp_shift                                   (6)
#define ST_CLKEN1_clken_cbus_shift                                    (4)
#define ST_CLKEN1_clken_alu_shift                                     (3)
#define ST_CLKEN1_clken_irda_shift                                    (2)
#define ST_CLKEN1_clken_ddc_shift                                     (1)
#define ST_CLKEN1_clken_lsadc_shift                                   (0)
#define ST_CLKEN1_clken_osc_mask                                      (0x00000800)
#define ST_CLKEN1_clken_rtc_mask                                      (0x00000400)
#define ST_CLKEN1_clken_emcu_core_mask                                (0x00000200)
#define ST_CLKEN1_clken_hdmi_det_mask                                 (0x00000100)
#define ST_CLKEN1_clken_cec_mask                                      (0x00000080)
#define ST_CLKEN1_clken_syncp_mask                                    (0x00000040)
#define ST_CLKEN1_clken_cbus_mask                                     (0x00000010)
#define ST_CLKEN1_clken_alu_mask                                      (0x00000008)
#define ST_CLKEN1_clken_irda_mask                                     (0x00000004)
#define ST_CLKEN1_clken_ddc_mask                                      (0x00000002)
#define ST_CLKEN1_clken_lsadc_mask                                    (0x00000001)
#define ST_CLKEN1_clken_osc(data)                                     (0x00000800&((data)<<11))
#define ST_CLKEN1_clken_rtc(data)                                     (0x00000400&((data)<<10))
#define ST_CLKEN1_clken_emcu_core(data)                               (0x00000200&((data)<<9))
#define ST_CLKEN1_clken_hdmi_det(data)                                (0x00000100&((data)<<8))
#define ST_CLKEN1_clken_cec(data)                                     (0x00000080&((data)<<7))
#define ST_CLKEN1_clken_syncp(data)                                   (0x00000040&((data)<<6))
#define ST_CLKEN1_clken_cbus(data)                                    (0x00000010&((data)<<4))
#define ST_CLKEN1_clken_alu(data)                                     (0x00000008&((data)<<3))
#define ST_CLKEN1_clken_irda(data)                                    (0x00000004&((data)<<2))
#define ST_CLKEN1_clken_ddc(data)                                     (0x00000002&((data)<<1))
#define ST_CLKEN1_clken_lsadc(data)                                   (0x00000001&(data))
#define ST_CLKEN1_get_clken_osc(data)                                 ((0x00000800&(data))>>11)
#define ST_CLKEN1_get_clken_rtc(data)                                 ((0x00000400&(data))>>10)
#define ST_CLKEN1_get_clken_emcu_core(data)                           ((0x00000200&(data))>>9)
#define ST_CLKEN1_get_clken_hdmi_det(data)                            ((0x00000100&(data))>>8)
#define ST_CLKEN1_get_clken_cec(data)                                 ((0x00000080&(data))>>7)
#define ST_CLKEN1_get_clken_syncp(data)                               ((0x00000040&(data))>>6)
#define ST_CLKEN1_get_clken_cbus(data)                                ((0x00000010&(data))>>4)
#define ST_CLKEN1_get_clken_alu(data)                                 ((0x00000008&(data))>>3)
#define ST_CLKEN1_get_clken_irda(data)                                ((0x00000004&(data))>>2)
#define ST_CLKEN1_get_clken_ddc(data)                                 ((0x00000002&(data))>>1)
#define ST_CLKEN1_get_clken_lsadc(data)                               (0x00000001&(data))


#define ST_BUSCLK                                                     0x18060050
#define ST_BUSCLK_reg_addr                                            "0xb8060050"
#define ST_BUSCLK_reg                                                 0xb8060050
#define ST_BUSCLK_inst_addr                                           "0x0014"
#define ST_BUSCLK_inst                                                0x0014
#define ST_BUSCLK_bus_div_en_shift                                    (18)
#define ST_BUSCLK_bus_div_apply_shift                                 (17)
#define ST_BUSCLK_bus_div_busy_shift                                  (16)
#define ST_BUSCLK_bus_div_sel_shift                                   (12)
#define ST_BUSCLK_bus_clksel_shift                                    (0)
#define ST_BUSCLK_bus_div_en_mask                                     (0x00040000)
#define ST_BUSCLK_bus_div_apply_mask                                  (0x00020000)
#define ST_BUSCLK_bus_div_busy_mask                                   (0x00010000)
#define ST_BUSCLK_bus_div_sel_mask                                    (0x00007000)
#define ST_BUSCLK_bus_clksel_mask                                     (0x00000001)
#define ST_BUSCLK_bus_div_en(data)                                    (0x00040000&((data)<<18))
#define ST_BUSCLK_bus_div_apply(data)                                 (0x00020000&((data)<<17))
#define ST_BUSCLK_bus_div_busy(data)                                  (0x00010000&((data)<<16))
#define ST_BUSCLK_bus_div_sel(data)                                   (0x00007000&((data)<<12))
#define ST_BUSCLK_bus_clksel(data)                                    (0x00000001&(data))
#define ST_BUSCLK_get_bus_div_en(data)                                ((0x00040000&(data))>>18)
#define ST_BUSCLK_get_bus_div_apply(data)                             ((0x00020000&(data))>>17)
#define ST_BUSCLK_get_bus_div_busy(data)                              ((0x00010000&(data))>>16)
#define ST_BUSCLK_get_bus_div_sel(data)                               ((0x00007000&(data))>>12)
#define ST_BUSCLK_get_bus_clksel(data)                                (0x00000001&(data))


#define ST_EMCUCLK                                                    0x18060054
#define ST_EMCUCLK_reg_addr                                           "0xb8060054"
#define ST_EMCUCLK_reg                                                0xb8060054
#define ST_EMCUCLK_inst_addr                                          "0x0015"
#define ST_EMCUCLK_inst                                               0x0015
#define ST_EMCUCLK_emcu_div_en_shift                                  (18)
#define ST_EMCUCLK_emcu_div_apply_shift                               (17)
#define ST_EMCUCLK_emcu_div_busy_shift                                (16)
#define ST_EMCUCLK_emcu_div_sel_shift                                 (12)
#define ST_EMCUCLK_emcu_div_en_mask                                   (0x00040000)
#define ST_EMCUCLK_emcu_div_apply_mask                                (0x00020000)
#define ST_EMCUCLK_emcu_div_busy_mask                                 (0x00010000)
#define ST_EMCUCLK_emcu_div_sel_mask                                  (0x00007000)
#define ST_EMCUCLK_emcu_div_en(data)                                  (0x00040000&((data)<<18))
#define ST_EMCUCLK_emcu_div_apply(data)                               (0x00020000&((data)<<17))
#define ST_EMCUCLK_emcu_div_busy(data)                                (0x00010000&((data)<<16))
#define ST_EMCUCLK_emcu_div_sel(data)                                 (0x00007000&((data)<<12))
#define ST_EMCUCLK_get_emcu_div_en(data)                              ((0x00040000&(data))>>18)
#define ST_EMCUCLK_get_emcu_div_apply(data)                           ((0x00020000&(data))>>17)
#define ST_EMCUCLK_get_emcu_div_busy(data)                            ((0x00010000&(data))>>16)
#define ST_EMCUCLK_get_emcu_div_sel(data)                             ((0x00007000&(data))>>12)


#define ST_CLKMUX                                                     0x18060058
#define ST_CLKMUX_reg_addr                                            "0xb8060058"
#define ST_CLKMUX_reg                                                 0xb8060058
#define ST_CLKMUX_inst_addr                                           "0x0016"
#define ST_CLKMUX_inst                                                0x0016
#define ST_CLKMUX_wow_gmac_clksel_shift                               (3)
#define ST_CLKMUX_wow_clksel_shift                                    (2)
#define ST_CLKMUX_osc_clksel_shift                                    (1)
#define ST_CLKMUX_uart_clksel_shift                                   (0)
#define ST_CLKMUX_wow_gmac_clksel_mask                                (0x00000008)
#define ST_CLKMUX_wow_clksel_mask                                     (0x00000004)
#define ST_CLKMUX_osc_clksel_mask                                     (0x00000002)
#define ST_CLKMUX_uart_clksel_mask                                    (0x00000001)
#define ST_CLKMUX_wow_gmac_clksel(data)                               (0x00000008&((data)<<3))
#define ST_CLKMUX_wow_clksel(data)                                    (0x00000004&((data)<<2))
#define ST_CLKMUX_osc_clksel(data)                                    (0x00000002&((data)<<1))
#define ST_CLKMUX_uart_clksel(data)                                   (0x00000001&(data))
#define ST_CLKMUX_get_wow_gmac_clksel(data)                           ((0x00000008&(data))>>3)
#define ST_CLKMUX_get_wow_clksel(data)                                ((0x00000004&(data))>>2)
#define ST_CLKMUX_get_osc_clksel(data)                                ((0x00000002&(data))>>1)
#define ST_CLKMUX_get_uart_clksel(data)                               (0x00000001&(data))


#define ST_ALU_0                                                      0x1806005c
#define ST_ALU_0_reg_addr                                             "0xb806005c"
#define ST_ALU_0_reg                                                  0xb806005c
#define ST_ALU_0_inst_addr                                            "0x0017"
#define ST_ALU_0_inst                                                 0x0017
#define ST_ALU_0_st2_isln_en_shift                                    (31)
#define ST_ALU_0_st2_wakeup_tim_shift                                 (4)
#define ST_ALU_0_st2_de_iso_ps_tim_shift                              (0)
#define ST_ALU_0_st2_isln_en_mask                                     (0x80000000)
#define ST_ALU_0_st2_wakeup_tim_mask                                  (0x000000F0)
#define ST_ALU_0_st2_de_iso_ps_tim_mask                               (0x0000000F)
#define ST_ALU_0_st2_isln_en(data)                                    (0x80000000&((data)<<31))
#define ST_ALU_0_st2_wakeup_tim(data)                                 (0x000000F0&((data)<<4))
#define ST_ALU_0_st2_de_iso_ps_tim(data)                              (0x0000000F&(data))
#define ST_ALU_0_get_st2_isln_en(data)                                ((0x80000000&(data))>>31)
#define ST_ALU_0_get_st2_wakeup_tim(data)                             ((0x000000F0&(data))>>4)
#define ST_ALU_0_get_st2_de_iso_ps_tim(data)                          (0x0000000F&(data))


#define ALU_IE                                                        0x18060060
#define ALU_IE_reg_addr                                               "0xb8060060"
#define ALU_IE_reg                                                    0xb8060060
#define ALU_IE_inst_addr                                              "0x0018"
#define ALU_IE_inst                                                   0x0018
#define ALU_IE_stie_self_wakeup_shift                                 (4)
#define ALU_IE_stie_rtc_shift                                         (3)
#define ALU_IE_stie_cec_shift                                         (2)
#define ALU_IE_stie_cbus_shift                                        (1)
#define ALU_IE_stie_iso_misc_shift                                    (0)
#define ALU_IE_stie_self_wakeup_mask                                  (0x00000010)
#define ALU_IE_stie_rtc_mask                                          (0x00000008)
#define ALU_IE_stie_cec_mask                                          (0x00000004)
#define ALU_IE_stie_cbus_mask                                         (0x00000002)
#define ALU_IE_stie_iso_misc_mask                                     (0x00000001)
#define ALU_IE_stie_self_wakeup(data)                                 (0x00000010&((data)<<4))
#define ALU_IE_stie_rtc(data)                                         (0x00000008&((data)<<3))
#define ALU_IE_stie_cec(data)                                         (0x00000004&((data)<<2))
#define ALU_IE_stie_cbus(data)                                        (0x00000002&((data)<<1))
#define ALU_IE_stie_iso_misc(data)                                    (0x00000001&(data))
#define ALU_IE_get_stie_self_wakeup(data)                             ((0x00000010&(data))>>4)
#define ALU_IE_get_stie_rtc(data)                                     ((0x00000008&(data))>>3)
#define ALU_IE_get_stie_cec(data)                                     ((0x00000004&(data))>>2)
#define ALU_IE_get_stie_cbus(data)                                    ((0x00000002&(data))>>1)
#define ALU_IE_get_stie_iso_misc(data)                                (0x00000001&(data))


#define ALU_IP                                                        0x18060064
#define ALU_IP_reg_addr                                               "0xb8060064"
#define ALU_IP_reg                                                    0xb8060064
#define ALU_IP_inst_addr                                              "0x0019"
#define ALU_IP_inst                                                   0x0019
#define ALU_IP_stip_self_wakeup_shift                                 (4)
#define ALU_IP_stip_rtc_shift                                         (3)
#define ALU_IP_stip_cec_shift                                         (2)
#define ALU_IP_stip_cbus_shift                                        (1)
#define ALU_IP_stip_iso_misc_shift                                    (0)
#define ALU_IP_stip_self_wakeup_mask                                  (0x00000010)
#define ALU_IP_stip_rtc_mask                                          (0x00000008)
#define ALU_IP_stip_cec_mask                                          (0x00000004)
#define ALU_IP_stip_cbus_mask                                         (0x00000002)
#define ALU_IP_stip_iso_misc_mask                                     (0x00000001)
#define ALU_IP_stip_self_wakeup(data)                                 (0x00000010&((data)<<4))
#define ALU_IP_stip_rtc(data)                                         (0x00000008&((data)<<3))
#define ALU_IP_stip_cec(data)                                         (0x00000004&((data)<<2))
#define ALU_IP_stip_cbus(data)                                        (0x00000002&((data)<<1))
#define ALU_IP_stip_iso_misc(data)                                    (0x00000001&(data))
#define ALU_IP_get_stip_self_wakeup(data)                             ((0x00000010&(data))>>4)
#define ALU_IP_get_stip_rtc(data)                                     ((0x00000008&(data))>>3)
#define ALU_IP_get_stip_cec(data)                                     ((0x00000004&(data))>>2)
#define ALU_IP_get_stip_cbus(data)                                    ((0x00000002&(data))>>1)
#define ALU_IP_get_stip_iso_misc(data)                                (0x00000001&(data))


#define ALU_PASS                                                      0x18060068
#define ALU_PASS_reg_addr                                             "0xb8060068"
#define ALU_PASS_reg                                                  0xb8060068
#define ALU_PASS_inst_addr                                            "0x001A"
#define ALU_PASS_inst                                                 0x001A
#define ALU_PASS_stpass_self_wakeup_shift                             (4)
#define ALU_PASS_stpass_rtc_shift                                     (3)
#define ALU_PASS_stpass_cec_shift                                     (2)
#define ALU_PASS_stpass_cbus_shift                                    (1)
#define ALU_PASS_stpass_iso_misc_shift                                (0)
#define ALU_PASS_stpass_self_wakeup_mask                              (0x00000010)
#define ALU_PASS_stpass_rtc_mask                                      (0x00000008)
#define ALU_PASS_stpass_cec_mask                                      (0x00000004)
#define ALU_PASS_stpass_cbus_mask                                     (0x00000002)
#define ALU_PASS_stpass_iso_misc_mask                                 (0x00000001)
#define ALU_PASS_stpass_self_wakeup(data)                             (0x00000010&((data)<<4))
#define ALU_PASS_stpass_rtc(data)                                     (0x00000008&((data)<<3))
#define ALU_PASS_stpass_cec(data)                                     (0x00000004&((data)<<2))
#define ALU_PASS_stpass_cbus(data)                                    (0x00000002&((data)<<1))
#define ALU_PASS_stpass_iso_misc(data)                                (0x00000001&(data))
#define ALU_PASS_get_stpass_self_wakeup(data)                         ((0x00000010&(data))>>4)
#define ALU_PASS_get_stpass_rtc(data)                                 ((0x00000008&(data))>>3)
#define ALU_PASS_get_stpass_cec(data)                                 ((0x00000004&(data))>>2)
#define ALU_PASS_get_stpass_cbus(data)                                ((0x00000002&(data))>>1)
#define ALU_PASS_get_stpass_iso_misc(data)                            (0x00000001&(data))


#define STB_IRQ_ALL                                                   0x1806006c
#define STB_IRQ_ALL_reg_addr                                          "0xb806006c"
#define STB_IRQ_ALL_reg                                               0xb806006c
#define STB_IRQ_ALL_inst_addr                                         "0x001B"
#define STB_IRQ_ALL_inst                                              0x001B
#define STB_IRQ_ALL_rtc_scpu_ie_shift                                 (6)
#define STB_IRQ_ALL_cec_scpu_ie_shift                                 (5)
#define STB_IRQ_ALL_cbus_scpu_ie_shift                                (4)
#define STB_IRQ_ALL_hdmi_clk_det_scpu_ie_shift                        (3)
#define STB_IRQ_ALL_syncp_scpu_ie_shift                               (2)
#define STB_IRQ_ALL_iso_misc_off_scpu_ie_shift                        (1)
#define STB_IRQ_ALL_iso_misc_scpu_ie_shift                            (0)
#define STB_IRQ_ALL_rtc_scpu_ie_mask                                  (0x00000040)
#define STB_IRQ_ALL_cec_scpu_ie_mask                                  (0x00000020)
#define STB_IRQ_ALL_cbus_scpu_ie_mask                                 (0x00000010)
#define STB_IRQ_ALL_hdmi_clk_det_scpu_ie_mask                         (0x00000008)
#define STB_IRQ_ALL_syncp_scpu_ie_mask                                (0x00000004)
#define STB_IRQ_ALL_iso_misc_off_scpu_ie_mask                         (0x00000002)
#define STB_IRQ_ALL_iso_misc_scpu_ie_mask                             (0x00000001)
#define STB_IRQ_ALL_rtc_scpu_ie(data)                                 (0x00000040&((data)<<6))
#define STB_IRQ_ALL_cec_scpu_ie(data)                                 (0x00000020&((data)<<5))
#define STB_IRQ_ALL_cbus_scpu_ie(data)                                (0x00000010&((data)<<4))
#define STB_IRQ_ALL_hdmi_clk_det_scpu_ie(data)                        (0x00000008&((data)<<3))
#define STB_IRQ_ALL_syncp_scpu_ie(data)                               (0x00000004&((data)<<2))
#define STB_IRQ_ALL_iso_misc_off_scpu_ie(data)                        (0x00000002&((data)<<1))
#define STB_IRQ_ALL_iso_misc_scpu_ie(data)                            (0x00000001&(data))
#define STB_IRQ_ALL_get_rtc_scpu_ie(data)                             ((0x00000040&(data))>>6)
#define STB_IRQ_ALL_get_cec_scpu_ie(data)                             ((0x00000020&(data))>>5)
#define STB_IRQ_ALL_get_cbus_scpu_ie(data)                            ((0x00000010&(data))>>4)
#define STB_IRQ_ALL_get_hdmi_clk_det_scpu_ie(data)                    ((0x00000008&(data))>>3)
#define STB_IRQ_ALL_get_syncp_scpu_ie(data)                           ((0x00000004&(data))>>2)
#define STB_IRQ_ALL_get_iso_misc_off_scpu_ie(data)                    ((0x00000002&(data))>>1)
#define STB_IRQ_ALL_get_iso_misc_scpu_ie(data)                        (0x00000001&(data))


#define ST_RING_OSC_0                                                 0x180600e4
#define ST_RING_OSC_0_reg_addr                                        "0xb80600e4"
#define ST_RING_OSC_0_reg                                             0xb80600e4
#define ST_RING_OSC_0_inst_addr                                       "0x0039"
#define ST_RING_OSC_0_inst                                            0x0039
#define ST_RING_OSC_0_osc_sw_s_shift                                  (16)
#define ST_RING_OSC_0_osc_status_shift                                (12)
#define ST_RING_OSC_0_osc_cnt_diff_shift                              (4)
#define ST_RING_OSC_0_osc_rstb_emb_shift                              (2)
#define ST_RING_OSC_0_osc_tracking_mode_shift                         (1)
#define ST_RING_OSC_0_osc_tracking_en_shift                           (0)
#define ST_RING_OSC_0_osc_sw_s_mask                                   (0x007F0000)
#define ST_RING_OSC_0_osc_status_mask                                 (0x00003000)
#define ST_RING_OSC_0_osc_cnt_diff_mask                               (0x00000FF0)
#define ST_RING_OSC_0_osc_rstb_emb_mask                               (0x00000004)
#define ST_RING_OSC_0_osc_tracking_mode_mask                          (0x00000002)
#define ST_RING_OSC_0_osc_tracking_en_mask                            (0x00000001)
#define ST_RING_OSC_0_osc_sw_s(data)                                  (0x007F0000&((data)<<16))
#define ST_RING_OSC_0_osc_status(data)                                (0x00003000&((data)<<12))
#define ST_RING_OSC_0_osc_cnt_diff(data)                              (0x00000FF0&((data)<<4))
#define ST_RING_OSC_0_osc_rstb_emb(data)                              (0x00000004&((data)<<2))
#define ST_RING_OSC_0_osc_tracking_mode(data)                         (0x00000002&((data)<<1))
#define ST_RING_OSC_0_osc_tracking_en(data)                           (0x00000001&(data))
#define ST_RING_OSC_0_get_osc_sw_s(data)                              ((0x007F0000&(data))>>16)
#define ST_RING_OSC_0_get_osc_status(data)                            ((0x00003000&(data))>>12)
#define ST_RING_OSC_0_get_osc_cnt_diff(data)                          ((0x00000FF0&(data))>>4)
#define ST_RING_OSC_0_get_osc_rstb_emb(data)                          ((0x00000004&(data))>>2)
#define ST_RING_OSC_0_get_osc_tracking_mode(data)                     ((0x00000002&(data))>>1)
#define ST_RING_OSC_0_get_osc_tracking_en(data)                       (0x00000001&(data))


#define ST_RING_OSC_1                                                 0x180600e8
#define ST_RING_OSC_1_reg_addr                                        "0xb80600e8"
#define ST_RING_OSC_1_reg                                             0xb80600e8
#define ST_RING_OSC_1_inst_addr                                       "0x003A"
#define ST_RING_OSC_1_inst                                            0x003A
#define ST_RING_OSC_1_s_emb_shift                                     (12)
#define ST_RING_OSC_1_dummy180600e8_11_9_shift                        (9)
#define ST_RING_OSC_1_osc_cnt_diff_max_clr_shift                      (8)
#define ST_RING_OSC_1_osc_cnt_diff_max_shift                          (0)
#define ST_RING_OSC_1_s_emb_mask                                      (0x0007F000)
#define ST_RING_OSC_1_dummy180600e8_11_9_mask                         (0x00000E00)
#define ST_RING_OSC_1_osc_cnt_diff_max_clr_mask                       (0x00000100)
#define ST_RING_OSC_1_osc_cnt_diff_max_mask                           (0x000000FF)
#define ST_RING_OSC_1_s_emb(data)                                     (0x0007F000&((data)<<12))
#define ST_RING_OSC_1_dummy180600e8_11_9(data)                        (0x00000E00&((data)<<9))
#define ST_RING_OSC_1_osc_cnt_diff_max_clr(data)                      (0x00000100&((data)<<8))
#define ST_RING_OSC_1_osc_cnt_diff_max(data)                          (0x000000FF&(data))
#define ST_RING_OSC_1_get_s_emb(data)                                 ((0x0007F000&(data))>>12)
#define ST_RING_OSC_1_get_dummy180600e8_11_9(data)                    ((0x00000E00&(data))>>9)
#define ST_RING_OSC_1_get_osc_cnt_diff_max_clr(data)                  ((0x00000100&(data))>>8)
#define ST_RING_OSC_1_get_osc_cnt_diff_max(data)                      (0x000000FF&(data))


#define ST_DBG_1                                                      0x180600f0
#define ST_DBG_1_reg_addr                                             "0xb80600f0"
#define ST_DBG_1_reg                                                  0xb80600f0
#define ST_DBG_1_inst_addr                                            "0x003C"
#define ST_DBG_1_inst                                                 0x003C
#define ST_DBG_1_alu_test_mode_en_shift                               (27)
#define ST_DBG_1_alu_dbg_sel_shift                                    (20)
#define ST_DBG_1_crt_dbg_sel_shift                                    (16)
#define ST_DBG_1_dbg_div_sel_shift                                    (0)
#define ST_DBG_1_alu_test_mode_en_mask                                (0x08000000)
#define ST_DBG_1_alu_dbg_sel_mask                                     (0x07F00000)
#define ST_DBG_1_crt_dbg_sel_mask                                     (0x000F0000)
#define ST_DBG_1_dbg_div_sel_mask                                     (0x00000003)
#define ST_DBG_1_alu_test_mode_en(data)                               (0x08000000&((data)<<27))
#define ST_DBG_1_alu_dbg_sel(data)                                    (0x07F00000&((data)<<20))
#define ST_DBG_1_crt_dbg_sel(data)                                    (0x000F0000&((data)<<16))
#define ST_DBG_1_dbg_div_sel(data)                                    (0x00000003&(data))
#define ST_DBG_1_get_alu_test_mode_en(data)                           ((0x08000000&(data))>>27)
#define ST_DBG_1_get_alu_dbg_sel(data)                                ((0x07F00000&(data))>>20)
#define ST_DBG_1_get_crt_dbg_sel(data)                                ((0x000F0000&(data))>>16)
#define ST_DBG_1_get_dbg_div_sel(data)                                (0x00000003&(data))


#define WDOG_DATA1                                                    0x18060100
#define WDOG_DATA1_reg_addr                                           "0xb8060100"
#define WDOG_DATA1_reg                                                0xb8060100
#define WDOG_DATA1_inst_addr                                          "0x0040"
#define WDOG_DATA1_inst                                               0x0040
#define WDOG_DATA1_wdog_data1_shift                                   (0)
#define WDOG_DATA1_wdog_data1_mask                                    (0xFFFFFFFF)
#define WDOG_DATA1_wdog_data1(data)                                   (0xFFFFFFFF&(data))
#define WDOG_DATA1_get_wdog_data1(data)                               (0xFFFFFFFF&(data))


#define WDOG_DATA2                                                    0x18060104
#define WDOG_DATA2_reg_addr                                           "0xb8060104"
#define WDOG_DATA2_reg                                                0xb8060104
#define WDOG_DATA2_inst_addr                                          "0x0041"
#define WDOG_DATA2_inst                                               0x0041
#define WDOG_DATA2_wdog_data2_shift                                   (0)
#define WDOG_DATA2_wdog_data2_mask                                    (0xFFFFFFFF)
#define WDOG_DATA2_wdog_data2(data)                                   (0xFFFFFFFF&(data))
#define WDOG_DATA2_get_wdog_data2(data)                               (0xFFFFFFFF&(data))


#define WDOG_DATA3                                                    0x18060108
#define WDOG_DATA3_reg_addr                                           "0xb8060108"
#define WDOG_DATA3_reg                                                0xb8060108
#define WDOG_DATA3_inst_addr                                          "0x0042"
#define WDOG_DATA3_inst                                               0x0042
#define WDOG_DATA3_wdog_data3_shift                                   (0)
#define WDOG_DATA3_wdog_data3_mask                                    (0xFFFFFFFF)
#define WDOG_DATA3_wdog_data3(data)                                   (0xFFFFFFFF&(data))
#define WDOG_DATA3_get_wdog_data3(data)                               (0xFFFFFFFF&(data))


#define WDOG_DATA4                                                    0x1806010c
#define WDOG_DATA4_reg_addr                                           "0xb806010c"
#define WDOG_DATA4_reg                                                0xb806010c
#define WDOG_DATA4_inst_addr                                          "0x0043"
#define WDOG_DATA4_inst                                               0x0043
#define WDOG_DATA4_wdog_data4_shift                                   (0)
#define WDOG_DATA4_wdog_data4_mask                                    (0xFFFFFFFF)
#define WDOG_DATA4_wdog_data4(data)                                   (0xFFFFFFFF&(data))
#define WDOG_DATA4_get_wdog_data4(data)                               (0xFFFFFFFF&(data))


#define WDOG_DATA5                                                    0x18060110
#define WDOG_DATA5_reg_addr                                           "0xb8060110"
#define WDOG_DATA5_reg                                                0xb8060110
#define WDOG_DATA5_inst_addr                                          "0x0044"
#define WDOG_DATA5_inst                                               0x0044
#define WDOG_DATA5_wdog_data5_shift                                   (0)
#define WDOG_DATA5_wdog_data5_mask                                    (0xFFFFFFFF)
#define WDOG_DATA5_wdog_data5(data)                                   (0xFFFFFFFF&(data))
#define WDOG_DATA5_get_wdog_data5(data)                               (0xFFFFFFFF&(data))


#define WDOG_DATA6                                                    0x18060114
#define WDOG_DATA6_reg_addr                                           "0xb8060114"
#define WDOG_DATA6_reg                                                0xb8060114
#define WDOG_DATA6_inst_addr                                          "0x0045"
#define WDOG_DATA6_inst                                               0x0045
#define WDOG_DATA6_wdog_data6_shift                                   (0)
#define WDOG_DATA6_wdog_data6_mask                                    (0xFFFFFFFF)
#define WDOG_DATA6_wdog_data6(data)                                   (0xFFFFFFFF&(data))
#define WDOG_DATA6_get_wdog_data6(data)                               (0xFFFFFFFF&(data))


#define WDOG_DATA7                                                    0x18060118
#define WDOG_DATA7_reg_addr                                           "0xb8060118"
#define WDOG_DATA7_reg                                                0xb8060118
#define WDOG_DATA7_inst_addr                                          "0x0046"
#define WDOG_DATA7_inst                                               0x0046
#define WDOG_DATA7_wdog_data7_shift                                   (0)
#define WDOG_DATA7_wdog_data7_mask                                    (0xFFFFFFFF)
#define WDOG_DATA7_wdog_data7(data)                                   (0xFFFFFFFF&(data))
#define WDOG_DATA7_get_wdog_data7(data)                               (0xFFFFFFFF&(data))


#define WDOG_DATA8                                                    0x1806011c
#define WDOG_DATA8_reg_addr                                           "0xb806011c"
#define WDOG_DATA8_reg                                                0xb806011c
#define WDOG_DATA8_inst_addr                                          "0x0047"
#define WDOG_DATA8_inst                                               0x0047
#define WDOG_DATA8_wdog_data8_shift                                   (0)
#define WDOG_DATA8_wdog_data8_mask                                    (0xFFFFFFFF)
#define WDOG_DATA8_wdog_data8(data)                                   (0xFFFFFFFF&(data))
#define WDOG_DATA8_get_wdog_data8(data)                               (0xFFFFFFFF&(data))


#define WDOG_DATA9                                                    0x18060120
#define WDOG_DATA9_reg_addr                                           "0xb8060120"
#define WDOG_DATA9_reg                                                0xb8060120
#define WDOG_DATA9_inst_addr                                          "0x0048"
#define WDOG_DATA9_inst                                               0x0048
#define WDOG_DATA9_wdog_data9_shift                                   (0)
#define WDOG_DATA9_wdog_data9_mask                                    (0xFFFFFFFF)
#define WDOG_DATA9_wdog_data9(data)                                   (0xFFFFFFFF&(data))
#define WDOG_DATA9_get_wdog_data9(data)                               (0xFFFFFFFF&(data))


#define WDOG_DATA10                                                   0x18060124
#define WDOG_DATA10_reg_addr                                          "0xb8060124"
#define WDOG_DATA10_reg                                               0xb8060124
#define WDOG_DATA10_inst_addr                                         "0x0049"
#define WDOG_DATA10_inst                                              0x0049
#define WDOG_DATA10_wdog_data10_shift                                 (0)
#define WDOG_DATA10_wdog_data10_mask                                  (0xFFFFFFFF)
#define WDOG_DATA10_wdog_data10(data)                                 (0xFFFFFFFF&(data))
#define WDOG_DATA10_get_wdog_data10(data)                             (0xFFFFFFFF&(data))


#define WDOG_DATA11                                                   0x18060128
#define WDOG_DATA11_reg_addr                                          "0xb8060128"
#define WDOG_DATA11_reg                                               0xb8060128
#define WDOG_DATA11_inst_addr                                         "0x004A"
#define WDOG_DATA11_inst                                              0x004A
#define WDOG_DATA11_wdog_data11_shift                                 (0)
#define WDOG_DATA11_wdog_data11_mask                                  (0xFFFFFFFF)
#define WDOG_DATA11_wdog_data11(data)                                 (0xFFFFFFFF&(data))
#define WDOG_DATA11_get_wdog_data11(data)                             (0xFFFFFFFF&(data))


#define WDOG_DATA12                                                   0x1806012c
#define WDOG_DATA12_reg_addr                                          "0xb806012c"
#define WDOG_DATA12_reg                                               0xb806012c
#define WDOG_DATA12_inst_addr                                         "0x004B"
#define WDOG_DATA12_inst                                              0x004B
#define WDOG_DATA12_wdog_data12_shift                                 (0)
#define WDOG_DATA12_wdog_data12_mask                                  (0xFFFFFFFF)
#define WDOG_DATA12_wdog_data12(data)                                 (0xFFFFFFFF&(data))
#define WDOG_DATA12_get_wdog_data12(data)                             (0xFFFFFFFF&(data))


#define SYS_SRST0                                                     0x18000100
#define SYS_SRST0_reg_addr                                            "0xb8000100"
#define SYS_SRST0_reg                                                 0xb8000100
#define SYS_SRST0_inst_addr                                           "0x0040"
#define SYS_SRST0_inst                                                0x0040
#define SYS_SRST0_rstn_vde2_shift                                     (10)
#define SYS_SRST0_rstn_ve2_p2_shift                                   (9)
#define SYS_SRST0_rstn_ve2_shift                                      (8)
#define SYS_SRST0_rstn_vcpu2_shift                                    (7)
#define SYS_SRST0_rstn_vde_shift                                      (6)
#define SYS_SRST0_rstn_ve_p2_shift                                    (5)
#define SYS_SRST0_rstn_ve_shift                                       (4)
#define SYS_SRST0_rstn_vcpu_shift                                     (3)
#define SYS_SRST0_rstn_ae_shift                                       (2)
#define SYS_SRST0_rstn_scpu_shift                                     (1)
#define SYS_SRST0_rstn_pllreg_shift                                   (0)
#define SYS_SRST0_rstn_vde2_mask                                      (0x00000400)
#define SYS_SRST0_rstn_ve2_p2_mask                                    (0x00000200)
#define SYS_SRST0_rstn_ve2_mask                                       (0x00000100)
#define SYS_SRST0_rstn_vcpu2_mask                                     (0x00000080)
#define SYS_SRST0_rstn_vde_mask                                       (0x00000040)
#define SYS_SRST0_rstn_ve_p2_mask                                     (0x00000020)
#define SYS_SRST0_rstn_ve_mask                                        (0x00000010)
#define SYS_SRST0_rstn_vcpu_mask                                      (0x00000008)
#define SYS_SRST0_rstn_ae_mask                                        (0x00000004)
#define SYS_SRST0_rstn_scpu_mask                                      (0x00000002)
#define SYS_SRST0_rstn_pllreg_mask                                    (0x00000001)
#define SYS_SRST0_rstn_vde2(data)                                     (0x00000400&((data)<<10))
#define SYS_SRST0_rstn_ve2_p2(data)                                   (0x00000200&((data)<<9))
#define SYS_SRST0_rstn_ve2(data)                                      (0x00000100&((data)<<8))
#define SYS_SRST0_rstn_vcpu2(data)                                    (0x00000080&((data)<<7))
#define SYS_SRST0_rstn_vde(data)                                      (0x00000040&((data)<<6))
#define SYS_SRST0_rstn_ve_p2(data)                                    (0x00000020&((data)<<5))
#define SYS_SRST0_rstn_ve(data)                                       (0x00000010&((data)<<4))
#define SYS_SRST0_rstn_vcpu(data)                                     (0x00000008&((data)<<3))
#define SYS_SRST0_rstn_ae(data)                                       (0x00000004&((data)<<2))
#define SYS_SRST0_rstn_scpu(data)                                     (0x00000002&((data)<<1))
#define SYS_SRST0_rstn_pllreg(data)                                   (0x00000001&(data))
#define SYS_SRST0_get_rstn_vde2(data)                                 ((0x00000400&(data))>>10)
#define SYS_SRST0_get_rstn_ve2_p2(data)                               ((0x00000200&(data))>>9)
#define SYS_SRST0_get_rstn_ve2(data)                                  ((0x00000100&(data))>>8)
#define SYS_SRST0_get_rstn_vcpu2(data)                                ((0x00000080&(data))>>7)
#define SYS_SRST0_get_rstn_vde(data)                                  ((0x00000040&(data))>>6)
#define SYS_SRST0_get_rstn_ve_p2(data)                                ((0x00000020&(data))>>5)
#define SYS_SRST0_get_rstn_ve(data)                                   ((0x00000010&(data))>>4)
#define SYS_SRST0_get_rstn_vcpu(data)                                 ((0x00000008&(data))>>3)
#define SYS_SRST0_get_rstn_ae(data)                                   ((0x00000004&(data))>>2)
#define SYS_SRST0_get_rstn_scpu(data)                                 ((0x00000002&(data))>>1)
#define SYS_SRST0_get_rstn_pllreg(data)                               (0x00000001&(data))


#define SYS_SRST1                                                     0x18000104
#define SYS_SRST1_reg_addr                                            "0xb8000104"
#define SYS_SRST1_reg                                                 0xb8000104
#define SYS_SRST1_inst_addr                                           "0x0041"
#define SYS_SRST1_inst                                                0x0041
#define SYS_SRST1_rstn_tvsb1_shift                                    (31)
#define SYS_SRST1_rstn_tvsb2_shift                                    (30)
#define SYS_SRST1_rstn_tvsb3_shift                                    (29)
#define SYS_SRST1_rstn_tvsb2_dc2_shift                                (28)
#define SYS_SRST1_rstn_tvsb3_dc2_shift                                (27)
#define SYS_SRST1_rstn_dcphy_shift                                    (25)
#define SYS_SRST1_rstn_dcu_shift                                      (24)
#define SYS_SRST1_rstn_if_demod_shift                                 (23)
#define SYS_SRST1_rstn_vdec_shift                                     (22)
#define SYS_SRST1_rstn_vdec2_shift                                    (21)
#define SYS_SRST1_rstn_vbis0_shift                                    (20)
#define SYS_SRST1_rstn_audio2_dac_shift                               (19)
#define SYS_SRST1_rstn_audio_adc_shift                                (18)
#define SYS_SRST1_rstn_audio_dac_shift                                (17)
#define SYS_SRST1_rstn_audio_shift                                    (16)
#define SYS_SRST1_rstn_ifadc_shift                                    (15)
#define SYS_SRST1_rstn_me_shift                                       (12)
#define SYS_SRST1_rstn_apll_adc_shift                                 (11)
#define SYS_SRST1_rstn_hdmi_shift                                     (10)
#define SYS_SRST1_rstn_tp_shift                                       (8)
#define SYS_SRST1_rstn_cp_shift                                       (7)
#define SYS_SRST1_rstn_md_shift                                       (6)
#define SYS_SRST1_rstn_se_shift                                       (5)
#define SYS_SRST1_rstn_3d_gde_shift                                   (3)
#define SYS_SRST1_rstn_vodma_shift                                    (2)
#define SYS_SRST1_rstn_dispim_shift                                   (1)
#define SYS_SRST1_rstn_disp_shift                                     (0)
#define SYS_SRST1_rstn_tvsb1_mask                                     (0x80000000)
#define SYS_SRST1_rstn_tvsb2_mask                                     (0x40000000)
#define SYS_SRST1_rstn_tvsb3_mask                                     (0x20000000)
#define SYS_SRST1_rstn_tvsb2_dc2_mask                                 (0x10000000)
#define SYS_SRST1_rstn_tvsb3_dc2_mask                                 (0x08000000)
#define SYS_SRST1_rstn_dcphy_mask                                     (0x02000000)
#define SYS_SRST1_rstn_dcu_mask                                       (0x01000000)
#define SYS_SRST1_rstn_if_demod_mask                                  (0x00800000)
#define SYS_SRST1_rstn_vdec_mask                                      (0x00400000)
#define SYS_SRST1_rstn_vdec2_mask                                     (0x00200000)
#define SYS_SRST1_rstn_vbis0_mask                                     (0x00100000)
#define SYS_SRST1_rstn_audio2_dac_mask                                (0x00080000)
#define SYS_SRST1_rstn_audio_adc_mask                                 (0x00040000)
#define SYS_SRST1_rstn_audio_dac_mask                                 (0x00020000)
#define SYS_SRST1_rstn_audio_mask                                     (0x00010000)
#define SYS_SRST1_rstn_ifadc_mask                                     (0x00008000)
#define SYS_SRST1_rstn_me_mask                                        (0x00001000)
#define SYS_SRST1_rstn_apll_adc_mask                                  (0x00000800)
#define SYS_SRST1_rstn_hdmi_mask                                      (0x00000400)
#define SYS_SRST1_rstn_tp_mask                                        (0x00000100)
#define SYS_SRST1_rstn_cp_mask                                        (0x00000080)
#define SYS_SRST1_rstn_md_mask                                        (0x00000040)
#define SYS_SRST1_rstn_se_mask                                        (0x00000020)
#define SYS_SRST1_rstn_3d_gde_mask                                    (0x00000008)
#define SYS_SRST1_rstn_vodma_mask                                     (0x00000004)
#define SYS_SRST1_rstn_dispim_mask                                    (0x00000002)
#define SYS_SRST1_rstn_disp_mask                                      (0x00000001)
#define SYS_SRST1_rstn_tvsb1(data)                                    (0x80000000&((data)<<31))
#define SYS_SRST1_rstn_tvsb2(data)                                    (0x40000000&((data)<<30))
#define SYS_SRST1_rstn_tvsb3(data)                                    (0x20000000&((data)<<29))
#define SYS_SRST1_rstn_tvsb2_dc2(data)                                (0x10000000&((data)<<28))
#define SYS_SRST1_rstn_tvsb3_dc2(data)                                (0x08000000&((data)<<27))
#define SYS_SRST1_rstn_dcphy(data)                                    (0x02000000&((data)<<25))
#define SYS_SRST1_rstn_dcu(data)                                      (0x01000000&((data)<<24))
#define SYS_SRST1_rstn_if_demod(data)                                 (0x00800000&((data)<<23))
#define SYS_SRST1_rstn_vdec(data)                                     (0x00400000&((data)<<22))
#define SYS_SRST1_rstn_vdec2(data)                                    (0x00200000&((data)<<21))
#define SYS_SRST1_rstn_vbis0(data)                                    (0x00100000&((data)<<20))
#define SYS_SRST1_rstn_audio2_dac(data)                               (0x00080000&((data)<<19))
#define SYS_SRST1_rstn_audio_adc(data)                                (0x00040000&((data)<<18))
#define SYS_SRST1_rstn_audio_dac(data)                                (0x00020000&((data)<<17))
#define SYS_SRST1_rstn_audio(data)                                    (0x00010000&((data)<<16))
#define SYS_SRST1_rstn_ifadc(data)                                    (0x00008000&((data)<<15))
#define SYS_SRST1_rstn_me(data)                                       (0x00001000&((data)<<12))
#define SYS_SRST1_rstn_apll_adc(data)                                 (0x00000800&((data)<<11))
#define SYS_SRST1_rstn_hdmi(data)                                     (0x00000400&((data)<<10))
#define SYS_SRST1_rstn_tp(data)                                       (0x00000100&((data)<<8))
#define SYS_SRST1_rstn_cp(data)                                       (0x00000080&((data)<<7))
#define SYS_SRST1_rstn_md(data)                                       (0x00000040&((data)<<6))
#define SYS_SRST1_rstn_se(data)                                       (0x00000020&((data)<<5))
#define SYS_SRST1_rstn_3d_gde(data)                                   (0x00000008&((data)<<3))
#define SYS_SRST1_rstn_vodma(data)                                    (0x00000004&((data)<<2))
#define SYS_SRST1_rstn_dispim(data)                                   (0x00000002&((data)<<1))
#define SYS_SRST1_rstn_disp(data)                                     (0x00000001&(data))
#define SYS_SRST1_get_rstn_tvsb1(data)                                ((0x80000000&(data))>>31)
#define SYS_SRST1_get_rstn_tvsb2(data)                                ((0x40000000&(data))>>30)
#define SYS_SRST1_get_rstn_tvsb3(data)                                ((0x20000000&(data))>>29)
#define SYS_SRST1_get_rstn_tvsb2_dc2(data)                            ((0x10000000&(data))>>28)
#define SYS_SRST1_get_rstn_tvsb3_dc2(data)                            ((0x08000000&(data))>>27)
#define SYS_SRST1_get_rstn_dcphy(data)                                ((0x02000000&(data))>>25)
#define SYS_SRST1_get_rstn_dcu(data)                                  ((0x01000000&(data))>>24)
#define SYS_SRST1_get_rstn_if_demod(data)                             ((0x00800000&(data))>>23)
#define SYS_SRST1_get_rstn_vdec(data)                                 ((0x00400000&(data))>>22)
#define SYS_SRST1_get_rstn_vdec2(data)                                ((0x00200000&(data))>>21)
#define SYS_SRST1_get_rstn_vbis0(data)                                ((0x00100000&(data))>>20)
#define SYS_SRST1_get_rstn_audio2_dac(data)                           ((0x00080000&(data))>>19)
#define SYS_SRST1_get_rstn_audio_adc(data)                            ((0x00040000&(data))>>18)
#define SYS_SRST1_get_rstn_audio_dac(data)                            ((0x00020000&(data))>>17)
#define SYS_SRST1_get_rstn_audio(data)                                ((0x00010000&(data))>>16)
#define SYS_SRST1_get_rstn_ifadc(data)                                ((0x00008000&(data))>>15)
#define SYS_SRST1_get_rstn_me(data)                                   ((0x00001000&(data))>>12)
#define SYS_SRST1_get_rstn_apll_adc(data)                             ((0x00000800&(data))>>11)
#define SYS_SRST1_get_rstn_hdmi(data)                                 ((0x00000400&(data))>>10)
#define SYS_SRST1_get_rstn_tp(data)                                   ((0x00000100&(data))>>8)
#define SYS_SRST1_get_rstn_cp(data)                                   ((0x00000080&(data))>>7)
#define SYS_SRST1_get_rstn_md(data)                                   ((0x00000040&(data))>>6)
#define SYS_SRST1_get_rstn_se(data)                                   ((0x00000020&(data))>>5)
#define SYS_SRST1_get_rstn_3d_gde(data)                               ((0x00000008&(data))>>3)
#define SYS_SRST1_get_rstn_vodma(data)                                ((0x00000004&(data))>>2)
#define SYS_SRST1_get_rstn_dispim(data)                               ((0x00000002&(data))>>1)
#define SYS_SRST1_get_rstn_disp(data)                                 (0x00000001&(data))


#define SYS_SRST2                                                     0x18000108
#define SYS_SRST2_reg_addr                                            "0xb8000108"
#define SYS_SRST2_reg                                                 0xb8000108
#define SYS_SRST2_inst_addr                                           "0x0042"
#define SYS_SRST2_inst                                                0x0042
#define SYS_SRST2_rstn_tm_shift                                       (28)
#define SYS_SRST2_rstn_atvin2_shift                                   (27)
#define SYS_SRST2_rstn_atvin_shift                                    (26)
#define SYS_SRST2_rstn_osdcmp_shift                                   (25)
#define SYS_SRST2_rstn_etn_shift                                      (24)
#define SYS_SRST2_rstn_cr_shift                                       (23)
#define SYS_SRST2_rstn_bistreg_shift                                  (21)
#define SYS_SRST2_rstn_usb_arb_shift                                  (20)
#define SYS_SRST2_dummy18000108_19_shift                              (19)
#define SYS_SRST2_rstn_usb3_mac_shift                                 (18)
#define SYS_SRST2_dummy18000108_17_shift                              (17)
#define SYS_SRST2_dummy18000108_15_13_shift                           (13)
#define SYS_SRST2_rstn_padmux_shift                                   (12)
#define SYS_SRST2_rstn_dtv_demod_shift                                (11)
#define SYS_SRST2_rstn_misc_shift                                     (10)
#define SYS_SRST2_rstn_pwm_shift                                      (9)
#define SYS_SRST2_rstn_uart1_shift                                    (8)
#define SYS_SRST2_rstn_uart2_shift                                    (7)
#define SYS_SRST2_rstn_uart3_shift                                    (6)
#define SYS_SRST2_rstn_gpio_shift                                     (5)
#define SYS_SRST2_rstn_i2c1_shift                                     (4)
#define SYS_SRST2_rstn_i2c2_shift                                     (3)
#define SYS_SRST2_rstn_nf_shift                                       (2)
#define SYS_SRST2_rstn_sc_shift                                       (1)
#define SYS_SRST2_rstn_pc_shift                                       (0)
#define SYS_SRST2_rstn_tm_mask                                        (0x10000000)
#define SYS_SRST2_rstn_atvin2_mask                                    (0x08000000)
#define SYS_SRST2_rstn_atvin_mask                                     (0x04000000)
#define SYS_SRST2_rstn_osdcmp_mask                                    (0x02000000)
#define SYS_SRST2_rstn_etn_mask                                       (0x01000000)
#define SYS_SRST2_rstn_cr_mask                                        (0x00800000)
#define SYS_SRST2_rstn_bistreg_mask                                   (0x00200000)
#define SYS_SRST2_rstn_usb_arb_mask                                   (0x00100000)
#define SYS_SRST2_dummy18000108_19_mask                               (0x00080000)
#define SYS_SRST2_rstn_usb3_mac_mask                                  (0x00040000)
#define SYS_SRST2_dummy18000108_17_mask                               (0x00020000)
#define SYS_SRST2_dummy18000108_15_13_mask                            (0x0000E000)
#define SYS_SRST2_rstn_padmux_mask                                    (0x00001000)
#define SYS_SRST2_rstn_dtv_demod_mask                                 (0x00000800)
#define SYS_SRST2_rstn_misc_mask                                      (0x00000400)
#define SYS_SRST2_rstn_pwm_mask                                       (0x00000200)
#define SYS_SRST2_rstn_uart1_mask                                     (0x00000100)
#define SYS_SRST2_rstn_uart2_mask                                     (0x00000080)
#define SYS_SRST2_rstn_uart3_mask                                     (0x00000040)
#define SYS_SRST2_rstn_gpio_mask                                      (0x00000020)
#define SYS_SRST2_rstn_i2c1_mask                                      (0x00000010)
#define SYS_SRST2_rstn_i2c2_mask                                      (0x00000008)
#define SYS_SRST2_rstn_nf_mask                                        (0x00000004)
#define SYS_SRST2_rstn_sc_mask                                        (0x00000002)
#define SYS_SRST2_rstn_pc_mask                                        (0x00000001)
#define SYS_SRST2_rstn_tm(data)                                       (0x10000000&((data)<<28))
#define SYS_SRST2_rstn_atvin2(data)                                   (0x08000000&((data)<<27))
#define SYS_SRST2_rstn_atvin(data)                                    (0x04000000&((data)<<26))
#define SYS_SRST2_rstn_osdcmp(data)                                   (0x02000000&((data)<<25))
#define SYS_SRST2_rstn_etn(data)                                      (0x01000000&((data)<<24))
#define SYS_SRST2_rstn_cr(data)                                       (0x00800000&((data)<<23))
#define SYS_SRST2_rstn_bistreg(data)                                  (0x00200000&((data)<<21))
#define SYS_SRST2_rstn_usb_arb(data)                                  (0x00100000&((data)<<20))
#define SYS_SRST2_dummy18000108_19(data)                              (0x00080000&((data)<<19))
#define SYS_SRST2_rstn_usb3_mac(data)                                 (0x00040000&((data)<<18))
#define SYS_SRST2_dummy18000108_17(data)                              (0x00020000&((data)<<17))
#define SYS_SRST2_dummy18000108_15_13(data)                           (0x0000E000&((data)<<13))
#define SYS_SRST2_rstn_padmux(data)                                   (0x00001000&((data)<<12))
#define SYS_SRST2_rstn_dtv_demod(data)                                (0x00000800&((data)<<11))
#define SYS_SRST2_rstn_misc(data)                                     (0x00000400&((data)<<10))
#define SYS_SRST2_rstn_pwm(data)                                      (0x00000200&((data)<<9))
#define SYS_SRST2_rstn_uart1(data)                                    (0x00000100&((data)<<8))
#define SYS_SRST2_rstn_uart2(data)                                    (0x00000080&((data)<<7))
#define SYS_SRST2_rstn_uart3(data)                                    (0x00000040&((data)<<6))
#define SYS_SRST2_rstn_gpio(data)                                     (0x00000020&((data)<<5))
#define SYS_SRST2_rstn_i2c1(data)                                     (0x00000010&((data)<<4))
#define SYS_SRST2_rstn_i2c2(data)                                     (0x00000008&((data)<<3))
#define SYS_SRST2_rstn_nf(data)                                       (0x00000004&((data)<<2))
#define SYS_SRST2_rstn_sc(data)                                       (0x00000002&((data)<<1))
#define SYS_SRST2_rstn_pc(data)                                       (0x00000001&(data))
#define SYS_SRST2_get_rstn_tm(data)                                   ((0x10000000&(data))>>28)
#define SYS_SRST2_get_rstn_atvin2(data)                               ((0x08000000&(data))>>27)
#define SYS_SRST2_get_rstn_atvin(data)                                ((0x04000000&(data))>>26)
#define SYS_SRST2_get_rstn_osdcmp(data)                               ((0x02000000&(data))>>25)
#define SYS_SRST2_get_rstn_etn(data)                                  ((0x01000000&(data))>>24)
#define SYS_SRST2_get_rstn_cr(data)                                   ((0x00800000&(data))>>23)
#define SYS_SRST2_get_rstn_bistreg(data)                              ((0x00200000&(data))>>21)
#define SYS_SRST2_get_rstn_usb_arb(data)                              ((0x00100000&(data))>>20)
#define SYS_SRST2_get_dummy18000108_19(data)                          ((0x00080000&(data))>>19)
#define SYS_SRST2_get_rstn_usb3_mac(data)                             ((0x00040000&(data))>>18)
#define SYS_SRST2_get_dummy18000108_17(data)                          ((0x00020000&(data))>>17)
#define SYS_SRST2_get_dummy18000108_15_13(data)                       ((0x0000E000&(data))>>13)
#define SYS_SRST2_get_rstn_padmux(data)                               ((0x00001000&(data))>>12)
#define SYS_SRST2_get_rstn_dtv_demod(data)                            ((0x00000800&(data))>>11)
#define SYS_SRST2_get_rstn_misc(data)                                 ((0x00000400&(data))>>10)
#define SYS_SRST2_get_rstn_pwm(data)                                  ((0x00000200&(data))>>9)
#define SYS_SRST2_get_rstn_uart1(data)                                ((0x00000100&(data))>>8)
#define SYS_SRST2_get_rstn_uart2(data)                                ((0x00000080&(data))>>7)
#define SYS_SRST2_get_rstn_uart3(data)                                ((0x00000040&(data))>>6)
#define SYS_SRST2_get_rstn_gpio(data)                                 ((0x00000020&(data))>>5)
#define SYS_SRST2_get_rstn_i2c1(data)                                 ((0x00000010&(data))>>4)
#define SYS_SRST2_get_rstn_i2c2(data)                                 ((0x00000008&(data))>>3)
#define SYS_SRST2_get_rstn_nf(data)                                   ((0x00000004&(data))>>2)
#define SYS_SRST2_get_rstn_sc(data)                                   ((0x00000002&(data))>>1)
#define SYS_SRST2_get_rstn_pc(data)                                   (0x00000001&(data))


#define SYS_SRST3                                                     0x1800010c
#define SYS_SRST3_reg_addr                                            "0xb800010c"
#define SYS_SRST3_reg                                                 0xb800010c
#define SYS_SRST3_inst_addr                                           "0x0043"
#define SYS_SRST3_inst                                                0x0043
#define SYS_SRST3_rstn_scpu_dbg_shift                                 (31)
#define SYS_SRST3_rstn_dcphy2_shift                                   (25)
#define SYS_SRST3_rstn_dcu2_shift                                     (24)
#define SYS_SRST3_rstn_irtx_shift                                     (18)
#define SYS_SRST3_rstn_ddc_shift                                      (17)
#define SYS_SRST3_rstn_sd_shift                                       (16)
#define SYS_SRST3_rstn_usb2_phy_p3_shift                              (7)
#define SYS_SRST3_rstn_usb2_phy_p2_shift                              (6)
#define SYS_SRST3_rstn_usb2_phy_p1_shift                              (5)
#define SYS_SRST3_rstn_usb2_phy_p0_shift                              (4)
#define SYS_SRST3_rstn_usb3_phy_shift                                 (2)
#define SYS_SRST3_rstn_usb3_p0_mdio_shift                             (1)
#define SYS_SRST3_rstn_scpu_dbg_mask                                  (0x80000000)
#define SYS_SRST3_rstn_dcphy2_mask                                    (0x02000000)
#define SYS_SRST3_rstn_dcu2_mask                                      (0x01000000)
#define SYS_SRST3_rstn_irtx_mask                                      (0x00040000)
#define SYS_SRST3_rstn_ddc_mask                                       (0x00020000)
#define SYS_SRST3_rstn_sd_mask                                        (0x00010000)
#define SYS_SRST3_rstn_usb2_phy_p3_mask                               (0x00000080)
#define SYS_SRST3_rstn_usb2_phy_p2_mask                               (0x00000040)
#define SYS_SRST3_rstn_usb2_phy_p1_mask                               (0x00000020)
#define SYS_SRST3_rstn_usb2_phy_p0_mask                               (0x00000010)
#define SYS_SRST3_rstn_usb3_phy_mask                                  (0x00000004)
#define SYS_SRST3_rstn_usb3_p0_mdio_mask                              (0x00000002)
#define SYS_SRST3_rstn_scpu_dbg(data)                                 (0x80000000&((data)<<31))
#define SYS_SRST3_rstn_dcphy2(data)                                   (0x02000000&((data)<<25))
#define SYS_SRST3_rstn_dcu2(data)                                     (0x01000000&((data)<<24))
#define SYS_SRST3_rstn_irtx(data)                                     (0x00040000&((data)<<18))
#define SYS_SRST3_rstn_ddc(data)                                      (0x00020000&((data)<<17))
#define SYS_SRST3_rstn_sd(data)                                       (0x00010000&((data)<<16))
#define SYS_SRST3_rstn_usb2_phy_p3(data)                              (0x00000080&((data)<<7))
#define SYS_SRST3_rstn_usb2_phy_p2(data)                              (0x00000040&((data)<<6))
#define SYS_SRST3_rstn_usb2_phy_p1(data)                              (0x00000020&((data)<<5))
#define SYS_SRST3_rstn_usb2_phy_p0(data)                              (0x00000010&((data)<<4))
#define SYS_SRST3_rstn_usb3_phy(data)                                 (0x00000004&((data)<<2))
#define SYS_SRST3_rstn_usb3_p0_mdio(data)                             (0x00000002&((data)<<1))
#define SYS_SRST3_get_rstn_scpu_dbg(data)                             ((0x80000000&(data))>>31)
#define SYS_SRST3_get_rstn_dcphy2(data)                               ((0x02000000&(data))>>25)
#define SYS_SRST3_get_rstn_dcu2(data)                                 ((0x01000000&(data))>>24)
#define SYS_SRST3_get_rstn_irtx(data)                                 ((0x00040000&(data))>>18)
#define SYS_SRST3_get_rstn_ddc(data)                                  ((0x00020000&(data))>>17)
#define SYS_SRST3_get_rstn_sd(data)                                   ((0x00010000&(data))>>16)
#define SYS_SRST3_get_rstn_usb2_phy_p3(data)                          ((0x00000080&(data))>>7)
#define SYS_SRST3_get_rstn_usb2_phy_p2(data)                          ((0x00000040&(data))>>6)
#define SYS_SRST3_get_rstn_usb2_phy_p1(data)                          ((0x00000020&(data))>>5)
#define SYS_SRST3_get_rstn_usb2_phy_p0(data)                          ((0x00000010&(data))>>4)
#define SYS_SRST3_get_rstn_usb3_phy(data)                             ((0x00000004&(data))>>2)
#define SYS_SRST3_get_rstn_usb3_p0_mdio(data)                         ((0x00000002&(data))>>1)


#define SYS_CLKEN0                                                    0x18000110
#define SYS_CLKEN0_reg_addr                                           "0xb8000110"
#define SYS_CLKEN0_reg                                                0xb8000110
#define SYS_CLKEN0_inst_addr                                          "0x0044"
#define SYS_CLKEN0_inst                                               0x0044
#define SYS_CLKEN0_clken_ve2_p2_shift                                 (9)
#define SYS_CLKEN0_clken_ve2_shift                                    (8)
#define SYS_CLKEN0_clken_vcpu2_shift                                  (7)
#define SYS_CLKEN0_clken_ve_p2_shift                                  (5)
#define SYS_CLKEN0_clken_ve_shift                                     (4)
#define SYS_CLKEN0_clken_vcpu_shift                                   (3)
#define SYS_CLKEN0_clken_scpu_shift                                   (1)
#define SYS_CLKEN0_clken_pllreg_shift                                 (0)
#define SYS_CLKEN0_clken_ve2_p2_mask                                  (0x00000200)
#define SYS_CLKEN0_clken_ve2_mask                                     (0x00000100)
#define SYS_CLKEN0_clken_vcpu2_mask                                   (0x00000080)
#define SYS_CLKEN0_clken_ve_p2_mask                                   (0x00000020)
#define SYS_CLKEN0_clken_ve_mask                                      (0x00000010)
#define SYS_CLKEN0_clken_vcpu_mask                                    (0x00000008)
#define SYS_CLKEN0_clken_scpu_mask                                    (0x00000002)
#define SYS_CLKEN0_clken_pllreg_mask                                  (0x00000001)
#define SYS_CLKEN0_clken_ve2_p2(data)                                 (0x00000200&((data)<<9))
#define SYS_CLKEN0_clken_ve2(data)                                    (0x00000100&((data)<<8))
#define SYS_CLKEN0_clken_vcpu2(data)                                  (0x00000080&((data)<<7))
#define SYS_CLKEN0_clken_ve_p2(data)                                  (0x00000020&((data)<<5))
#define SYS_CLKEN0_clken_ve(data)                                     (0x00000010&((data)<<4))
#define SYS_CLKEN0_clken_vcpu(data)                                   (0x00000008&((data)<<3))
#define SYS_CLKEN0_clken_scpu(data)                                   (0x00000002&((data)<<1))
#define SYS_CLKEN0_clken_pllreg(data)                                 (0x00000001&(data))
#define SYS_CLKEN0_get_clken_ve2_p2(data)                             ((0x00000200&(data))>>9)
#define SYS_CLKEN0_get_clken_ve2(data)                                ((0x00000100&(data))>>8)
#define SYS_CLKEN0_get_clken_vcpu2(data)                              ((0x00000080&(data))>>7)
#define SYS_CLKEN0_get_clken_ve_p2(data)                              ((0x00000020&(data))>>5)
#define SYS_CLKEN0_get_clken_ve(data)                                 ((0x00000010&(data))>>4)
#define SYS_CLKEN0_get_clken_vcpu(data)                               ((0x00000008&(data))>>3)
#define SYS_CLKEN0_get_clken_scpu(data)                               ((0x00000002&(data))>>1)
#define SYS_CLKEN0_get_clken_pllreg(data)                             (0x00000001&(data))


#define SYS_CLKEN1                                                    0x18000114
#define SYS_CLKEN1_reg_addr                                           "0xb8000114"
#define SYS_CLKEN1_reg                                                0xb8000114
#define SYS_CLKEN1_inst_addr                                          "0x0045"
#define SYS_CLKEN1_inst                                               0x0045
#define SYS_CLKEN1_clken_tvsb1_shift                                  (31)
#define SYS_CLKEN1_clken_tvsb2_shift                                  (30)
#define SYS_CLKEN1_clken_tvsb3_shift                                  (29)
#define SYS_CLKEN1_clken_tvsb2_dc2_shift                              (28)
#define SYS_CLKEN1_clken_tvsb3_dc2_shift                              (27)
#define SYS_CLKEN1_dummy18000114_26_shift                             (26)
#define SYS_CLKEN1_clken_dcphy_shift                                  (25)
#define SYS_CLKEN1_clken_dcu_shift                                    (24)
#define SYS_CLKEN1_clken_if_demod_shift                               (23)
#define SYS_CLKEN1_clken_vdec_shift                                   (22)
#define SYS_CLKEN1_dummy18000114_21_shift                             (21)
#define SYS_CLKEN1_clken_vbis0_shift                                  (20)
#define SYS_CLKEN1_clken_audio_daad_128fs_shift                       (19)
#define SYS_CLKEN1_clken_audio_daad_256fs_shift                       (18)
#define SYS_CLKEN1_clken_audio_pre512fs_shift                         (17)
#define SYS_CLKEN1_clken_audio_shift                                  (16)
#define SYS_CLKEN1_clken_ifadc_shift                                  (15)
#define SYS_CLKEN1_dummy18000114_14_13_shift                          (13)
#define SYS_CLKEN1_clken_me_shift                                     (12)
#define SYS_CLKEN1_clken_apll_adc_shift                               (11)
#define SYS_CLKEN1_clken_hdmi_shift                                   (10)
#define SYS_CLKEN1_clken_tp_shift                                     (8)
#define SYS_CLKEN1_clken_cp_shift                                     (7)
#define SYS_CLKEN1_clken_md_shift                                     (6)
#define SYS_CLKEN1_clken_se_shift                                     (5)
#define SYS_CLKEN1_dummy18000114_4_shift                              (4)
#define SYS_CLKEN1_clken_3d_gde_shift                                 (3)
#define SYS_CLKEN1_clken_vodma_shift                                  (2)
#define SYS_CLKEN1_clken_dispim_shift                                 (1)
#define SYS_CLKEN1_clken_disp_shift                                   (0)
#define SYS_CLKEN1_clken_tvsb1_mask                                   (0x80000000)
#define SYS_CLKEN1_clken_tvsb2_mask                                   (0x40000000)
#define SYS_CLKEN1_clken_tvsb3_mask                                   (0x20000000)
#define SYS_CLKEN1_clken_tvsb2_dc2_mask                               (0x10000000)
#define SYS_CLKEN1_clken_tvsb3_dc2_mask                               (0x08000000)
#define SYS_CLKEN1_dummy18000114_26_mask                              (0x04000000)
#define SYS_CLKEN1_clken_dcphy_mask                                   (0x02000000)
#define SYS_CLKEN1_clken_dcu_mask                                     (0x01000000)
#define SYS_CLKEN1_clken_if_demod_mask                                (0x00800000)
#define SYS_CLKEN1_clken_vdec_mask                                    (0x00400000)
#define SYS_CLKEN1_dummy18000114_21_mask                              (0x00200000)
#define SYS_CLKEN1_clken_vbis0_mask                                   (0x00100000)
#define SYS_CLKEN1_clken_audio_daad_128fs_mask                        (0x00080000)
#define SYS_CLKEN1_clken_audio_daad_256fs_mask                        (0x00040000)
#define SYS_CLKEN1_clken_audio_pre512fs_mask                          (0x00020000)
#define SYS_CLKEN1_clken_audio_mask                                   (0x00010000)
#define SYS_CLKEN1_clken_ifadc_mask                                   (0x00008000)
#define SYS_CLKEN1_dummy18000114_14_13_mask                           (0x00006000)
#define SYS_CLKEN1_clken_me_mask                                      (0x00001000)
#define SYS_CLKEN1_clken_apll_adc_mask                                (0x00000800)
#define SYS_CLKEN1_clken_hdmi_mask                                    (0x00000400)
#define SYS_CLKEN1_clken_tp_mask                                      (0x00000100)
#define SYS_CLKEN1_clken_cp_mask                                      (0x00000080)
#define SYS_CLKEN1_clken_md_mask                                      (0x00000040)
#define SYS_CLKEN1_clken_se_mask                                      (0x00000020)
#define SYS_CLKEN1_dummy18000114_4_mask                               (0x00000010)
#define SYS_CLKEN1_clken_3d_gde_mask                                  (0x00000008)
#define SYS_CLKEN1_clken_vodma_mask                                   (0x00000004)
#define SYS_CLKEN1_clken_dispim_mask                                  (0x00000002)
#define SYS_CLKEN1_clken_disp_mask                                    (0x00000001)
#define SYS_CLKEN1_clken_tvsb1(data)                                  (0x80000000&((data)<<31))
#define SYS_CLKEN1_clken_tvsb2(data)                                  (0x40000000&((data)<<30))
#define SYS_CLKEN1_clken_tvsb3(data)                                  (0x20000000&((data)<<29))
#define SYS_CLKEN1_clken_tvsb2_dc2(data)                              (0x10000000&((data)<<28))
#define SYS_CLKEN1_clken_tvsb3_dc2(data)                              (0x08000000&((data)<<27))
#define SYS_CLKEN1_dummy18000114_26(data)                             (0x04000000&((data)<<26))
#define SYS_CLKEN1_clken_dcphy(data)                                  (0x02000000&((data)<<25))
#define SYS_CLKEN1_clken_dcu(data)                                    (0x01000000&((data)<<24))
#define SYS_CLKEN1_clken_if_demod(data)                               (0x00800000&((data)<<23))
#define SYS_CLKEN1_clken_vdec(data)                                   (0x00400000&((data)<<22))
#define SYS_CLKEN1_dummy18000114_21(data)                             (0x00200000&((data)<<21))
#define SYS_CLKEN1_clken_vbis0(data)                                  (0x00100000&((data)<<20))
#define SYS_CLKEN1_clken_audio_daad_128fs(data)                       (0x00080000&((data)<<19))
#define SYS_CLKEN1_clken_audio_daad_256fs(data)                       (0x00040000&((data)<<18))
#define SYS_CLKEN1_clken_audio_pre512fs(data)                         (0x00020000&((data)<<17))
#define SYS_CLKEN1_clken_audio(data)                                  (0x00010000&((data)<<16))
#define SYS_CLKEN1_clken_ifadc(data)                                  (0x00008000&((data)<<15))
#define SYS_CLKEN1_dummy18000114_14_13(data)                          (0x00006000&((data)<<13))
#define SYS_CLKEN1_clken_me(data)                                     (0x00001000&((data)<<12))
#define SYS_CLKEN1_clken_apll_adc(data)                               (0x00000800&((data)<<11))
#define SYS_CLKEN1_clken_hdmi(data)                                   (0x00000400&((data)<<10))
#define SYS_CLKEN1_clken_tp(data)                                     (0x00000100&((data)<<8))
#define SYS_CLKEN1_clken_cp(data)                                     (0x00000080&((data)<<7))
#define SYS_CLKEN1_clken_md(data)                                     (0x00000040&((data)<<6))
#define SYS_CLKEN1_clken_se(data)                                     (0x00000020&((data)<<5))
#define SYS_CLKEN1_dummy18000114_4(data)                              (0x00000010&((data)<<4))
#define SYS_CLKEN1_clken_3d_gde(data)                                 (0x00000008&((data)<<3))
#define SYS_CLKEN1_clken_vodma(data)                                  (0x00000004&((data)<<2))
#define SYS_CLKEN1_clken_dispim(data)                                 (0x00000002&((data)<<1))
#define SYS_CLKEN1_clken_disp(data)                                   (0x00000001&(data))
#define SYS_CLKEN1_get_clken_tvsb1(data)                              ((0x80000000&(data))>>31)
#define SYS_CLKEN1_get_clken_tvsb2(data)                              ((0x40000000&(data))>>30)
#define SYS_CLKEN1_get_clken_tvsb3(data)                              ((0x20000000&(data))>>29)
#define SYS_CLKEN1_get_clken_tvsb2_dc2(data)                          ((0x10000000&(data))>>28)
#define SYS_CLKEN1_get_clken_tvsb3_dc2(data)                          ((0x08000000&(data))>>27)
#define SYS_CLKEN1_get_dummy18000114_26(data)                         ((0x04000000&(data))>>26)
#define SYS_CLKEN1_get_clken_dcphy(data)                              ((0x02000000&(data))>>25)
#define SYS_CLKEN1_get_clken_dcu(data)                                ((0x01000000&(data))>>24)
#define SYS_CLKEN1_get_clken_if_demod(data)                           ((0x00800000&(data))>>23)
#define SYS_CLKEN1_get_clken_vdec(data)                               ((0x00400000&(data))>>22)
#define SYS_CLKEN1_get_dummy18000114_21(data)                         ((0x00200000&(data))>>21)
#define SYS_CLKEN1_get_clken_vbis0(data)                              ((0x00100000&(data))>>20)
#define SYS_CLKEN1_get_clken_audio_daad_128fs(data)                   ((0x00080000&(data))>>19)
#define SYS_CLKEN1_get_clken_audio_daad_256fs(data)                   ((0x00040000&(data))>>18)
#define SYS_CLKEN1_get_clken_audio_pre512fs(data)                     ((0x00020000&(data))>>17)
#define SYS_CLKEN1_get_clken_audio(data)                              ((0x00010000&(data))>>16)
#define SYS_CLKEN1_get_clken_ifadc(data)                              ((0x00008000&(data))>>15)
#define SYS_CLKEN1_get_dummy18000114_14_13(data)                      ((0x00006000&(data))>>13)
#define SYS_CLKEN1_get_clken_me(data)                                 ((0x00001000&(data))>>12)
#define SYS_CLKEN1_get_clken_apll_adc(data)                           ((0x00000800&(data))>>11)
#define SYS_CLKEN1_get_clken_hdmi(data)                               ((0x00000400&(data))>>10)
#define SYS_CLKEN1_get_clken_tp(data)                                 ((0x00000100&(data))>>8)
#define SYS_CLKEN1_get_clken_cp(data)                                 ((0x00000080&(data))>>7)
#define SYS_CLKEN1_get_clken_md(data)                                 ((0x00000040&(data))>>6)
#define SYS_CLKEN1_get_clken_se(data)                                 ((0x00000020&(data))>>5)
#define SYS_CLKEN1_get_dummy18000114_4(data)                          ((0x00000010&(data))>>4)
#define SYS_CLKEN1_get_clken_3d_gde(data)                             ((0x00000008&(data))>>3)
#define SYS_CLKEN1_get_clken_vodma(data)                              ((0x00000004&(data))>>2)
#define SYS_CLKEN1_get_clken_dispim(data)                             ((0x00000002&(data))>>1)
#define SYS_CLKEN1_get_clken_disp(data)                               (0x00000001&(data))


#define SYS_CLKEN2                                                    0x18000118
#define SYS_CLKEN2_reg_addr                                           "0xb8000118"
#define SYS_CLKEN2_reg                                                0xb8000118
#define SYS_CLKEN2_inst_addr                                          "0x0046"
#define SYS_CLKEN2_inst                                               0x0046
#define SYS_CLKEN2_clken_spds_shift                                   (29)
#define SYS_CLKEN2_clken_tm_shift                                     (28)
#define SYS_CLKEN2_clken_atvin_vd_shift                               (27)
#define SYS_CLKEN2_clken_atvin_ifd_shift                              (26)
#define SYS_CLKEN2_clken_osdcmp_shift                                 (25)
#define SYS_CLKEN2_clken_etn_shift                                    (24)
#define SYS_CLKEN2_clken_cr_shift                                     (23)
#define SYS_CLKEN2_clken_efuse_shift                                  (22)
#define SYS_CLKEN2_clken_bistreg_shift                                (21)
#define SYS_CLKEN2_clken_usb_shift                                    (18)
#define SYS_CLKEN2_clken_audio2_512fs_shift                           (15)
#define SYS_CLKEN2_clken_audio2_daad_256fs_shift                      (14)
#define SYS_CLKEN2_clken_audio2_daad_128fs_shift                      (13)
#define SYS_CLKEN2_clken_padmux_shift                                 (12)
#define SYS_CLKEN2_clken_dtv_demod_shift                              (11)
#define SYS_CLKEN2_clken_misc_shift                                   (10)
#define SYS_CLKEN2_clken_pwm_shift                                    (9)
#define SYS_CLKEN2_clken_uart1_shift                                  (8)
#define SYS_CLKEN2_clken_uart2_shift                                  (7)
#define SYS_CLKEN2_clken_uart3_shift                                  (6)
#define SYS_CLKEN2_clken_gpio_shift                                   (5)
#define SYS_CLKEN2_clken_i2c1_shift                                   (4)
#define SYS_CLKEN2_clken_i2c2_shift                                   (3)
#define SYS_CLKEN2_clken_nf_shift                                     (2)
#define SYS_CLKEN2_clken_sc_shift                                     (1)
#define SYS_CLKEN2_clken_pc_shift                                     (0)
#define SYS_CLKEN2_clken_spds_mask                                    (0x20000000)
#define SYS_CLKEN2_clken_tm_mask                                      (0x10000000)
#define SYS_CLKEN2_clken_atvin_vd_mask                                (0x08000000)
#define SYS_CLKEN2_clken_atvin_ifd_mask                               (0x04000000)
#define SYS_CLKEN2_clken_osdcmp_mask                                  (0x02000000)
#define SYS_CLKEN2_clken_etn_mask                                     (0x01000000)
#define SYS_CLKEN2_clken_cr_mask                                      (0x00800000)
#define SYS_CLKEN2_clken_efuse_mask                                   (0x00400000)
#define SYS_CLKEN2_clken_bistreg_mask                                 (0x00200000)
#define SYS_CLKEN2_clken_usb_mask                                     (0x00040000)
#define SYS_CLKEN2_clken_audio2_512fs_mask                            (0x00008000)
#define SYS_CLKEN2_clken_audio2_daad_256fs_mask                       (0x00004000)
#define SYS_CLKEN2_clken_audio2_daad_128fs_mask                       (0x00002000)
#define SYS_CLKEN2_clken_padmux_mask                                  (0x00001000)
#define SYS_CLKEN2_clken_dtv_demod_mask                               (0x00000800)
#define SYS_CLKEN2_clken_misc_mask                                    (0x00000400)
#define SYS_CLKEN2_clken_pwm_mask                                     (0x00000200)
#define SYS_CLKEN2_clken_uart1_mask                                   (0x00000100)
#define SYS_CLKEN2_clken_uart2_mask                                   (0x00000080)
#define SYS_CLKEN2_clken_uart3_mask                                   (0x00000040)
#define SYS_CLKEN2_clken_gpio_mask                                    (0x00000020)
#define SYS_CLKEN2_clken_i2c1_mask                                    (0x00000010)
#define SYS_CLKEN2_clken_i2c2_mask                                    (0x00000008)
#define SYS_CLKEN2_clken_nf_mask                                      (0x00000004)
#define SYS_CLKEN2_clken_sc_mask                                      (0x00000002)
#define SYS_CLKEN2_clken_pc_mask                                      (0x00000001)
#define SYS_CLKEN2_clken_spds(data)                                   (0x20000000&((data)<<29))
#define SYS_CLKEN2_clken_tm(data)                                     (0x10000000&((data)<<28))
#define SYS_CLKEN2_clken_atvin_vd(data)                               (0x08000000&((data)<<27))
#define SYS_CLKEN2_clken_atvin_ifd(data)                              (0x04000000&((data)<<26))
#define SYS_CLKEN2_clken_osdcmp(data)                                 (0x02000000&((data)<<25))
#define SYS_CLKEN2_clken_etn(data)                                    (0x01000000&((data)<<24))
#define SYS_CLKEN2_clken_cr(data)                                     (0x00800000&((data)<<23))
#define SYS_CLKEN2_clken_efuse(data)                                  (0x00400000&((data)<<22))
#define SYS_CLKEN2_clken_bistreg(data)                                (0x00200000&((data)<<21))
#define SYS_CLKEN2_clken_usb(data)                                    (0x00040000&((data)<<18))
#define SYS_CLKEN2_clken_audio2_512fs(data)                           (0x00008000&((data)<<15))
#define SYS_CLKEN2_clken_audio2_daad_256fs(data)                      (0x00004000&((data)<<14))
#define SYS_CLKEN2_clken_audio2_daad_128fs(data)                      (0x00002000&((data)<<13))
#define SYS_CLKEN2_clken_padmux(data)                                 (0x00001000&((data)<<12))
#define SYS_CLKEN2_clken_dtv_demod(data)                              (0x00000800&((data)<<11))
#define SYS_CLKEN2_clken_misc(data)                                   (0x00000400&((data)<<10))
#define SYS_CLKEN2_clken_pwm(data)                                    (0x00000200&((data)<<9))
#define SYS_CLKEN2_clken_uart1(data)                                  (0x00000100&((data)<<8))
#define SYS_CLKEN2_clken_uart2(data)                                  (0x00000080&((data)<<7))
#define SYS_CLKEN2_clken_uart3(data)                                  (0x00000040&((data)<<6))
#define SYS_CLKEN2_clken_gpio(data)                                   (0x00000020&((data)<<5))
#define SYS_CLKEN2_clken_i2c1(data)                                   (0x00000010&((data)<<4))
#define SYS_CLKEN2_clken_i2c2(data)                                   (0x00000008&((data)<<3))
#define SYS_CLKEN2_clken_nf(data)                                     (0x00000004&((data)<<2))
#define SYS_CLKEN2_clken_sc(data)                                     (0x00000002&((data)<<1))
#define SYS_CLKEN2_clken_pc(data)                                     (0x00000001&(data))
#define SYS_CLKEN2_get_clken_spds(data)                               ((0x20000000&(data))>>29)
#define SYS_CLKEN2_get_clken_tm(data)                                 ((0x10000000&(data))>>28)
#define SYS_CLKEN2_get_clken_atvin_vd(data)                           ((0x08000000&(data))>>27)
#define SYS_CLKEN2_get_clken_atvin_ifd(data)                          ((0x04000000&(data))>>26)
#define SYS_CLKEN2_get_clken_osdcmp(data)                             ((0x02000000&(data))>>25)
#define SYS_CLKEN2_get_clken_etn(data)                                ((0x01000000&(data))>>24)
#define SYS_CLKEN2_get_clken_cr(data)                                 ((0x00800000&(data))>>23)
#define SYS_CLKEN2_get_clken_efuse(data)                              ((0x00400000&(data))>>22)
#define SYS_CLKEN2_get_clken_bistreg(data)                            ((0x00200000&(data))>>21)
#define SYS_CLKEN2_get_clken_usb(data)                                ((0x00040000&(data))>>18)
#define SYS_CLKEN2_get_clken_audio2_512fs(data)                       ((0x00008000&(data))>>15)
#define SYS_CLKEN2_get_clken_audio2_daad_256fs(data)                  ((0x00004000&(data))>>14)
#define SYS_CLKEN2_get_clken_audio2_daad_128fs(data)                  ((0x00002000&(data))>>13)
#define SYS_CLKEN2_get_clken_padmux(data)                             ((0x00001000&(data))>>12)
#define SYS_CLKEN2_get_clken_dtv_demod(data)                          ((0x00000800&(data))>>11)
#define SYS_CLKEN2_get_clken_misc(data)                               ((0x00000400&(data))>>10)
#define SYS_CLKEN2_get_clken_pwm(data)                                ((0x00000200&(data))>>9)
#define SYS_CLKEN2_get_clken_uart1(data)                              ((0x00000100&(data))>>8)
#define SYS_CLKEN2_get_clken_uart2(data)                              ((0x00000080&(data))>>7)
#define SYS_CLKEN2_get_clken_uart3(data)                              ((0x00000040&(data))>>6)
#define SYS_CLKEN2_get_clken_gpio(data)                               ((0x00000020&(data))>>5)
#define SYS_CLKEN2_get_clken_i2c1(data)                               ((0x00000010&(data))>>4)
#define SYS_CLKEN2_get_clken_i2c2(data)                               ((0x00000008&(data))>>3)
#define SYS_CLKEN2_get_clken_nf(data)                                 ((0x00000004&(data))>>2)
#define SYS_CLKEN2_get_clken_sc(data)                                 ((0x00000002&(data))>>1)
#define SYS_CLKEN2_get_clken_pc(data)                                 (0x00000001&(data))


#define SYS_CLKEN3                                                    0x1800011c
#define SYS_CLKEN3_reg_addr                                           "0xb800011c"
#define SYS_CLKEN3_reg                                                0xb800011c
#define SYS_CLKEN3_inst_addr                                          "0x0047"
#define SYS_CLKEN3_inst                                               0x0047
#define SYS_CLKEN3_clken_dcphy2_shift                                 (25)
#define SYS_CLKEN3_clken_dcu2_shift                                   (24)
#define SYS_CLKEN3_clken_irtx_shift                                   (18)
#define SYS_CLKEN3_clken_ddc_shift                                    (17)
#define SYS_CLKEN3_clken_sd_shift                                     (16)
#define SYS_CLKEN3_clken_dcphy2_mask                                  (0x02000000)
#define SYS_CLKEN3_clken_dcu2_mask                                    (0x01000000)
#define SYS_CLKEN3_clken_irtx_mask                                    (0x00040000)
#define SYS_CLKEN3_clken_ddc_mask                                     (0x00020000)
#define SYS_CLKEN3_clken_sd_mask                                      (0x00010000)
#define SYS_CLKEN3_clken_dcphy2(data)                                 (0x02000000&((data)<<25))
#define SYS_CLKEN3_clken_dcu2(data)                                   (0x01000000&((data)<<24))
#define SYS_CLKEN3_clken_irtx(data)                                   (0x00040000&((data)<<18))
#define SYS_CLKEN3_clken_ddc(data)                                    (0x00020000&((data)<<17))
#define SYS_CLKEN3_clken_sd(data)                                     (0x00010000&((data)<<16))
#define SYS_CLKEN3_get_clken_dcphy2(data)                             ((0x02000000&(data))>>25)
#define SYS_CLKEN3_get_clken_dcu2(data)                               ((0x01000000&(data))>>24)
#define SYS_CLKEN3_get_clken_irtx(data)                               ((0x00040000&(data))>>18)
#define SYS_CLKEN3_get_clken_ddc(data)                                ((0x00020000&(data))>>17)
#define SYS_CLKEN3_get_clken_sd(data)                                 ((0x00010000&(data))>>16)


#define SYS_CPUSEL                                                    0x18000200
#define SYS_CPUSEL_reg_addr                                           "0xb8000200"
#define SYS_CPUSEL_reg                                                0xb8000200
#define SYS_CPUSEL_inst_addr                                          "0x0080"
#define SYS_CPUSEL_inst                                               0x0080
#define SYS_CPUSEL_ejtag_mode_shift                                   (4)
#define SYS_CPUSEL_acpu_clksel_shift                                  (0)
#define SYS_CPUSEL_ejtag_mode_mask                                    (0x00000010)
#define SYS_CPUSEL_acpu_clksel_mask                                   (0x00000001)
#define SYS_CPUSEL_ejtag_mode(data)                                   (0x00000010&((data)<<4))
#define SYS_CPUSEL_acpu_clksel(data)                                  (0x00000001&(data))
#define SYS_CPUSEL_get_ejtag_mode(data)                               ((0x00000010&(data))>>4)
#define SYS_CPUSEL_get_acpu_clksel(data)                              (0x00000001&(data))


#define SYS_CLKSEL                                                    0x18000204
#define SYS_CLKSEL_reg_addr                                           "0xb8000204"
#define SYS_CLKSEL_reg                                                0xb8000204
#define SYS_CLKSEL_inst_addr                                          "0x0081"
#define SYS_CLKSEL_inst                                               0x0081
#define SYS_CLKSEL_epi_dbg_clksel_shift                               (24)
#define SYS_CLKSEL_epi_div_clksel_shift                               (23)
#define SYS_CLKSEL_sd_clksel_shift                                    (20)
#define SYS_CLKSEL_atvin_clk_sel_shift                                (17)
#define SYS_CLKSEL_atvin_vd_clk_sel_shift                             (16)
#define SYS_CLKSEL_cr_clksel_shift                                    (12)
#define SYS_CLKSEL_vdec_x27_clksel_shift                              (8)
#define SYS_CLKSEL_vbis0_yppsel_shift                                 (5)
#define SYS_CLKSEL_inv_vbis0_clk_shift                                (4)
#define SYS_CLKSEL_uart_clksel_shift                                  (0)
#define SYS_CLKSEL_epi_dbg_clksel_mask                                (0x01000000)
#define SYS_CLKSEL_epi_div_clksel_mask                                (0x00800000)
#define SYS_CLKSEL_sd_clksel_mask                                     (0x00700000)
#define SYS_CLKSEL_atvin_clk_sel_mask                                 (0x00020000)
#define SYS_CLKSEL_atvin_vd_clk_sel_mask                              (0x00010000)
#define SYS_CLKSEL_cr_clksel_mask                                     (0x00007000)
#define SYS_CLKSEL_vdec_x27_clksel_mask                               (0x00000100)
#define SYS_CLKSEL_vbis0_yppsel_mask                                  (0x00000020)
#define SYS_CLKSEL_inv_vbis0_clk_mask                                 (0x00000010)
#define SYS_CLKSEL_uart_clksel_mask                                   (0x00000001)
#define SYS_CLKSEL_epi_dbg_clksel(data)                               (0x01000000&((data)<<24))
#define SYS_CLKSEL_epi_div_clksel(data)                               (0x00800000&((data)<<23))
#define SYS_CLKSEL_sd_clksel(data)                                    (0x00700000&((data)<<20))
#define SYS_CLKSEL_atvin_clk_sel(data)                                (0x00020000&((data)<<17))
#define SYS_CLKSEL_atvin_vd_clk_sel(data)                             (0x00010000&((data)<<16))
#define SYS_CLKSEL_cr_clksel(data)                                    (0x00007000&((data)<<12))
#define SYS_CLKSEL_vdec_x27_clksel(data)                              (0x00000100&((data)<<8))
#define SYS_CLKSEL_vbis0_yppsel(data)                                 (0x00000020&((data)<<5))
#define SYS_CLKSEL_inv_vbis0_clk(data)                                (0x00000010&((data)<<4))
#define SYS_CLKSEL_uart_clksel(data)                                  (0x00000001&(data))
#define SYS_CLKSEL_get_epi_dbg_clksel(data)                           ((0x01000000&(data))>>24)
#define SYS_CLKSEL_get_epi_div_clksel(data)                           ((0x00800000&(data))>>23)
#define SYS_CLKSEL_get_sd_clksel(data)                                ((0x00700000&(data))>>20)
#define SYS_CLKSEL_get_atvin_clk_sel(data)                            ((0x00020000&(data))>>17)
#define SYS_CLKSEL_get_atvin_vd_clk_sel(data)                         ((0x00010000&(data))>>16)
#define SYS_CLKSEL_get_cr_clksel(data)                                ((0x00007000&(data))>>12)
#define SYS_CLKSEL_get_vdec_x27_clksel(data)                          ((0x00000100&(data))>>8)
#define SYS_CLKSEL_get_vbis0_yppsel(data)                             ((0x00000020&(data))>>5)
#define SYS_CLKSEL_get_inv_vbis0_clk(data)                            ((0x00000010&(data))>>4)
#define SYS_CLKSEL_get_uart_clksel(data)                              (0x00000001&(data))


#define SYS_CLKDIV                                                    0x18000214
#define SYS_CLKDIV_reg_addr                                           "0xb8000214"
#define SYS_CLKDIV_reg                                                0xb8000214
#define SYS_CLKDIV_inst_addr                                          "0x0085"
#define SYS_CLKDIV_inst                                               0x0085
#define SYS_CLKDIV_nf_clksel_shift                                    (8)
#define SYS_CLKDIV_dtv_demod_multi_req_disable_shift                  (4)
#define SYS_CLKDIV_demod_i2c_saddr_sel_shift                          (3)
#define SYS_CLKDIV_aud_dtv_freq_sel_shift                             (0)
#define SYS_CLKDIV_nf_clksel_mask                                     (0x00000700)
#define SYS_CLKDIV_dtv_demod_multi_req_disable_mask                   (0x00000010)
#define SYS_CLKDIV_demod_i2c_saddr_sel_mask                           (0x00000008)
#define SYS_CLKDIV_aud_dtv_freq_sel_mask                              (0x00000007)
#define SYS_CLKDIV_nf_clksel(data)                                    (0x00000700&((data)<<8))
#define SYS_CLKDIV_dtv_demod_multi_req_disable(data)                  (0x00000010&((data)<<4))
#define SYS_CLKDIV_demod_i2c_saddr_sel(data)                          (0x00000008&((data)<<3))
#define SYS_CLKDIV_aud_dtv_freq_sel(data)                             (0x00000007&(data))
#define SYS_CLKDIV_get_nf_clksel(data)                                ((0x00000700&(data))>>8)
#define SYS_CLKDIV_get_dtv_demod_multi_req_disable(data)              ((0x00000010&(data))>>4)
#define SYS_CLKDIV_get_demod_i2c_saddr_sel(data)                      ((0x00000008&(data))>>3)
#define SYS_CLKDIV_get_aud_dtv_freq_sel(data)                         (0x00000007&(data))


#define SYS_ARM_WD                                                    0x18000218
#define SYS_ARM_WD_reg_addr                                           "0xb8000218"
#define SYS_ARM_WD_reg                                                0xb8000218
#define SYS_ARM_WD_inst_addr                                          "0x0086"
#define SYS_ARM_WD_inst                                               0x0086
#define SYS_ARM_WD_arm_wd_en_shift                                    (16)
#define SYS_ARM_WD_arm_wd_cnt_shift                                   (0)
#define SYS_ARM_WD_arm_wd_en_mask                                     (0x00010000)
#define SYS_ARM_WD_arm_wd_cnt_mask                                    (0x00000FFF)
#define SYS_ARM_WD_arm_wd_en(data)                                    (0x00010000&((data)<<16))
#define SYS_ARM_WD_arm_wd_cnt(data)                                   (0x00000FFF&(data))
#define SYS_ARM_WD_get_arm_wd_en(data)                                ((0x00010000&(data))>>16)
#define SYS_ARM_WD_get_arm_wd_cnt(data)                               (0x00000FFF&(data))


#define SYS_TVSB1                                                     0x1800021c
#define SYS_TVSB1_reg_addr                                            "0xb800021c"
#define SYS_TVSB1_reg                                                 0xb800021c
#define SYS_TVSB1_inst_addr                                           "0x0087"
#define SYS_TVSB1_inst                                                0x0087
#define SYS_TVSB1_dummy1800021c_31_2_shift                            (2)
#define SYS_TVSB1_gpu_core2_clken_shift                               (1)
#define SYS_TVSB1_tvsb1_dc2_sel_shift                                 (0)
#define SYS_TVSB1_dummy1800021c_31_2_mask                             (0xFFFFFFFC)
#define SYS_TVSB1_gpu_core2_clken_mask                                (0x00000002)
#define SYS_TVSB1_tvsb1_dc2_sel_mask                                  (0x00000001)
#define SYS_TVSB1_dummy1800021c_31_2(data)                            (0xFFFFFFFC&((data)<<2))
#define SYS_TVSB1_gpu_core2_clken(data)                               (0x00000002&((data)<<1))
#define SYS_TVSB1_tvsb1_dc2_sel(data)                                 (0x00000001&(data))
#define SYS_TVSB1_get_dummy1800021c_31_2(data)                        ((0xFFFFFFFC&(data))>>2)
#define SYS_TVSB1_get_gpu_core2_clken(data)                           ((0x00000002&(data))>>1)
#define SYS_TVSB1_get_tvsb1_dc2_sel(data)                             (0x00000001&(data))


#define EFUSE_CTRL0                                                   0x18000240
#define EFUSE_CTRL0_reg_addr                                          "0xb8000240"
#define EFUSE_CTRL0_reg                                               0xb8000240
#define EFUSE_CTRL0_inst_addr                                         "0x0090"
#define EFUSE_CTRL0_inst                                              0x0090
#define EFUSE_CTRL0_efuse_ready_shift                                 (0)
#define EFUSE_CTRL0_efuse_ready_mask                                  (0x00000001)
#define EFUSE_CTRL0_efuse_ready(data)                                 (0x00000001&(data))
#define EFUSE_CTRL0_get_efuse_ready(data)                             (0x00000001&(data))


#define POWER_CTRL0                                                   0x18000260
#define POWER_CTRL0_reg_addr                                          "0xb8000260"
#define POWER_CTRL0_reg                                               0xb8000260
#define POWER_CTRL0_inst_addr                                         "0x0098"
#define POWER_CTRL0_inst                                              0x0098
#define POWER_CTRL0_atv_iso_en_shift                                  (12)
#define POWER_CTRL0_atv_wek_status_shift                              (11)
#define POWER_CTRL0_atv_str_status_shift                              (10)
#define POWER_CTRL0_atv_wek_pow_shift                                 (9)
#define POWER_CTRL0_atv_str_pow_shift                                 (8)
#define POWER_CTRL0_dtv_iso_en_shift                                  (4)
#define POWER_CTRL0_dtv_wek_status_shift                              (3)
#define POWER_CTRL0_dtv_str_status_shift                              (2)
#define POWER_CTRL0_dtv_wek_pow_shift                                 (1)
#define POWER_CTRL0_dtv_str_pow_shift                                 (0)
#define POWER_CTRL0_atv_iso_en_mask                                   (0x00001000)
#define POWER_CTRL0_atv_wek_status_mask                               (0x00000800)
#define POWER_CTRL0_atv_str_status_mask                               (0x00000400)
#define POWER_CTRL0_atv_wek_pow_mask                                  (0x00000200)
#define POWER_CTRL0_atv_str_pow_mask                                  (0x00000100)
#define POWER_CTRL0_dtv_iso_en_mask                                   (0x00000010)
#define POWER_CTRL0_dtv_wek_status_mask                               (0x00000008)
#define POWER_CTRL0_dtv_str_status_mask                               (0x00000004)
#define POWER_CTRL0_dtv_wek_pow_mask                                  (0x00000002)
#define POWER_CTRL0_dtv_str_pow_mask                                  (0x00000001)
#define POWER_CTRL0_atv_iso_en(data)                                  (0x00001000&((data)<<12))
#define POWER_CTRL0_atv_wek_status(data)                              (0x00000800&((data)<<11))
#define POWER_CTRL0_atv_str_status(data)                              (0x00000400&((data)<<10))
#define POWER_CTRL0_atv_wek_pow(data)                                 (0x00000200&((data)<<9))
#define POWER_CTRL0_atv_str_pow(data)                                 (0x00000100&((data)<<8))
#define POWER_CTRL0_dtv_iso_en(data)                                  (0x00000010&((data)<<4))
#define POWER_CTRL0_dtv_wek_status(data)                              (0x00000008&((data)<<3))
#define POWER_CTRL0_dtv_str_status(data)                              (0x00000004&((data)<<2))
#define POWER_CTRL0_dtv_wek_pow(data)                                 (0x00000002&((data)<<1))
#define POWER_CTRL0_dtv_str_pow(data)                                 (0x00000001&(data))
#define POWER_CTRL0_get_atv_iso_en(data)                              ((0x00001000&(data))>>12)
#define POWER_CTRL0_get_atv_wek_status(data)                          ((0x00000800&(data))>>11)
#define POWER_CTRL0_get_atv_str_status(data)                          ((0x00000400&(data))>>10)
#define POWER_CTRL0_get_atv_wek_pow(data)                             ((0x00000200&(data))>>9)
#define POWER_CTRL0_get_atv_str_pow(data)                             ((0x00000100&(data))>>8)
#define POWER_CTRL0_get_dtv_iso_en(data)                              ((0x00000010&(data))>>4)
#define POWER_CTRL0_get_dtv_wek_status(data)                          ((0x00000008&(data))>>3)
#define POWER_CTRL0_get_dtv_str_status(data)                          ((0x00000004&(data))>>2)
#define POWER_CTRL0_get_dtv_wek_pow(data)                             ((0x00000002&(data))>>1)
#define POWER_CTRL0_get_dtv_str_pow(data)                             (0x00000001&(data))


#define TM_CTRL0                                                      0x18000280
#define TM_CTRL0_reg_addr                                             "0xb8000280"
#define TM_CTRL0_reg                                                  0xb8000280
#define TM_CTRL0_inst_addr                                            "0x00A0"
#define TM_CTRL0_inst                                                 0x00A0
#define TM_CTRL0_tm_enable_shift                                      (27)
#define TM_CTRL0_tm_data_valid_shift                                  (26)
#define TM_CTRL0_tm_data_sampled_shift                                (25)
#define TM_CTRL0_tm_reverse_cmp_out_shift                             (24)
#define TM_CTRL0_tm_data_out_shift                                    (16)
#define TM_CTRL0_tm_pwron_dly_shift                                   (0)
#define TM_CTRL0_tm_enable_mask                                       (0x08000000)
#define TM_CTRL0_tm_data_valid_mask                                   (0x04000000)
#define TM_CTRL0_tm_data_sampled_mask                                 (0x02000000)
#define TM_CTRL0_tm_reverse_cmp_out_mask                              (0x01000000)
#define TM_CTRL0_tm_data_out_mask                                     (0x003F0000)
#define TM_CTRL0_tm_pwron_dly_mask                                    (0x0000FFFF)
#define TM_CTRL0_tm_enable(data)                                      (0x08000000&((data)<<27))
#define TM_CTRL0_tm_data_valid(data)                                  (0x04000000&((data)<<26))
#define TM_CTRL0_tm_data_sampled(data)                                (0x02000000&((data)<<25))
#define TM_CTRL0_tm_reverse_cmp_out(data)                             (0x01000000&((data)<<24))
#define TM_CTRL0_tm_data_out(data)                                    (0x003F0000&((data)<<16))
#define TM_CTRL0_tm_pwron_dly(data)                                   (0x0000FFFF&(data))
#define TM_CTRL0_get_tm_enable(data)                                  ((0x08000000&(data))>>27)
#define TM_CTRL0_get_tm_data_valid(data)                              ((0x04000000&(data))>>26)
#define TM_CTRL0_get_tm_data_sampled(data)                            ((0x02000000&(data))>>25)
#define TM_CTRL0_get_tm_reverse_cmp_out(data)                         ((0x01000000&(data))>>24)
#define TM_CTRL0_get_tm_data_out(data)                                ((0x003F0000&(data))>>16)
#define TM_CTRL0_get_tm_pwron_dly(data)                               (0x0000FFFF&(data))


#define TM_CTRL1                                                      0x18000284
#define TM_CTRL1_reg_addr                                             "0xb8000284"
#define TM_CTRL1_reg                                                  0xb8000284
#define TM_CTRL1_inst_addr                                            "0x00A1"
#define TM_CTRL1_inst                                                 0x00A1
#define TM_CTRL1_tm_compare_dly_shift                                 (16)
#define TM_CTRL1_tm_sample_dly_shift                                  (0)
#define TM_CTRL1_tm_compare_dly_mask                                  (0xFFFF0000)
#define TM_CTRL1_tm_sample_dly_mask                                   (0x0000FFFF)
#define TM_CTRL1_tm_compare_dly(data)                                 (0xFFFF0000&((data)<<16))
#define TM_CTRL1_tm_sample_dly(data)                                  (0x0000FFFF&(data))
#define TM_CTRL1_get_tm_compare_dly(data)                             ((0xFFFF0000&(data))>>16)
#define TM_CTRL1_get_tm_sample_dly(data)                              (0x0000FFFF&(data))


#define TM_CTRL2                                                      0x1800028c
#define TM_CTRL2_reg_addr                                             "0xb800028c"
#define TM_CTRL2_reg                                                  0xb800028c
#define TM_CTRL2_inst_addr                                            "0x00A3"
#define TM_CTRL2_inst                                                 0x00A3
#define TM_CTRL2_tm_sbg_shift                                         (7)
#define TM_CTRL2_tm_sos_shift                                         (4)
#define TM_CTRL2_tm_sinl_shift                                        (2)
#define TM_CTRL2_tm_sbg_mask                                          (0x00000380)
#define TM_CTRL2_tm_sos_mask                                          (0x00000070)
#define TM_CTRL2_tm_sinl_mask                                         (0x0000000C)
#define TM_CTRL2_tm_sbg(data)                                         (0x00000380&((data)<<7))
#define TM_CTRL2_tm_sos(data)                                         (0x00000070&((data)<<4))
#define TM_CTRL2_tm_sinl(data)                                        (0x0000000C&((data)<<2))
#define TM_CTRL2_get_tm_sbg(data)                                     ((0x00000380&(data))>>7)
#define TM_CTRL2_get_tm_sos(data)                                     ((0x00000070&(data))>>4)
#define TM_CTRL2_get_tm_sinl(data)                                    ((0x0000000C&(data))>>2)


#define SS_12T_LVT_0                                                  0x18008f50
#define SS_12T_LVT_0_reg_addr                                         "0xb8008f50"
#define SS_12T_LVT_0_reg                                              0xb8008f50
#define SS_12T_LVT_0_inst_addr                                        "0x03D4"
#define SS_12T_LVT_0_inst                                             0x03D4
#define SS_12T_LVT_0_data_in_shift                                    (8)
#define SS_12T_LVT_0_data_in_ready_shift                              (5)
#define SS_12T_LVT_0_wire_sel_shift                                   (4)
#define SS_12T_LVT_0_ro_sel_shift                                     (1)
#define SS_12T_LVT_0_dss_rst_n_shift                                  (0)
#define SS_12T_LVT_0_data_in_mask                                     (0x0FFFFF00)
#define SS_12T_LVT_0_data_in_ready_mask                               (0x00000020)
#define SS_12T_LVT_0_wire_sel_mask                                    (0x00000010)
#define SS_12T_LVT_0_ro_sel_mask                                      (0x0000000E)
#define SS_12T_LVT_0_dss_rst_n_mask                                   (0x00000001)
#define SS_12T_LVT_0_data_in(data)                                    (0x0FFFFF00&((data)<<8))
#define SS_12T_LVT_0_data_in_ready(data)                              (0x00000020&((data)<<5))
#define SS_12T_LVT_0_wire_sel(data)                                   (0x00000010&((data)<<4))
#define SS_12T_LVT_0_ro_sel(data)                                     (0x0000000E&((data)<<1))
#define SS_12T_LVT_0_dss_rst_n(data)                                  (0x00000001&(data))
#define SS_12T_LVT_0_get_data_in(data)                                ((0x0FFFFF00&(data))>>8)
#define SS_12T_LVT_0_get_data_in_ready(data)                          ((0x00000020&(data))>>5)
#define SS_12T_LVT_0_get_wire_sel(data)                               ((0x00000010&(data))>>4)
#define SS_12T_LVT_0_get_ro_sel(data)                                 ((0x0000000E&(data))>>1)
#define SS_12T_LVT_0_get_dss_rst_n(data)                              (0x00000001&(data))


#define SS_12T_LVT_1                                                  0x18008f54
#define SS_12T_LVT_1_reg_addr                                         "0xb8008f54"
#define SS_12T_LVT_1_reg                                              0xb8008f54
#define SS_12T_LVT_1_inst_addr                                        "0x03D5"
#define SS_12T_LVT_1_inst                                             0x03D5
#define SS_12T_LVT_1_count_out_shift                                  (4)
#define SS_12T_LVT_1_wsort_go_shift                                   (1)
#define SS_12T_LVT_1_ready_shift                                      (0)
#define SS_12T_LVT_1_count_out_mask                                   (0x00FFFFF0)
#define SS_12T_LVT_1_wsort_go_mask                                    (0x00000002)
#define SS_12T_LVT_1_ready_mask                                       (0x00000001)
#define SS_12T_LVT_1_count_out(data)                                  (0x00FFFFF0&((data)<<4))
#define SS_12T_LVT_1_wsort_go(data)                                   (0x00000002&((data)<<1))
#define SS_12T_LVT_1_ready(data)                                      (0x00000001&(data))
#define SS_12T_LVT_1_get_count_out(data)                              ((0x00FFFFF0&(data))>>4)
#define SS_12T_LVT_1_get_wsort_go(data)                               ((0x00000002&(data))>>1)
#define SS_12T_LVT_1_get_ready(data)                                  (0x00000001&(data))


#define SS_12T_RVT_0                                                  0x18000298
#define SS_12T_RVT_0_reg_addr                                         "0xb8000298"
#define SS_12T_RVT_0_reg                                              0xb8000298
#define SS_12T_RVT_0_inst_addr                                        "0x00A6"
#define SS_12T_RVT_0_inst                                             0x00A6
#define SS_12T_RVT_0_rvt_12t_dss_rst_n_shift                          (31)
#define SS_12T_RVT_0_rvt_12t_ro_sel_shift                             (25)
#define SS_12T_RVT_0_rvt_12t_wire_sel_shift                           (24)
#define SS_12T_RVT_0_rvt_12t_ready_shift                              (20)
#define SS_12T_RVT_0_rvt_12t_count_out_shift                          (0)
#define SS_12T_RVT_0_rvt_12t_dss_rst_n_mask                           (0x80000000)
#define SS_12T_RVT_0_rvt_12t_ro_sel_mask                              (0x0E000000)
#define SS_12T_RVT_0_rvt_12t_wire_sel_mask                            (0x01000000)
#define SS_12T_RVT_0_rvt_12t_ready_mask                               (0x00100000)
#define SS_12T_RVT_0_rvt_12t_count_out_mask                           (0x000FFFFF)
#define SS_12T_RVT_0_rvt_12t_dss_rst_n(data)                          (0x80000000&((data)<<31))
#define SS_12T_RVT_0_rvt_12t_ro_sel(data)                             (0x0E000000&((data)<<25))
#define SS_12T_RVT_0_rvt_12t_wire_sel(data)                           (0x01000000&((data)<<24))
#define SS_12T_RVT_0_rvt_12t_ready(data)                              (0x00100000&((data)<<20))
#define SS_12T_RVT_0_rvt_12t_count_out(data)                          (0x000FFFFF&(data))
#define SS_12T_RVT_0_get_rvt_12t_dss_rst_n(data)                      ((0x80000000&(data))>>31)
#define SS_12T_RVT_0_get_rvt_12t_ro_sel(data)                         ((0x0E000000&(data))>>25)
#define SS_12T_RVT_0_get_rvt_12t_wire_sel(data)                       ((0x01000000&(data))>>24)
#define SS_12T_RVT_0_get_rvt_12t_ready(data)                          ((0x00100000&(data))>>20)
#define SS_12T_RVT_0_get_rvt_12t_count_out(data)                      (0x000FFFFF&(data))


#define SS_12T_RVT_1                                                  0x1800029c
#define SS_12T_RVT_1_reg_addr                                         "0xb800029c"
#define SS_12T_RVT_1_reg                                              0xb800029c
#define SS_12T_RVT_1_inst_addr                                        "0x00A7"
#define SS_12T_RVT_1_inst                                             0x00A7
#define SS_12T_RVT_1_rvt_12t_data_in_ready_shift                      (24)
#define SS_12T_RVT_1_rvt_12t_data_in_shift                            (4)
#define SS_12T_RVT_1_rvt_12t_data_read_ack_shift                      (1)
#define SS_12T_RVT_1_rvt_12t_wsort_go_shift                           (0)
#define SS_12T_RVT_1_rvt_12t_data_in_ready_mask                       (0x01000000)
#define SS_12T_RVT_1_rvt_12t_data_in_mask                             (0x00FFFFF0)
#define SS_12T_RVT_1_rvt_12t_data_read_ack_mask                       (0x00000002)
#define SS_12T_RVT_1_rvt_12t_wsort_go_mask                            (0x00000001)
#define SS_12T_RVT_1_rvt_12t_data_in_ready(data)                      (0x01000000&((data)<<24))
#define SS_12T_RVT_1_rvt_12t_data_in(data)                            (0x00FFFFF0&((data)<<4))
#define SS_12T_RVT_1_rvt_12t_data_read_ack(data)                      (0x00000002&((data)<<1))
#define SS_12T_RVT_1_rvt_12t_wsort_go(data)                           (0x00000001&(data))
#define SS_12T_RVT_1_get_rvt_12t_data_in_ready(data)                  ((0x01000000&(data))>>24)
#define SS_12T_RVT_1_get_rvt_12t_data_in(data)                        ((0x00FFFFF0&(data))>>4)
#define SS_12T_RVT_1_get_rvt_12t_data_read_ack(data)                  ((0x00000002&(data))>>1)
#define SS_12T_RVT_1_get_rvt_12t_wsort_go(data)                       (0x00000001&(data))


#define SS_9T_LVT_0                                                   0x18000340
#define SS_9T_LVT_0_reg_addr                                          "0xb8000340"
#define SS_9T_LVT_0_reg                                               0xb8000340
#define SS_9T_LVT_0_inst_addr                                         "0x00D0"
#define SS_9T_LVT_0_inst                                              0x00D0
#define SS_9T_LVT_0_lvt_9t_dss_rst_n_shift                            (31)
#define SS_9T_LVT_0_lvt_9t_ro_sel_shift                               (25)
#define SS_9T_LVT_0_lvt_9t_wire_sel_shift                             (24)
#define SS_9T_LVT_0_lvt_9t_ready_shift                                (20)
#define SS_9T_LVT_0_lvt_9t_count_out_shift                            (0)
#define SS_9T_LVT_0_lvt_9t_dss_rst_n_mask                             (0x80000000)
#define SS_9T_LVT_0_lvt_9t_ro_sel_mask                                (0x0E000000)
#define SS_9T_LVT_0_lvt_9t_wire_sel_mask                              (0x01000000)
#define SS_9T_LVT_0_lvt_9t_ready_mask                                 (0x00100000)
#define SS_9T_LVT_0_lvt_9t_count_out_mask                             (0x000FFFFF)
#define SS_9T_LVT_0_lvt_9t_dss_rst_n(data)                            (0x80000000&((data)<<31))
#define SS_9T_LVT_0_lvt_9t_ro_sel(data)                               (0x0E000000&((data)<<25))
#define SS_9T_LVT_0_lvt_9t_wire_sel(data)                             (0x01000000&((data)<<24))
#define SS_9T_LVT_0_lvt_9t_ready(data)                                (0x00100000&((data)<<20))
#define SS_9T_LVT_0_lvt_9t_count_out(data)                            (0x000FFFFF&(data))
#define SS_9T_LVT_0_get_lvt_9t_dss_rst_n(data)                        ((0x80000000&(data))>>31)
#define SS_9T_LVT_0_get_lvt_9t_ro_sel(data)                           ((0x0E000000&(data))>>25)
#define SS_9T_LVT_0_get_lvt_9t_wire_sel(data)                         ((0x01000000&(data))>>24)
#define SS_9T_LVT_0_get_lvt_9t_ready(data)                            ((0x00100000&(data))>>20)
#define SS_9T_LVT_0_get_lvt_9t_count_out(data)                        (0x000FFFFF&(data))


#define SS_9T_LVT_1                                                   0x18000344
#define SS_9T_LVT_1_reg_addr                                          "0xb8000344"
#define SS_9T_LVT_1_reg                                               0xb8000344
#define SS_9T_LVT_1_inst_addr                                         "0x00D1"
#define SS_9T_LVT_1_inst                                              0x00D1
#define SS_9T_LVT_1_lvt_9t_data_in_ready_shift                        (24)
#define SS_9T_LVT_1_lvt_9t_data_in_shift                              (4)
#define SS_9T_LVT_1_lvt_9t_data_read_ack_shift                        (1)
#define SS_9T_LVT_1_lvt_9t_wsort_go_shift                             (0)
#define SS_9T_LVT_1_lvt_9t_data_in_ready_mask                         (0x01000000)
#define SS_9T_LVT_1_lvt_9t_data_in_mask                               (0x00FFFFF0)
#define SS_9T_LVT_1_lvt_9t_data_read_ack_mask                         (0x00000002)
#define SS_9T_LVT_1_lvt_9t_wsort_go_mask                              (0x00000001)
#define SS_9T_LVT_1_lvt_9t_data_in_ready(data)                        (0x01000000&((data)<<24))
#define SS_9T_LVT_1_lvt_9t_data_in(data)                              (0x00FFFFF0&((data)<<4))
#define SS_9T_LVT_1_lvt_9t_data_read_ack(data)                        (0x00000002&((data)<<1))
#define SS_9T_LVT_1_lvt_9t_wsort_go(data)                             (0x00000001&(data))
#define SS_9T_LVT_1_get_lvt_9t_data_in_ready(data)                    ((0x01000000&(data))>>24)
#define SS_9T_LVT_1_get_lvt_9t_data_in(data)                          ((0x00FFFFF0&(data))>>4)
#define SS_9T_LVT_1_get_lvt_9t_data_read_ack(data)                    ((0x00000002&(data))>>1)
#define SS_9T_LVT_1_get_lvt_9t_wsort_go(data)                         (0x00000001&(data))


#define SS_9T_RVT_0                                                   0x18000348
#define SS_9T_RVT_0_reg_addr                                          "0xb8000348"
#define SS_9T_RVT_0_reg                                               0xb8000348
#define SS_9T_RVT_0_inst_addr                                         "0x00D2"
#define SS_9T_RVT_0_inst                                              0x00D2
#define SS_9T_RVT_0_rvt_9t_dss_rst_n_shift                            (31)
#define SS_9T_RVT_0_rvt_9t_ro_sel_shift                               (25)
#define SS_9T_RVT_0_rvt_9t_wire_sel_shift                             (24)
#define SS_9T_RVT_0_rvt_9t_ready_shift                                (20)
#define SS_9T_RVT_0_rvt_9t_count_out_shift                            (0)
#define SS_9T_RVT_0_rvt_9t_dss_rst_n_mask                             (0x80000000)
#define SS_9T_RVT_0_rvt_9t_ro_sel_mask                                (0x0E000000)
#define SS_9T_RVT_0_rvt_9t_wire_sel_mask                              (0x01000000)
#define SS_9T_RVT_0_rvt_9t_ready_mask                                 (0x00100000)
#define SS_9T_RVT_0_rvt_9t_count_out_mask                             (0x000FFFFF)
#define SS_9T_RVT_0_rvt_9t_dss_rst_n(data)                            (0x80000000&((data)<<31))
#define SS_9T_RVT_0_rvt_9t_ro_sel(data)                               (0x0E000000&((data)<<25))
#define SS_9T_RVT_0_rvt_9t_wire_sel(data)                             (0x01000000&((data)<<24))
#define SS_9T_RVT_0_rvt_9t_ready(data)                                (0x00100000&((data)<<20))
#define SS_9T_RVT_0_rvt_9t_count_out(data)                            (0x000FFFFF&(data))
#define SS_9T_RVT_0_get_rvt_9t_dss_rst_n(data)                        ((0x80000000&(data))>>31)
#define SS_9T_RVT_0_get_rvt_9t_ro_sel(data)                           ((0x0E000000&(data))>>25)
#define SS_9T_RVT_0_get_rvt_9t_wire_sel(data)                         ((0x01000000&(data))>>24)
#define SS_9T_RVT_0_get_rvt_9t_ready(data)                            ((0x00100000&(data))>>20)
#define SS_9T_RVT_0_get_rvt_9t_count_out(data)                        (0x000FFFFF&(data))


#define SS_9T_RVT_1                                                   0x1800034c
#define SS_9T_RVT_1_reg_addr                                          "0xb800034c"
#define SS_9T_RVT_1_reg                                               0xb800034c
#define SS_9T_RVT_1_inst_addr                                         "0x00D3"
#define SS_9T_RVT_1_inst                                              0x00D3
#define SS_9T_RVT_1_rvt_9t_data_in_ready_shift                        (24)
#define SS_9T_RVT_1_rvt_9t_data_in_shift                              (4)
#define SS_9T_RVT_1_rvt_9t_data_read_ack_shift                        (1)
#define SS_9T_RVT_1_rvt_9t_wsort_go_shift                             (0)
#define SS_9T_RVT_1_rvt_9t_data_in_ready_mask                         (0x01000000)
#define SS_9T_RVT_1_rvt_9t_data_in_mask                               (0x00FFFFF0)
#define SS_9T_RVT_1_rvt_9t_data_read_ack_mask                         (0x00000002)
#define SS_9T_RVT_1_rvt_9t_wsort_go_mask                              (0x00000001)
#define SS_9T_RVT_1_rvt_9t_data_in_ready(data)                        (0x01000000&((data)<<24))
#define SS_9T_RVT_1_rvt_9t_data_in(data)                              (0x00FFFFF0&((data)<<4))
#define SS_9T_RVT_1_rvt_9t_data_read_ack(data)                        (0x00000002&((data)<<1))
#define SS_9T_RVT_1_rvt_9t_wsort_go(data)                             (0x00000001&(data))
#define SS_9T_RVT_1_get_rvt_9t_data_in_ready(data)                    ((0x01000000&(data))>>24)
#define SS_9T_RVT_1_get_rvt_9t_data_in(data)                          ((0x00FFFFF0&(data))>>4)
#define SS_9T_RVT_1_get_rvt_9t_data_read_ack(data)                    ((0x00000002&(data))>>1)
#define SS_9T_RVT_1_get_rvt_9t_wsort_go(data)                         (0x00000001&(data))


#define SS_7T_0                                                       0x1801c3f0
#define SS_7T_0_reg_addr                                              "0xb801c3f0"
#define SS_7T_0_reg                                                   0xb801c3f0
#define SS_7T_0_inst_addr                                             "0x00FC"
#define SS_7T_0_inst                                                  0x00FC
#define SS_7T_0_rlvt_7t_dss_rst_n_shift                               (31)
#define SS_7T_0_rlvt_7t_ro_sel_shift                                  (25)
#define SS_7T_0_rlvt_7t_wire_sel_shift                                (24)
#define SS_7T_0_rlvt_7t_ready_shift                                   (20)
#define SS_7T_0_rlvt_7t_count_out_shift                               (0)
#define SS_7T_0_rlvt_7t_dss_rst_n_mask                                (0x80000000)
#define SS_7T_0_rlvt_7t_ro_sel_mask                                   (0x0E000000)
#define SS_7T_0_rlvt_7t_wire_sel_mask                                 (0x01000000)
#define SS_7T_0_rlvt_7t_ready_mask                                    (0x00100000)
#define SS_7T_0_rlvt_7t_count_out_mask                                (0x000FFFFF)
#define SS_7T_0_rlvt_7t_dss_rst_n(data)                               (0x80000000&((data)<<31))
#define SS_7T_0_rlvt_7t_ro_sel(data)                                  (0x0E000000&((data)<<25))
#define SS_7T_0_rlvt_7t_wire_sel(data)                                (0x01000000&((data)<<24))
#define SS_7T_0_rlvt_7t_ready(data)                                   (0x00100000&((data)<<20))
#define SS_7T_0_rlvt_7t_count_out(data)                               (0x000FFFFF&(data))
#define SS_7T_0_get_rlvt_7t_dss_rst_n(data)                           ((0x80000000&(data))>>31)
#define SS_7T_0_get_rlvt_7t_ro_sel(data)                              ((0x0E000000&(data))>>25)
#define SS_7T_0_get_rlvt_7t_wire_sel(data)                            ((0x01000000&(data))>>24)
#define SS_7T_0_get_rlvt_7t_ready(data)                               ((0x00100000&(data))>>20)
#define SS_7T_0_get_rlvt_7t_count_out(data)                           (0x000FFFFF&(data))


#define SS_7T_1                                                       0x1801c3f4
#define SS_7T_1_reg_addr                                              "0xb801c3f4"
#define SS_7T_1_reg                                                   0xb801c3f4
#define SS_7T_1_inst_addr                                             "0x00FD"
#define SS_7T_1_inst                                                  0x00FD
#define SS_7T_1_rlvt_7t_data_in_ready_shift                           (24)
#define SS_7T_1_rlvt_7t_data_in_shift                                 (4)
#define SS_7T_1_rlvt_7t_data_read_ack_shift                           (1)
#define SS_7T_1_rlvt_7t_wsort_go_shift                                (0)
#define SS_7T_1_rlvt_7t_data_in_ready_mask                            (0x01000000)
#define SS_7T_1_rlvt_7t_data_in_mask                                  (0x00FFFFF0)
#define SS_7T_1_rlvt_7t_data_read_ack_mask                            (0x00000002)
#define SS_7T_1_rlvt_7t_wsort_go_mask                                 (0x00000001)
#define SS_7T_1_rlvt_7t_data_in_ready(data)                           (0x01000000&((data)<<24))
#define SS_7T_1_rlvt_7t_data_in(data)                                 (0x00FFFFF0&((data)<<4))
#define SS_7T_1_rlvt_7t_data_read_ack(data)                           (0x00000002&((data)<<1))
#define SS_7T_1_rlvt_7t_wsort_go(data)                                (0x00000001&(data))
#define SS_7T_1_get_rlvt_7t_data_in_ready(data)                       ((0x01000000&(data))>>24)
#define SS_7T_1_get_rlvt_7t_data_in(data)                             ((0x00FFFFF0&(data))>>4)
#define SS_7T_1_get_rlvt_7t_data_read_ack(data)                       ((0x00000002&(data))>>1)
#define SS_7T_1_get_rlvt_7t_wsort_go(data)                            (0x00000001&(data))


#define SC_DEBUG_0                                                    0x18000310
#define SC_DEBUG_0_reg_addr                                           "0xb8000310"
#define SC_DEBUG_0_reg                                                0xb8000310
#define SC_DEBUG_0_inst_addr                                          "0x00C4"
#define SC_DEBUG_0_inst                                               0x00C4
#define SC_DEBUG_0_dbg0_div_sel_shift                                 (16)
#define SC_DEBUG_0_top_ssc_dbg_sel_shift                              (9)
#define SC_DEBUG_0_crt_dbg_sel_shift                                  (0)
#define SC_DEBUG_0_dbg0_div_sel_mask                                  (0x00030000)
#define SC_DEBUG_0_top_ssc_dbg_sel_mask                               (0x00000E00)
#define SC_DEBUG_0_crt_dbg_sel_mask                                   (0x000000FF)
#define SC_DEBUG_0_dbg0_div_sel(data)                                 (0x00030000&((data)<<16))
#define SC_DEBUG_0_top_ssc_dbg_sel(data)                              (0x00000E00&((data)<<9))
#define SC_DEBUG_0_crt_dbg_sel(data)                                  (0x000000FF&(data))
#define SC_DEBUG_0_get_dbg0_div_sel(data)                             ((0x00030000&(data))>>16)
#define SC_DEBUG_0_get_top_ssc_dbg_sel(data)                          ((0x00000E00&(data))>>9)
#define SC_DEBUG_0_get_crt_dbg_sel(data)                              (0x000000FF&(data))


#define SYS_PLL_SCPU1                                                 0x18000400
#define SYS_PLL_SCPU1_reg_addr                                        "0xb8000400"
#define SYS_PLL_SCPU1_reg                                             0xb8000400
#define SYS_PLL_SCPU1_inst_addr                                       "0x0100"
#define SYS_PLL_SCPU1_inst                                            0x0100
#define SYS_PLL_SCPU1_pllscpu_cp_shift                                (22)
#define SYS_PLL_SCPU1_pllscpu_n_shift                                 (20)
#define SYS_PLL_SCPU1_pllscpu_m_shift                                 (12)
#define SYS_PLL_SCPU1_pllscpu_ip_shift                                (9)
#define SYS_PLL_SCPU1_pllscpu_o_shift                                 (7)
#define SYS_PLL_SCPU1_pllscpu_wdset_shift                             (6)
#define SYS_PLL_SCPU1_pllscpu_wdrst_shift                             (5)
#define SYS_PLL_SCPU1_pllscpu_cs_shift                                (3)
#define SYS_PLL_SCPU1_pllscpu_rs_shift                                (0)
#define SYS_PLL_SCPU1_pllscpu_cp_mask                                 (0x00C00000)
#define SYS_PLL_SCPU1_pllscpu_n_mask                                  (0x00300000)
#define SYS_PLL_SCPU1_pllscpu_m_mask                                  (0x000FF000)
#define SYS_PLL_SCPU1_pllscpu_ip_mask                                 (0x00000E00)
#define SYS_PLL_SCPU1_pllscpu_o_mask                                  (0x00000180)
#define SYS_PLL_SCPU1_pllscpu_wdset_mask                              (0x00000040)
#define SYS_PLL_SCPU1_pllscpu_wdrst_mask                              (0x00000020)
#define SYS_PLL_SCPU1_pllscpu_cs_mask                                 (0x00000018)
#define SYS_PLL_SCPU1_pllscpu_rs_mask                                 (0x00000007)
#define SYS_PLL_SCPU1_pllscpu_cp(data)                                (0x00C00000&((data)<<22))
#define SYS_PLL_SCPU1_pllscpu_n(data)                                 (0x00300000&((data)<<20))
#define SYS_PLL_SCPU1_pllscpu_m(data)                                 (0x000FF000&((data)<<12))
#define SYS_PLL_SCPU1_pllscpu_ip(data)                                (0x00000E00&((data)<<9))
#define SYS_PLL_SCPU1_pllscpu_o(data)                                 (0x00000180&((data)<<7))
#define SYS_PLL_SCPU1_pllscpu_wdset(data)                             (0x00000040&((data)<<6))
#define SYS_PLL_SCPU1_pllscpu_wdrst(data)                             (0x00000020&((data)<<5))
#define SYS_PLL_SCPU1_pllscpu_cs(data)                                (0x00000018&((data)<<3))
#define SYS_PLL_SCPU1_pllscpu_rs(data)                                (0x00000007&(data))
#define SYS_PLL_SCPU1_get_pllscpu_cp(data)                            ((0x00C00000&(data))>>22)
#define SYS_PLL_SCPU1_get_pllscpu_n(data)                             ((0x00300000&(data))>>20)
#define SYS_PLL_SCPU1_get_pllscpu_m(data)                             ((0x000FF000&(data))>>12)
#define SYS_PLL_SCPU1_get_pllscpu_ip(data)                            ((0x00000E00&(data))>>9)
#define SYS_PLL_SCPU1_get_pllscpu_o(data)                             ((0x00000180&(data))>>7)
#define SYS_PLL_SCPU1_get_pllscpu_wdset(data)                         ((0x00000040&(data))>>6)
#define SYS_PLL_SCPU1_get_pllscpu_wdrst(data)                         ((0x00000020&(data))>>5)
#define SYS_PLL_SCPU1_get_pllscpu_cs(data)                            ((0x00000018&(data))>>3)
#define SYS_PLL_SCPU1_get_pllscpu_rs(data)                            (0x00000007&(data))


#define SYS_PLL_SCPU2                                                 0x18000404
#define SYS_PLL_SCPU2_reg_addr                                        "0xb8000404"
#define SYS_PLL_SCPU2_reg                                             0xb8000404
#define SYS_PLL_SCPU2_inst_addr                                       "0x0101"
#define SYS_PLL_SCPU2_inst                                            0x0101
#define SYS_PLL_SCPU2_pllscpu_vcorb_shift                             (3)
#define SYS_PLL_SCPU2_pllscpu_oeb_shift                               (2)
#define SYS_PLL_SCPU2_pllscpu_rstb_shift                              (1)
#define SYS_PLL_SCPU2_pllscpu_pow_shift                               (0)
#define SYS_PLL_SCPU2_pllscpu_vcorb_mask                              (0x00000008)
#define SYS_PLL_SCPU2_pllscpu_oeb_mask                                (0x00000004)
#define SYS_PLL_SCPU2_pllscpu_rstb_mask                               (0x00000002)
#define SYS_PLL_SCPU2_pllscpu_pow_mask                                (0x00000001)
#define SYS_PLL_SCPU2_pllscpu_vcorb(data)                             (0x00000008&((data)<<3))
#define SYS_PLL_SCPU2_pllscpu_oeb(data)                               (0x00000004&((data)<<2))
#define SYS_PLL_SCPU2_pllscpu_rstb(data)                              (0x00000002&((data)<<1))
#define SYS_PLL_SCPU2_pllscpu_pow(data)                               (0x00000001&(data))
#define SYS_PLL_SCPU2_get_pllscpu_vcorb(data)                         ((0x00000008&(data))>>3)
#define SYS_PLL_SCPU2_get_pllscpu_oeb(data)                           ((0x00000004&(data))>>2)
#define SYS_PLL_SCPU2_get_pllscpu_rstb(data)                          ((0x00000002&(data))>>1)
#define SYS_PLL_SCPU2_get_pllscpu_pow(data)                           (0x00000001&(data))


#define SYS_PLL_ACPU1                                                 0x18000408
#define SYS_PLL_ACPU1_reg_addr                                        "0xb8000408"
#define SYS_PLL_ACPU1_reg                                             0xb8000408
#define SYS_PLL_ACPU1_inst_addr                                       "0x0102"
#define SYS_PLL_ACPU1_inst                                            0x0102
#define SYS_PLL_ACPU1_pllacpu_tst_shift                               (24)
#define SYS_PLL_ACPU1_pllacpu_n_shift                                 (20)
#define SYS_PLL_ACPU1_pllacpu_m_shift                                 (12)
#define SYS_PLL_ACPU1_pllacpu_ip_shift                                (9)
#define SYS_PLL_ACPU1_pllacpu_o_shift                                 (7)
#define SYS_PLL_ACPU1_pllacpu_wdset_shift                             (6)
#define SYS_PLL_ACPU1_pllacpu_wdrst_shift                             (5)
#define SYS_PLL_ACPU1_pllacpu_cs_shift                                (3)
#define SYS_PLL_ACPU1_pllacpu_rs_shift                                (0)
#define SYS_PLL_ACPU1_pllacpu_tst_mask                                (0x01000000)
#define SYS_PLL_ACPU1_pllacpu_n_mask                                  (0x00300000)
#define SYS_PLL_ACPU1_pllacpu_m_mask                                  (0x0007F000)
#define SYS_PLL_ACPU1_pllacpu_ip_mask                                 (0x00000E00)
#define SYS_PLL_ACPU1_pllacpu_o_mask                                  (0x00000180)
#define SYS_PLL_ACPU1_pllacpu_wdset_mask                              (0x00000040)
#define SYS_PLL_ACPU1_pllacpu_wdrst_mask                              (0x00000020)
#define SYS_PLL_ACPU1_pllacpu_cs_mask                                 (0x00000018)
#define SYS_PLL_ACPU1_pllacpu_rs_mask                                 (0x00000007)
#define SYS_PLL_ACPU1_pllacpu_tst(data)                               (0x01000000&((data)<<24))
#define SYS_PLL_ACPU1_pllacpu_n(data)                                 (0x00300000&((data)<<20))
#define SYS_PLL_ACPU1_pllacpu_m(data)                                 (0x0007F000&((data)<<12))
#define SYS_PLL_ACPU1_pllacpu_ip(data)                                (0x00000E00&((data)<<9))
#define SYS_PLL_ACPU1_pllacpu_o(data)                                 (0x00000180&((data)<<7))
#define SYS_PLL_ACPU1_pllacpu_wdset(data)                             (0x00000040&((data)<<6))
#define SYS_PLL_ACPU1_pllacpu_wdrst(data)                             (0x00000020&((data)<<5))
#define SYS_PLL_ACPU1_pllacpu_cs(data)                                (0x00000018&((data)<<3))
#define SYS_PLL_ACPU1_pllacpu_rs(data)                                (0x00000007&(data))
#define SYS_PLL_ACPU1_get_pllacpu_tst(data)                           ((0x01000000&(data))>>24)
#define SYS_PLL_ACPU1_get_pllacpu_n(data)                             ((0x00300000&(data))>>20)
#define SYS_PLL_ACPU1_get_pllacpu_m(data)                             ((0x0007F000&(data))>>12)
#define SYS_PLL_ACPU1_get_pllacpu_ip(data)                            ((0x00000E00&(data))>>9)
#define SYS_PLL_ACPU1_get_pllacpu_o(data)                             ((0x00000180&(data))>>7)
#define SYS_PLL_ACPU1_get_pllacpu_wdset(data)                         ((0x00000040&(data))>>6)
#define SYS_PLL_ACPU1_get_pllacpu_wdrst(data)                         ((0x00000020&(data))>>5)
#define SYS_PLL_ACPU1_get_pllacpu_cs(data)                            ((0x00000018&(data))>>3)
#define SYS_PLL_ACPU1_get_pllacpu_rs(data)                            (0x00000007&(data))


#define SYS_PLL_ACPU2                                                 0x1800040c
#define SYS_PLL_ACPU2_reg_addr                                        "0xb800040c"
#define SYS_PLL_ACPU2_reg                                             0xb800040c
#define SYS_PLL_ACPU2_inst_addr                                       "0x0103"
#define SYS_PLL_ACPU2_inst                                            0x0103
#define SYS_PLL_ACPU2_pllacpu_oeb_shift                               (2)
#define SYS_PLL_ACPU2_pllacpu_rstb_shift                              (1)
#define SYS_PLL_ACPU2_pllacpu_pow_shift                               (0)
#define SYS_PLL_ACPU2_pllacpu_oeb_mask                                (0x00000004)
#define SYS_PLL_ACPU2_pllacpu_rstb_mask                               (0x00000002)
#define SYS_PLL_ACPU2_pllacpu_pow_mask                                (0x00000001)
#define SYS_PLL_ACPU2_pllacpu_oeb(data)                               (0x00000004&((data)<<2))
#define SYS_PLL_ACPU2_pllacpu_rstb(data)                              (0x00000002&((data)<<1))
#define SYS_PLL_ACPU2_pllacpu_pow(data)                               (0x00000001&(data))
#define SYS_PLL_ACPU2_get_pllacpu_oeb(data)                           ((0x00000004&(data))>>2)
#define SYS_PLL_ACPU2_get_pllacpu_rstb(data)                          ((0x00000002&(data))>>1)
#define SYS_PLL_ACPU2_get_pllacpu_pow(data)                           (0x00000001&(data))


#define SYS_PLL_VCPU1                                                 0x18000410
#define SYS_PLL_VCPU1_reg_addr                                        "0xb8000410"
#define SYS_PLL_VCPU1_reg                                             0xb8000410
#define SYS_PLL_VCPU1_inst_addr                                       "0x0104"
#define SYS_PLL_VCPU1_inst                                            0x0104
#define SYS_PLL_VCPU1_pllvcpu_tst_shift                               (24)
#define SYS_PLL_VCPU1_pllvcpu_n_shift                                 (20)
#define SYS_PLL_VCPU1_pllvcpu_m_shift                                 (12)
#define SYS_PLL_VCPU1_pllvcpu_ip_shift                                (9)
#define SYS_PLL_VCPU1_pllvcpu_o_shift                                 (7)
#define SYS_PLL_VCPU1_pllvcpu_wdset_shift                             (6)
#define SYS_PLL_VCPU1_pllvcpu_wdrst_shift                             (5)
#define SYS_PLL_VCPU1_pllvcpu_cs_shift                                (3)
#define SYS_PLL_VCPU1_pllvcpu_rs_shift                                (0)
#define SYS_PLL_VCPU1_pllvcpu_tst_mask                                (0x01000000)
#define SYS_PLL_VCPU1_pllvcpu_n_mask                                  (0x00300000)
#define SYS_PLL_VCPU1_pllvcpu_m_mask                                  (0x0007F000)
#define SYS_PLL_VCPU1_pllvcpu_ip_mask                                 (0x00000E00)
#define SYS_PLL_VCPU1_pllvcpu_o_mask                                  (0x00000180)
#define SYS_PLL_VCPU1_pllvcpu_wdset_mask                              (0x00000040)
#define SYS_PLL_VCPU1_pllvcpu_wdrst_mask                              (0x00000020)
#define SYS_PLL_VCPU1_pllvcpu_cs_mask                                 (0x00000018)
#define SYS_PLL_VCPU1_pllvcpu_rs_mask                                 (0x00000007)
#define SYS_PLL_VCPU1_pllvcpu_tst(data)                               (0x01000000&((data)<<24))
#define SYS_PLL_VCPU1_pllvcpu_n(data)                                 (0x00300000&((data)<<20))
#define SYS_PLL_VCPU1_pllvcpu_m(data)                                 (0x0007F000&((data)<<12))
#define SYS_PLL_VCPU1_pllvcpu_ip(data)                                (0x00000E00&((data)<<9))
#define SYS_PLL_VCPU1_pllvcpu_o(data)                                 (0x00000180&((data)<<7))
#define SYS_PLL_VCPU1_pllvcpu_wdset(data)                             (0x00000040&((data)<<6))
#define SYS_PLL_VCPU1_pllvcpu_wdrst(data)                             (0x00000020&((data)<<5))
#define SYS_PLL_VCPU1_pllvcpu_cs(data)                                (0x00000018&((data)<<3))
#define SYS_PLL_VCPU1_pllvcpu_rs(data)                                (0x00000007&(data))
#define SYS_PLL_VCPU1_get_pllvcpu_tst(data)                           ((0x01000000&(data))>>24)
#define SYS_PLL_VCPU1_get_pllvcpu_n(data)                             ((0x00300000&(data))>>20)
#define SYS_PLL_VCPU1_get_pllvcpu_m(data)                             ((0x0007F000&(data))>>12)
#define SYS_PLL_VCPU1_get_pllvcpu_ip(data)                            ((0x00000E00&(data))>>9)
#define SYS_PLL_VCPU1_get_pllvcpu_o(data)                             ((0x00000180&(data))>>7)
#define SYS_PLL_VCPU1_get_pllvcpu_wdset(data)                         ((0x00000040&(data))>>6)
#define SYS_PLL_VCPU1_get_pllvcpu_wdrst(data)                         ((0x00000020&(data))>>5)
#define SYS_PLL_VCPU1_get_pllvcpu_cs(data)                            ((0x00000018&(data))>>3)
#define SYS_PLL_VCPU1_get_pllvcpu_rs(data)                            (0x00000007&(data))


#define SYS_PLL_VCPU2                                                 0x18000414
#define SYS_PLL_VCPU2_reg_addr                                        "0xb8000414"
#define SYS_PLL_VCPU2_reg                                             0xb8000414
#define SYS_PLL_VCPU2_inst_addr                                       "0x0105"
#define SYS_PLL_VCPU2_inst                                            0x0105
#define SYS_PLL_VCPU2_pllvcpu_oeb_shift                               (2)
#define SYS_PLL_VCPU2_pllvcpu_rstb_shift                              (1)
#define SYS_PLL_VCPU2_pllvcpu_pow_shift                               (0)
#define SYS_PLL_VCPU2_pllvcpu_oeb_mask                                (0x00000004)
#define SYS_PLL_VCPU2_pllvcpu_rstb_mask                               (0x00000002)
#define SYS_PLL_VCPU2_pllvcpu_pow_mask                                (0x00000001)
#define SYS_PLL_VCPU2_pllvcpu_oeb(data)                               (0x00000004&((data)<<2))
#define SYS_PLL_VCPU2_pllvcpu_rstb(data)                              (0x00000002&((data)<<1))
#define SYS_PLL_VCPU2_pllvcpu_pow(data)                               (0x00000001&(data))
#define SYS_PLL_VCPU2_get_pllvcpu_oeb(data)                           ((0x00000004&(data))>>2)
#define SYS_PLL_VCPU2_get_pllvcpu_rstb(data)                          ((0x00000002&(data))>>1)
#define SYS_PLL_VCPU2_get_pllvcpu_pow(data)                           (0x00000001&(data))


#define SYS_PLL_CPU                                                   0x1800041c
#define SYS_PLL_CPU_reg_addr                                          "0xb800041c"
#define SYS_PLL_CPU_reg                                               0xb800041c
#define SYS_PLL_CPU_inst_addr                                         "0x0107"
#define SYS_PLL_CPU_inst                                              0x0107
#define SYS_PLL_CPU_pllcpu_reg_shift                                  (0)
#define SYS_PLL_CPU_pllcpu_reg_mask                                   (0x00000003)
#define SYS_PLL_CPU_pllcpu_reg(data)                                  (0x00000003&(data))
#define SYS_PLL_CPU_get_pllcpu_reg(data)                              (0x00000003&(data))


#define SYS_PLL_BUS1                                                  0x18000420
#define SYS_PLL_BUS1_reg_addr                                         "0xb8000420"
#define SYS_PLL_BUS1_reg                                              0xb8000420
#define SYS_PLL_BUS1_inst_addr                                        "0x0108"
#define SYS_PLL_BUS1_inst                                             0x0108
#define SYS_PLL_BUS1_pllbus_n_shift                                   (25)
#define SYS_PLL_BUS1_pllbus_m_shift                                   (18)
#define SYS_PLL_BUS1_pllbus_ip_shift                                  (15)
#define SYS_PLL_BUS1_pllbus_rs_shift                                  (11)
#define SYS_PLL_BUS1_pllbus_cs_shift                                  (8)
#define SYS_PLL_BUS1_pllbus_cp_shift                                  (5)
#define SYS_PLL_BUS1_pllbus_r3_shift                                  (2)
#define SYS_PLL_BUS1_pllbus_c3_shift                                  (0)
#define SYS_PLL_BUS1_pllbus_n_mask                                    (0x06000000)
#define SYS_PLL_BUS1_pllbus_m_mask                                    (0x01FC0000)
#define SYS_PLL_BUS1_pllbus_ip_mask                                   (0x00038000)
#define SYS_PLL_BUS1_pllbus_rs_mask                                   (0x00003800)
#define SYS_PLL_BUS1_pllbus_cs_mask                                   (0x00000300)
#define SYS_PLL_BUS1_pllbus_cp_mask                                   (0x00000060)
#define SYS_PLL_BUS1_pllbus_r3_mask                                   (0x0000001C)
#define SYS_PLL_BUS1_pllbus_c3_mask                                   (0x00000003)
#define SYS_PLL_BUS1_pllbus_n(data)                                   (0x06000000&((data)<<25))
#define SYS_PLL_BUS1_pllbus_m(data)                                   (0x01FC0000&((data)<<18))
#define SYS_PLL_BUS1_pllbus_ip(data)                                  (0x00038000&((data)<<15))
#define SYS_PLL_BUS1_pllbus_rs(data)                                  (0x00003800&((data)<<11))
#define SYS_PLL_BUS1_pllbus_cs(data)                                  (0x00000300&((data)<<8))
#define SYS_PLL_BUS1_pllbus_cp(data)                                  (0x00000060&((data)<<5))
#define SYS_PLL_BUS1_pllbus_r3(data)                                  (0x0000001C&((data)<<2))
#define SYS_PLL_BUS1_pllbus_c3(data)                                  (0x00000003&(data))
#define SYS_PLL_BUS1_get_pllbus_n(data)                               ((0x06000000&(data))>>25)
#define SYS_PLL_BUS1_get_pllbus_m(data)                               ((0x01FC0000&(data))>>18)
#define SYS_PLL_BUS1_get_pllbus_ip(data)                              ((0x00038000&(data))>>15)
#define SYS_PLL_BUS1_get_pllbus_rs(data)                              ((0x00003800&(data))>>11)
#define SYS_PLL_BUS1_get_pllbus_cs(data)                              ((0x00000300&(data))>>8)
#define SYS_PLL_BUS1_get_pllbus_cp(data)                              ((0x00000060&(data))>>5)
#define SYS_PLL_BUS1_get_pllbus_r3(data)                              ((0x0000001C&(data))>>2)
#define SYS_PLL_BUS1_get_pllbus_c3(data)                              (0x00000003&(data))


#define SYS_PLL_BUS2                                                  0x18000424
#define SYS_PLL_BUS2_reg_addr                                         "0xb8000424"
#define SYS_PLL_BUS2_reg                                              0xb8000424
#define SYS_PLL_BUS2_inst_addr                                        "0x0109"
#define SYS_PLL_BUS2_inst                                             0x0109
#define SYS_PLL_BUS2_dummy18000424_18_shift                           (18)
#define SYS_PLL_BUS2_pllbus_pi_rl_shift                               (16)
#define SYS_PLL_BUS2_pllbus_pi_rs_shift                               (14)
#define SYS_PLL_BUS2_pllbus_pi_bias_shift                             (12)
#define SYS_PLL_BUS2_dummy18000424_11_shift                           (11)
#define SYS_PLL_BUS2_pllbus_wdmode_shift                              (9)
#define SYS_PLL_BUS2_dummy18000424_8_6_shift                          (6)
#define SYS_PLL_BUS2_pllbus_fupdn_shift                               (5)
#define SYS_PLL_BUS2_pllbus_psen_shift                                (4)
#define SYS_PLL_BUS2_pllbus_vcorb_shift                               (3)
#define SYS_PLL_BUS2_dummy18000424_2_shift                            (2)
#define SYS_PLL_BUS2_pllbus_tst_shift                                 (1)
#define SYS_PLL_BUS2_pllbus_pstst_shift                               (0)
#define SYS_PLL_BUS2_dummy18000424_18_mask                            (0x00040000)
#define SYS_PLL_BUS2_pllbus_pi_rl_mask                                (0x00030000)
#define SYS_PLL_BUS2_pllbus_pi_rs_mask                                (0x0000C000)
#define SYS_PLL_BUS2_pllbus_pi_bias_mask                              (0x00003000)
#define SYS_PLL_BUS2_dummy18000424_11_mask                            (0x00000800)
#define SYS_PLL_BUS2_pllbus_wdmode_mask                               (0x00000600)
#define SYS_PLL_BUS2_dummy18000424_8_6_mask                           (0x000001C0)
#define SYS_PLL_BUS2_pllbus_fupdn_mask                                (0x00000020)
#define SYS_PLL_BUS2_pllbus_psen_mask                                 (0x00000010)
#define SYS_PLL_BUS2_pllbus_vcorb_mask                                (0x00000008)
#define SYS_PLL_BUS2_dummy18000424_2_mask                             (0x00000004)
#define SYS_PLL_BUS2_pllbus_tst_mask                                  (0x00000002)
#define SYS_PLL_BUS2_pllbus_pstst_mask                                (0x00000001)
#define SYS_PLL_BUS2_dummy18000424_18(data)                           (0x00040000&((data)<<18))
#define SYS_PLL_BUS2_pllbus_pi_rl(data)                               (0x00030000&((data)<<16))
#define SYS_PLL_BUS2_pllbus_pi_rs(data)                               (0x0000C000&((data)<<14))
#define SYS_PLL_BUS2_pllbus_pi_bias(data)                             (0x00003000&((data)<<12))
#define SYS_PLL_BUS2_dummy18000424_11(data)                           (0x00000800&((data)<<11))
#define SYS_PLL_BUS2_pllbus_wdmode(data)                              (0x00000600&((data)<<9))
#define SYS_PLL_BUS2_dummy18000424_8_6(data)                          (0x000001C0&((data)<<6))
#define SYS_PLL_BUS2_pllbus_fupdn(data)                               (0x00000020&((data)<<5))
#define SYS_PLL_BUS2_pllbus_psen(data)                                (0x00000010&((data)<<4))
#define SYS_PLL_BUS2_pllbus_vcorb(data)                               (0x00000008&((data)<<3))
#define SYS_PLL_BUS2_dummy18000424_2(data)                            (0x00000004&((data)<<2))
#define SYS_PLL_BUS2_pllbus_tst(data)                                 (0x00000002&((data)<<1))
#define SYS_PLL_BUS2_pllbus_pstst(data)                               (0x00000001&(data))
#define SYS_PLL_BUS2_get_dummy18000424_18(data)                       ((0x00040000&(data))>>18)
#define SYS_PLL_BUS2_get_pllbus_pi_rl(data)                           ((0x00030000&(data))>>16)
#define SYS_PLL_BUS2_get_pllbus_pi_rs(data)                           ((0x0000C000&(data))>>14)
#define SYS_PLL_BUS2_get_pllbus_pi_bias(data)                         ((0x00003000&(data))>>12)
#define SYS_PLL_BUS2_get_dummy18000424_11(data)                       ((0x00000800&(data))>>11)
#define SYS_PLL_BUS2_get_pllbus_wdmode(data)                          ((0x00000600&(data))>>9)
#define SYS_PLL_BUS2_get_dummy18000424_8_6(data)                      ((0x000001C0&(data))>>6)
#define SYS_PLL_BUS2_get_pllbus_fupdn(data)                           ((0x00000020&(data))>>5)
#define SYS_PLL_BUS2_get_pllbus_psen(data)                            ((0x00000010&(data))>>4)
#define SYS_PLL_BUS2_get_pllbus_vcorb(data)                           ((0x00000008&(data))>>3)
#define SYS_PLL_BUS2_get_dummy18000424_2(data)                        ((0x00000004&(data))>>2)
#define SYS_PLL_BUS2_get_pllbus_tst(data)                             ((0x00000002&(data))>>1)
#define SYS_PLL_BUS2_get_pllbus_pstst(data)                           (0x00000001&(data))


#define SYS_PLL_BUS3                                                  0x18000428
#define SYS_PLL_BUS3_reg_addr                                         "0xb8000428"
#define SYS_PLL_BUS3_reg                                              0xb8000428
#define SYS_PLL_BUS3_inst_addr                                        "0x010A"
#define SYS_PLL_BUS3_inst                                             0x010A
#define SYS_PLL_BUS3_pllbus_o_shift                                   (3)
#define SYS_PLL_BUS3_pllbus_oeb_shift                                 (2)
#define SYS_PLL_BUS3_pllbus_rstb_shift                                (1)
#define SYS_PLL_BUS3_pllbus_pow_shift                                 (0)
#define SYS_PLL_BUS3_pllbus_o_mask                                    (0x00000008)
#define SYS_PLL_BUS3_pllbus_oeb_mask                                  (0x00000004)
#define SYS_PLL_BUS3_pllbus_rstb_mask                                 (0x00000002)
#define SYS_PLL_BUS3_pllbus_pow_mask                                  (0x00000001)
#define SYS_PLL_BUS3_pllbus_o(data)                                   (0x00000008&((data)<<3))
#define SYS_PLL_BUS3_pllbus_oeb(data)                                 (0x00000004&((data)<<2))
#define SYS_PLL_BUS3_pllbus_rstb(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_BUS3_pllbus_pow(data)                                 (0x00000001&(data))
#define SYS_PLL_BUS3_get_pllbus_o(data)                               ((0x00000008&(data))>>3)
#define SYS_PLL_BUS3_get_pllbus_oeb(data)                             ((0x00000004&(data))>>2)
#define SYS_PLL_BUS3_get_pllbus_rstb(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_BUS3_get_pllbus_pow(data)                             (0x00000001&(data))


#define SC_BUSPLL_SSC                                                 0x1800042c
#define SC_BUSPLL_SSC_reg_addr                                        "0xb800042c"
#define SC_BUSPLL_SSC_reg                                             0xb800042c
#define SC_BUSPLL_SSC_inst_addr                                       "0x010B"
#define SC_BUSPLL_SSC_inst                                            0x010B
#define SC_BUSPLL_SSC_bus_ssc_sse_shift                               (31)
#define SC_BUSPLL_SSC_bus_ssc_ckinv_shift                             (30)
#define SC_BUSPLL_SSC_bus_ssc_sss_shift                               (24)
#define SC_BUSPLL_SSC_bus_ssc_ssn_shift                               (16)
#define SC_BUSPLL_SSC_bus_ssc_ssfpv_shift                             (8)
#define SC_BUSPLL_SSC_bus_ssc_stms_shift                              (0)
#define SC_BUSPLL_SSC_bus_ssc_sse_mask                                (0x80000000)
#define SC_BUSPLL_SSC_bus_ssc_ckinv_mask                              (0x40000000)
#define SC_BUSPLL_SSC_bus_ssc_sss_mask                                (0x3F000000)
#define SC_BUSPLL_SSC_bus_ssc_ssn_mask                                (0x007F0000)
#define SC_BUSPLL_SSC_bus_ssc_ssfpv_mask                              (0x0000FF00)
#define SC_BUSPLL_SSC_bus_ssc_stms_mask                               (0x00000003)
#define SC_BUSPLL_SSC_bus_ssc_sse(data)                               (0x80000000&((data)<<31))
#define SC_BUSPLL_SSC_bus_ssc_ckinv(data)                             (0x40000000&((data)<<30))
#define SC_BUSPLL_SSC_bus_ssc_sss(data)                               (0x3F000000&((data)<<24))
#define SC_BUSPLL_SSC_bus_ssc_ssn(data)                               (0x007F0000&((data)<<16))
#define SC_BUSPLL_SSC_bus_ssc_ssfpv(data)                             (0x0000FF00&((data)<<8))
#define SC_BUSPLL_SSC_bus_ssc_stms(data)                              (0x00000003&(data))
#define SC_BUSPLL_SSC_get_bus_ssc_sse(data)                           ((0x80000000&(data))>>31)
#define SC_BUSPLL_SSC_get_bus_ssc_ckinv(data)                         ((0x40000000&(data))>>30)
#define SC_BUSPLL_SSC_get_bus_ssc_sss(data)                           ((0x3F000000&(data))>>24)
#define SC_BUSPLL_SSC_get_bus_ssc_ssn(data)                           ((0x007F0000&(data))>>16)
#define SC_BUSPLL_SSC_get_bus_ssc_ssfpv(data)                         ((0x0000FF00&(data))>>8)
#define SC_BUSPLL_SSC_get_bus_ssc_stms(data)                          (0x00000003&(data))


#define SYS_PLL_H_BUS1                                                0x18000430
#define SYS_PLL_H_BUS1_reg_addr                                       "0xb8000430"
#define SYS_PLL_H_BUS1_reg                                            0xb8000430
#define SYS_PLL_H_BUS1_inst_addr                                      "0x010C"
#define SYS_PLL_H_BUS1_inst                                           0x010C
#define SYS_PLL_H_BUS1_pllbus_n_h_shift                               (25)
#define SYS_PLL_H_BUS1_pllbus_m_h_shift                               (18)
#define SYS_PLL_H_BUS1_pllbus_ip_h_shift                              (15)
#define SYS_PLL_H_BUS1_pllbus_rs_h_shift                              (11)
#define SYS_PLL_H_BUS1_pllbus_cs_h_shift                              (8)
#define SYS_PLL_H_BUS1_pllbus_cp_h_shift                              (5)
#define SYS_PLL_H_BUS1_pllbus_r3_h_shift                              (2)
#define SYS_PLL_H_BUS1_pllbus_c3_h_shift                              (0)
#define SYS_PLL_H_BUS1_pllbus_n_h_mask                                (0x06000000)
#define SYS_PLL_H_BUS1_pllbus_m_h_mask                                (0x01FC0000)
#define SYS_PLL_H_BUS1_pllbus_ip_h_mask                               (0x00038000)
#define SYS_PLL_H_BUS1_pllbus_rs_h_mask                               (0x00003800)
#define SYS_PLL_H_BUS1_pllbus_cs_h_mask                               (0x00000300)
#define SYS_PLL_H_BUS1_pllbus_cp_h_mask                               (0x00000060)
#define SYS_PLL_H_BUS1_pllbus_r3_h_mask                               (0x0000001C)
#define SYS_PLL_H_BUS1_pllbus_c3_h_mask                               (0x00000003)
#define SYS_PLL_H_BUS1_pllbus_n_h(data)                               (0x06000000&((data)<<25))
#define SYS_PLL_H_BUS1_pllbus_m_h(data)                               (0x01FC0000&((data)<<18))
#define SYS_PLL_H_BUS1_pllbus_ip_h(data)                              (0x00038000&((data)<<15))
#define SYS_PLL_H_BUS1_pllbus_rs_h(data)                              (0x00003800&((data)<<11))
#define SYS_PLL_H_BUS1_pllbus_cs_h(data)                              (0x00000300&((data)<<8))
#define SYS_PLL_H_BUS1_pllbus_cp_h(data)                              (0x00000060&((data)<<5))
#define SYS_PLL_H_BUS1_pllbus_r3_h(data)                              (0x0000001C&((data)<<2))
#define SYS_PLL_H_BUS1_pllbus_c3_h(data)                              (0x00000003&(data))
#define SYS_PLL_H_BUS1_get_pllbus_n_h(data)                           ((0x06000000&(data))>>25)
#define SYS_PLL_H_BUS1_get_pllbus_m_h(data)                           ((0x01FC0000&(data))>>18)
#define SYS_PLL_H_BUS1_get_pllbus_ip_h(data)                          ((0x00038000&(data))>>15)
#define SYS_PLL_H_BUS1_get_pllbus_rs_h(data)                          ((0x00003800&(data))>>11)
#define SYS_PLL_H_BUS1_get_pllbus_cs_h(data)                          ((0x00000300&(data))>>8)
#define SYS_PLL_H_BUS1_get_pllbus_cp_h(data)                          ((0x00000060&(data))>>5)
#define SYS_PLL_H_BUS1_get_pllbus_r3_h(data)                          ((0x0000001C&(data))>>2)
#define SYS_PLL_H_BUS1_get_pllbus_c3_h(data)                          (0x00000003&(data))


#define SYS_PLL_H_BUS2                                                0x18000434
#define SYS_PLL_H_BUS2_reg_addr                                       "0xb8000434"
#define SYS_PLL_H_BUS2_reg                                            0xb8000434
#define SYS_PLL_H_BUS2_inst_addr                                      "0x010D"
#define SYS_PLL_H_BUS2_inst                                           0x010D
#define SYS_PLL_H_BUS2_dummy18000434_18_shift                         (18)
#define SYS_PLL_H_BUS2_pllbus_pi_rl_h_shift                           (16)
#define SYS_PLL_H_BUS2_pllbus_pi_rs_h_shift                           (14)
#define SYS_PLL_H_BUS2_pllbus_pi_bias_h_shift                         (12)
#define SYS_PLL_H_BUS2_dummy18000434_11_shift                         (11)
#define SYS_PLL_H_BUS2_pllbus_wdmode_h_shift                          (9)
#define SYS_PLL_H_BUS2_dummy18000434_8_6_shift                        (6)
#define SYS_PLL_H_BUS2_pllbus_fupdn_h_shift                           (5)
#define SYS_PLL_H_BUS2_pllbus_psen_h_shift                            (4)
#define SYS_PLL_H_BUS2_pllbus_vcorb_h_shift                           (3)
#define SYS_PLL_H_BUS2_dummy18000434_2_shift                          (2)
#define SYS_PLL_H_BUS2_pllbus_tst_h_shift                             (1)
#define SYS_PLL_H_BUS2_pllbus_pstst_h_shift                           (0)
#define SYS_PLL_H_BUS2_dummy18000434_18_mask                          (0x00040000)
#define SYS_PLL_H_BUS2_pllbus_pi_rl_h_mask                            (0x00030000)
#define SYS_PLL_H_BUS2_pllbus_pi_rs_h_mask                            (0x0000C000)
#define SYS_PLL_H_BUS2_pllbus_pi_bias_h_mask                          (0x00003000)
#define SYS_PLL_H_BUS2_dummy18000434_11_mask                          (0x00000800)
#define SYS_PLL_H_BUS2_pllbus_wdmode_h_mask                           (0x00000600)
#define SYS_PLL_H_BUS2_dummy18000434_8_6_mask                         (0x000001C0)
#define SYS_PLL_H_BUS2_pllbus_fupdn_h_mask                            (0x00000020)
#define SYS_PLL_H_BUS2_pllbus_psen_h_mask                             (0x00000010)
#define SYS_PLL_H_BUS2_pllbus_vcorb_h_mask                            (0x00000008)
#define SYS_PLL_H_BUS2_dummy18000434_2_mask                           (0x00000004)
#define SYS_PLL_H_BUS2_pllbus_tst_h_mask                              (0x00000002)
#define SYS_PLL_H_BUS2_pllbus_pstst_h_mask                            (0x00000001)
#define SYS_PLL_H_BUS2_dummy18000434_18(data)                         (0x00040000&((data)<<18))
#define SYS_PLL_H_BUS2_pllbus_pi_rl_h(data)                           (0x00030000&((data)<<16))
#define SYS_PLL_H_BUS2_pllbus_pi_rs_h(data)                           (0x0000C000&((data)<<14))
#define SYS_PLL_H_BUS2_pllbus_pi_bias_h(data)                         (0x00003000&((data)<<12))
#define SYS_PLL_H_BUS2_dummy18000434_11(data)                         (0x00000800&((data)<<11))
#define SYS_PLL_H_BUS2_pllbus_wdmode_h(data)                          (0x00000600&((data)<<9))
#define SYS_PLL_H_BUS2_dummy18000434_8_6(data)                        (0x000001C0&((data)<<6))
#define SYS_PLL_H_BUS2_pllbus_fupdn_h(data)                           (0x00000020&((data)<<5))
#define SYS_PLL_H_BUS2_pllbus_psen_h(data)                            (0x00000010&((data)<<4))
#define SYS_PLL_H_BUS2_pllbus_vcorb_h(data)                           (0x00000008&((data)<<3))
#define SYS_PLL_H_BUS2_dummy18000434_2(data)                          (0x00000004&((data)<<2))
#define SYS_PLL_H_BUS2_pllbus_tst_h(data)                             (0x00000002&((data)<<1))
#define SYS_PLL_H_BUS2_pllbus_pstst_h(data)                           (0x00000001&(data))
#define SYS_PLL_H_BUS2_get_dummy18000434_18(data)                     ((0x00040000&(data))>>18)
#define SYS_PLL_H_BUS2_get_pllbus_pi_rl_h(data)                       ((0x00030000&(data))>>16)
#define SYS_PLL_H_BUS2_get_pllbus_pi_rs_h(data)                       ((0x0000C000&(data))>>14)
#define SYS_PLL_H_BUS2_get_pllbus_pi_bias_h(data)                     ((0x00003000&(data))>>12)
#define SYS_PLL_H_BUS2_get_dummy18000434_11(data)                     ((0x00000800&(data))>>11)
#define SYS_PLL_H_BUS2_get_pllbus_wdmode_h(data)                      ((0x00000600&(data))>>9)
#define SYS_PLL_H_BUS2_get_dummy18000434_8_6(data)                    ((0x000001C0&(data))>>6)
#define SYS_PLL_H_BUS2_get_pllbus_fupdn_h(data)                       ((0x00000020&(data))>>5)
#define SYS_PLL_H_BUS2_get_pllbus_psen_h(data)                        ((0x00000010&(data))>>4)
#define SYS_PLL_H_BUS2_get_pllbus_vcorb_h(data)                       ((0x00000008&(data))>>3)
#define SYS_PLL_H_BUS2_get_dummy18000434_2(data)                      ((0x00000004&(data))>>2)
#define SYS_PLL_H_BUS2_get_pllbus_tst_h(data)                         ((0x00000002&(data))>>1)
#define SYS_PLL_H_BUS2_get_pllbus_pstst_h(data)                       (0x00000001&(data))


#define SYS_PLL_H_BUS3                                                0x18000438
#define SYS_PLL_H_BUS3_reg_addr                                       "0xb8000438"
#define SYS_PLL_H_BUS3_reg                                            0xb8000438
#define SYS_PLL_H_BUS3_inst_addr                                      "0x010E"
#define SYS_PLL_H_BUS3_inst                                           0x010E
#define SYS_PLL_H_BUS3_pllbus_o_h_shift                               (3)
#define SYS_PLL_H_BUS3_pllbus_oeb_h_shift                             (2)
#define SYS_PLL_H_BUS3_pllbus_rstb_h_shift                            (1)
#define SYS_PLL_H_BUS3_pllbus_pow_h_shift                             (0)
#define SYS_PLL_H_BUS3_pllbus_o_h_mask                                (0x00000008)
#define SYS_PLL_H_BUS3_pllbus_oeb_h_mask                              (0x00000004)
#define SYS_PLL_H_BUS3_pllbus_rstb_h_mask                             (0x00000002)
#define SYS_PLL_H_BUS3_pllbus_pow_h_mask                              (0x00000001)
#define SYS_PLL_H_BUS3_pllbus_o_h(data)                               (0x00000008&((data)<<3))
#define SYS_PLL_H_BUS3_pllbus_oeb_h(data)                             (0x00000004&((data)<<2))
#define SYS_PLL_H_BUS3_pllbus_rstb_h(data)                            (0x00000002&((data)<<1))
#define SYS_PLL_H_BUS3_pllbus_pow_h(data)                             (0x00000001&(data))
#define SYS_PLL_H_BUS3_get_pllbus_o_h(data)                           ((0x00000008&(data))>>3)
#define SYS_PLL_H_BUS3_get_pllbus_oeb_h(data)                         ((0x00000004&(data))>>2)
#define SYS_PLL_H_BUS3_get_pllbus_rstb_h(data)                        ((0x00000002&(data))>>1)
#define SYS_PLL_H_BUS3_get_pllbus_pow_h(data)                         (0x00000001&(data))


#define SC_BUSHPLL_SSC                                                0x1800043c
#define SC_BUSHPLL_SSC_reg_addr                                       "0xb800043c"
#define SC_BUSHPLL_SSC_reg                                            0xb800043c
#define SC_BUSHPLL_SSC_inst_addr                                      "0x010F"
#define SC_BUSHPLL_SSC_inst                                           0x010F
#define SC_BUSHPLL_SSC_bush_ssc_sse_shift                             (31)
#define SC_BUSHPLL_SSC_bush_ssc_ckinv_shift                           (30)
#define SC_BUSHPLL_SSC_bush_ssc_sss_shift                             (24)
#define SC_BUSHPLL_SSC_bush_ssc_ssn_shift                             (16)
#define SC_BUSHPLL_SSC_bush_ssc_ssfpv_shift                           (8)
#define SC_BUSHPLL_SSC_bush_ssc_stms_shift                            (0)
#define SC_BUSHPLL_SSC_bush_ssc_sse_mask                              (0x80000000)
#define SC_BUSHPLL_SSC_bush_ssc_ckinv_mask                            (0x40000000)
#define SC_BUSHPLL_SSC_bush_ssc_sss_mask                              (0x3F000000)
#define SC_BUSHPLL_SSC_bush_ssc_ssn_mask                              (0x007F0000)
#define SC_BUSHPLL_SSC_bush_ssc_ssfpv_mask                            (0x0000FF00)
#define SC_BUSHPLL_SSC_bush_ssc_stms_mask                             (0x00000003)
#define SC_BUSHPLL_SSC_bush_ssc_sse(data)                             (0x80000000&((data)<<31))
#define SC_BUSHPLL_SSC_bush_ssc_ckinv(data)                           (0x40000000&((data)<<30))
#define SC_BUSHPLL_SSC_bush_ssc_sss(data)                             (0x3F000000&((data)<<24))
#define SC_BUSHPLL_SSC_bush_ssc_ssn(data)                             (0x007F0000&((data)<<16))
#define SC_BUSHPLL_SSC_bush_ssc_ssfpv(data)                           (0x0000FF00&((data)<<8))
#define SC_BUSHPLL_SSC_bush_ssc_stms(data)                            (0x00000003&(data))
#define SC_BUSHPLL_SSC_get_bush_ssc_sse(data)                         ((0x80000000&(data))>>31)
#define SC_BUSHPLL_SSC_get_bush_ssc_ckinv(data)                       ((0x40000000&(data))>>30)
#define SC_BUSHPLL_SSC_get_bush_ssc_sss(data)                         ((0x3F000000&(data))>>24)
#define SC_BUSHPLL_SSC_get_bush_ssc_ssn(data)                         ((0x007F0000&(data))>>16)
#define SC_BUSHPLL_SSC_get_bush_ssc_ssfpv(data)                       ((0x0000FF00&(data))>>8)
#define SC_BUSHPLL_SSC_get_bush_ssc_stms(data)                        (0x00000003&(data))


#define SYS_PLL_2_BUS1                                                0x18000440
#define SYS_PLL_2_BUS1_reg_addr                                       "0xb8000440"
#define SYS_PLL_2_BUS1_reg                                            0xb8000440
#define SYS_PLL_2_BUS1_inst_addr                                      "0x0110"
#define SYS_PLL_2_BUS1_inst                                           0x0110
#define SYS_PLL_2_BUS1_pllbus_n_2_shift                               (25)
#define SYS_PLL_2_BUS1_pllbus_m_2_shift                               (18)
#define SYS_PLL_2_BUS1_pllbus_ip_2_shift                              (15)
#define SYS_PLL_2_BUS1_pllbus_rs_2_shift                              (11)
#define SYS_PLL_2_BUS1_pllbus_cs_2_shift                              (8)
#define SYS_PLL_2_BUS1_pllbus_cp_2_shift                              (5)
#define SYS_PLL_2_BUS1_pllbus_r3_2_shift                              (2)
#define SYS_PLL_2_BUS1_pllbus_c3_2_shift                              (0)
#define SYS_PLL_2_BUS1_pllbus_n_2_mask                                (0x06000000)
#define SYS_PLL_2_BUS1_pllbus_m_2_mask                                (0x01FC0000)
#define SYS_PLL_2_BUS1_pllbus_ip_2_mask                               (0x00038000)
#define SYS_PLL_2_BUS1_pllbus_rs_2_mask                               (0x00003800)
#define SYS_PLL_2_BUS1_pllbus_cs_2_mask                               (0x00000300)
#define SYS_PLL_2_BUS1_pllbus_cp_2_mask                               (0x00000060)
#define SYS_PLL_2_BUS1_pllbus_r3_2_mask                               (0x0000001C)
#define SYS_PLL_2_BUS1_pllbus_c3_2_mask                               (0x00000003)
#define SYS_PLL_2_BUS1_pllbus_n_2(data)                               (0x06000000&((data)<<25))
#define SYS_PLL_2_BUS1_pllbus_m_2(data)                               (0x01FC0000&((data)<<18))
#define SYS_PLL_2_BUS1_pllbus_ip_2(data)                              (0x00038000&((data)<<15))
#define SYS_PLL_2_BUS1_pllbus_rs_2(data)                              (0x00003800&((data)<<11))
#define SYS_PLL_2_BUS1_pllbus_cs_2(data)                              (0x00000300&((data)<<8))
#define SYS_PLL_2_BUS1_pllbus_cp_2(data)                              (0x00000060&((data)<<5))
#define SYS_PLL_2_BUS1_pllbus_r3_2(data)                              (0x0000001C&((data)<<2))
#define SYS_PLL_2_BUS1_pllbus_c3_2(data)                              (0x00000003&(data))
#define SYS_PLL_2_BUS1_get_pllbus_n_2(data)                           ((0x06000000&(data))>>25)
#define SYS_PLL_2_BUS1_get_pllbus_m_2(data)                           ((0x01FC0000&(data))>>18)
#define SYS_PLL_2_BUS1_get_pllbus_ip_2(data)                          ((0x00038000&(data))>>15)
#define SYS_PLL_2_BUS1_get_pllbus_rs_2(data)                          ((0x00003800&(data))>>11)
#define SYS_PLL_2_BUS1_get_pllbus_cs_2(data)                          ((0x00000300&(data))>>8)
#define SYS_PLL_2_BUS1_get_pllbus_cp_2(data)                          ((0x00000060&(data))>>5)
#define SYS_PLL_2_BUS1_get_pllbus_r3_2(data)                          ((0x0000001C&(data))>>2)
#define SYS_PLL_2_BUS1_get_pllbus_c3_2(data)                          (0x00000003&(data))


#define SYS_PLL_2_BUS2                                                0x18000444
#define SYS_PLL_2_BUS2_reg_addr                                       "0xb8000444"
#define SYS_PLL_2_BUS2_reg                                            0xb8000444
#define SYS_PLL_2_BUS2_inst_addr                                      "0x0111"
#define SYS_PLL_2_BUS2_inst                                           0x0111
#define SYS_PLL_2_BUS2_dummy18000444_18_shift                         (18)
#define SYS_PLL_2_BUS2_pllbus_pi_rl_2_shift                           (16)
#define SYS_PLL_2_BUS2_pllbus_pi_rs_2_shift                           (14)
#define SYS_PLL_2_BUS2_pllbus_pi_bias_2_shift                         (12)
#define SYS_PLL_2_BUS2_dummy18000444_11_shift                         (11)
#define SYS_PLL_2_BUS2_pllbus_wdmode_2_shift                          (9)
#define SYS_PLL_2_BUS2_dummy18000444_8_6_shift                        (6)
#define SYS_PLL_2_BUS2_pllbus_fupdn_2_shift                           (5)
#define SYS_PLL_2_BUS2_pllbus_psen_2_shift                            (4)
#define SYS_PLL_2_BUS2_pllbus_vcorb_2_shift                           (3)
#define SYS_PLL_2_BUS2_dummy18000444_2_shift                          (2)
#define SYS_PLL_2_BUS2_pllbus_tst_2_shift                             (1)
#define SYS_PLL_2_BUS2_pllbus_pstst_2_shift                           (0)
#define SYS_PLL_2_BUS2_dummy18000444_18_mask                          (0x00040000)
#define SYS_PLL_2_BUS2_pllbus_pi_rl_2_mask                            (0x00030000)
#define SYS_PLL_2_BUS2_pllbus_pi_rs_2_mask                            (0x0000C000)
#define SYS_PLL_2_BUS2_pllbus_pi_bias_2_mask                          (0x00003000)
#define SYS_PLL_2_BUS2_dummy18000444_11_mask                          (0x00000800)
#define SYS_PLL_2_BUS2_pllbus_wdmode_2_mask                           (0x00000600)
#define SYS_PLL_2_BUS2_dummy18000444_8_6_mask                         (0x000001C0)
#define SYS_PLL_2_BUS2_pllbus_fupdn_2_mask                            (0x00000020)
#define SYS_PLL_2_BUS2_pllbus_psen_2_mask                             (0x00000010)
#define SYS_PLL_2_BUS2_pllbus_vcorb_2_mask                            (0x00000008)
#define SYS_PLL_2_BUS2_dummy18000444_2_mask                           (0x00000004)
#define SYS_PLL_2_BUS2_pllbus_tst_2_mask                              (0x00000002)
#define SYS_PLL_2_BUS2_pllbus_pstst_2_mask                            (0x00000001)
#define SYS_PLL_2_BUS2_dummy18000444_18(data)                         (0x00040000&((data)<<18))
#define SYS_PLL_2_BUS2_pllbus_pi_rl_2(data)                           (0x00030000&((data)<<16))
#define SYS_PLL_2_BUS2_pllbus_pi_rs_2(data)                           (0x0000C000&((data)<<14))
#define SYS_PLL_2_BUS2_pllbus_pi_bias_2(data)                         (0x00003000&((data)<<12))
#define SYS_PLL_2_BUS2_dummy18000444_11(data)                         (0x00000800&((data)<<11))
#define SYS_PLL_2_BUS2_pllbus_wdmode_2(data)                          (0x00000600&((data)<<9))
#define SYS_PLL_2_BUS2_dummy18000444_8_6(data)                        (0x000001C0&((data)<<6))
#define SYS_PLL_2_BUS2_pllbus_fupdn_2(data)                           (0x00000020&((data)<<5))
#define SYS_PLL_2_BUS2_pllbus_psen_2(data)                            (0x00000010&((data)<<4))
#define SYS_PLL_2_BUS2_pllbus_vcorb_2(data)                           (0x00000008&((data)<<3))
#define SYS_PLL_2_BUS2_dummy18000444_2(data)                          (0x00000004&((data)<<2))
#define SYS_PLL_2_BUS2_pllbus_tst_2(data)                             (0x00000002&((data)<<1))
#define SYS_PLL_2_BUS2_pllbus_pstst_2(data)                           (0x00000001&(data))
#define SYS_PLL_2_BUS2_get_dummy18000444_18(data)                     ((0x00040000&(data))>>18)
#define SYS_PLL_2_BUS2_get_pllbus_pi_rl_2(data)                       ((0x00030000&(data))>>16)
#define SYS_PLL_2_BUS2_get_pllbus_pi_rs_2(data)                       ((0x0000C000&(data))>>14)
#define SYS_PLL_2_BUS2_get_pllbus_pi_bias_2(data)                     ((0x00003000&(data))>>12)
#define SYS_PLL_2_BUS2_get_dummy18000444_11(data)                     ((0x00000800&(data))>>11)
#define SYS_PLL_2_BUS2_get_pllbus_wdmode_2(data)                      ((0x00000600&(data))>>9)
#define SYS_PLL_2_BUS2_get_dummy18000444_8_6(data)                    ((0x000001C0&(data))>>6)
#define SYS_PLL_2_BUS2_get_pllbus_fupdn_2(data)                       ((0x00000020&(data))>>5)
#define SYS_PLL_2_BUS2_get_pllbus_psen_2(data)                        ((0x00000010&(data))>>4)
#define SYS_PLL_2_BUS2_get_pllbus_vcorb_2(data)                       ((0x00000008&(data))>>3)
#define SYS_PLL_2_BUS2_get_dummy18000444_2(data)                      ((0x00000004&(data))>>2)
#define SYS_PLL_2_BUS2_get_pllbus_tst_2(data)                         ((0x00000002&(data))>>1)
#define SYS_PLL_2_BUS2_get_pllbus_pstst_2(data)                       (0x00000001&(data))


#define SYS_PLL_2_BUS3                                                0x18000448
#define SYS_PLL_2_BUS3_reg_addr                                       "0xb8000448"
#define SYS_PLL_2_BUS3_reg                                            0xb8000448
#define SYS_PLL_2_BUS3_inst_addr                                      "0x0112"
#define SYS_PLL_2_BUS3_inst                                           0x0112
#define SYS_PLL_2_BUS3_pllbus_o_2_shift                               (3)
#define SYS_PLL_2_BUS3_pllbus_oeb_2_shift                             (2)
#define SYS_PLL_2_BUS3_pllbus_rstb_2_shift                            (1)
#define SYS_PLL_2_BUS3_pllbus_pow_2_shift                             (0)
#define SYS_PLL_2_BUS3_pllbus_o_2_mask                                (0x00000008)
#define SYS_PLL_2_BUS3_pllbus_oeb_2_mask                              (0x00000004)
#define SYS_PLL_2_BUS3_pllbus_rstb_2_mask                             (0x00000002)
#define SYS_PLL_2_BUS3_pllbus_pow_2_mask                              (0x00000001)
#define SYS_PLL_2_BUS3_pllbus_o_2(data)                               (0x00000008&((data)<<3))
#define SYS_PLL_2_BUS3_pllbus_oeb_2(data)                             (0x00000004&((data)<<2))
#define SYS_PLL_2_BUS3_pllbus_rstb_2(data)                            (0x00000002&((data)<<1))
#define SYS_PLL_2_BUS3_pllbus_pow_2(data)                             (0x00000001&(data))
#define SYS_PLL_2_BUS3_get_pllbus_o_2(data)                           ((0x00000008&(data))>>3)
#define SYS_PLL_2_BUS3_get_pllbus_oeb_2(data)                         ((0x00000004&(data))>>2)
#define SYS_PLL_2_BUS3_get_pllbus_rstb_2(data)                        ((0x00000002&(data))>>1)
#define SYS_PLL_2_BUS3_get_pllbus_pow_2(data)                         (0x00000001&(data))


#define SC_BUS2PLL_SSC                                                0x1800044c
#define SC_BUS2PLL_SSC_reg_addr                                       "0xb800044c"
#define SC_BUS2PLL_SSC_reg                                            0xb800044c
#define SC_BUS2PLL_SSC_inst_addr                                      "0x0113"
#define SC_BUS2PLL_SSC_inst                                           0x0113
#define SC_BUS2PLL_SSC_bus2_ssc_sse_shift                             (31)
#define SC_BUS2PLL_SSC_bus2_ssc_ckinv_shift                           (30)
#define SC_BUS2PLL_SSC_bus2_ssc_sss_shift                             (24)
#define SC_BUS2PLL_SSC_bus2_ssc_ssn_shift                             (16)
#define SC_BUS2PLL_SSC_bus2_ssc_ssfpv_shift                           (8)
#define SC_BUS2PLL_SSC_bus2_ssc_stms_shift                            (0)
#define SC_BUS2PLL_SSC_bus2_ssc_sse_mask                              (0x80000000)
#define SC_BUS2PLL_SSC_bus2_ssc_ckinv_mask                            (0x40000000)
#define SC_BUS2PLL_SSC_bus2_ssc_sss_mask                              (0x3F000000)
#define SC_BUS2PLL_SSC_bus2_ssc_ssn_mask                              (0x007F0000)
#define SC_BUS2PLL_SSC_bus2_ssc_ssfpv_mask                            (0x0000FF00)
#define SC_BUS2PLL_SSC_bus2_ssc_stms_mask                             (0x00000003)
#define SC_BUS2PLL_SSC_bus2_ssc_sse(data)                             (0x80000000&((data)<<31))
#define SC_BUS2PLL_SSC_bus2_ssc_ckinv(data)                           (0x40000000&((data)<<30))
#define SC_BUS2PLL_SSC_bus2_ssc_sss(data)                             (0x3F000000&((data)<<24))
#define SC_BUS2PLL_SSC_bus2_ssc_ssn(data)                             (0x007F0000&((data)<<16))
#define SC_BUS2PLL_SSC_bus2_ssc_ssfpv(data)                           (0x0000FF00&((data)<<8))
#define SC_BUS2PLL_SSC_bus2_ssc_stms(data)                            (0x00000003&(data))
#define SC_BUS2PLL_SSC_get_bus2_ssc_sse(data)                         ((0x80000000&(data))>>31)
#define SC_BUS2PLL_SSC_get_bus2_ssc_ckinv(data)                       ((0x40000000&(data))>>30)
#define SC_BUS2PLL_SSC_get_bus2_ssc_sss(data)                         ((0x3F000000&(data))>>24)
#define SC_BUS2PLL_SSC_get_bus2_ssc_ssn(data)                         ((0x007F0000&(data))>>16)
#define SC_BUS2PLL_SSC_get_bus2_ssc_ssfpv(data)                       ((0x0000FF00&(data))>>8)
#define SC_BUS2PLL_SSC_get_bus2_ssc_stms(data)                        (0x00000003&(data))


#define SYS_PLL_GPU1                                                  0x18000450
#define SYS_PLL_GPU1_reg_addr                                         "0xb8000450"
#define SYS_PLL_GPU1_reg                                              0xb8000450
#define SYS_PLL_GPU1_inst_addr                                        "0x0114"
#define SYS_PLL_GPU1_inst                                             0x0114
#define SYS_PLL_GPU1_pllgpu_n_shift                                   (20)
#define SYS_PLL_GPU1_pllgpu_m_shift                                   (12)
#define SYS_PLL_GPU1_pllgpu_ip_shift                                  (9)
#define SYS_PLL_GPU1_pllgpu_o_shift                                   (7)
#define SYS_PLL_GPU1_pllgpu_wdset_shift                               (6)
#define SYS_PLL_GPU1_pllgpu_wdrst_shift                               (5)
#define SYS_PLL_GPU1_pllgpu_cs_shift                                  (3)
#define SYS_PLL_GPU1_pllgpu_rs_shift                                  (0)
#define SYS_PLL_GPU1_pllgpu_n_mask                                    (0x00300000)
#define SYS_PLL_GPU1_pllgpu_m_mask                                    (0x0007F000)
#define SYS_PLL_GPU1_pllgpu_ip_mask                                   (0x00000E00)
#define SYS_PLL_GPU1_pllgpu_o_mask                                    (0x00000180)
#define SYS_PLL_GPU1_pllgpu_wdset_mask                                (0x00000040)
#define SYS_PLL_GPU1_pllgpu_wdrst_mask                                (0x00000020)
#define SYS_PLL_GPU1_pllgpu_cs_mask                                   (0x00000018)
#define SYS_PLL_GPU1_pllgpu_rs_mask                                   (0x00000007)
#define SYS_PLL_GPU1_pllgpu_n(data)                                   (0x00300000&((data)<<20))
#define SYS_PLL_GPU1_pllgpu_m(data)                                   (0x0007F000&((data)<<12))
#define SYS_PLL_GPU1_pllgpu_ip(data)                                  (0x00000E00&((data)<<9))
#define SYS_PLL_GPU1_pllgpu_o(data)                                   (0x00000180&((data)<<7))
#define SYS_PLL_GPU1_pllgpu_wdset(data)                               (0x00000040&((data)<<6))
#define SYS_PLL_GPU1_pllgpu_wdrst(data)                               (0x00000020&((data)<<5))
#define SYS_PLL_GPU1_pllgpu_cs(data)                                  (0x00000018&((data)<<3))
#define SYS_PLL_GPU1_pllgpu_rs(data)                                  (0x00000007&(data))
#define SYS_PLL_GPU1_get_pllgpu_n(data)                               ((0x00300000&(data))>>20)
#define SYS_PLL_GPU1_get_pllgpu_m(data)                               ((0x0007F000&(data))>>12)
#define SYS_PLL_GPU1_get_pllgpu_ip(data)                              ((0x00000E00&(data))>>9)
#define SYS_PLL_GPU1_get_pllgpu_o(data)                               ((0x00000180&(data))>>7)
#define SYS_PLL_GPU1_get_pllgpu_wdset(data)                           ((0x00000040&(data))>>6)
#define SYS_PLL_GPU1_get_pllgpu_wdrst(data)                           ((0x00000020&(data))>>5)
#define SYS_PLL_GPU1_get_pllgpu_cs(data)                              ((0x00000018&(data))>>3)
#define SYS_PLL_GPU1_get_pllgpu_rs(data)                              (0x00000007&(data))


#define SYS_PLL_GPU2                                                  0x18000454
#define SYS_PLL_GPU2_reg_addr                                         "0xb8000454"
#define SYS_PLL_GPU2_reg                                              0xb8000454
#define SYS_PLL_GPU2_inst_addr                                        "0x0115"
#define SYS_PLL_GPU2_inst                                             0x0115
#define SYS_PLL_GPU2_pllgpu_tst_shift                                 (3)
#define SYS_PLL_GPU2_pllgpu_oeb_shift                                 (2)
#define SYS_PLL_GPU2_pllgpu_rstb_shift                                (1)
#define SYS_PLL_GPU2_pllgpu_pow_shift                                 (0)
#define SYS_PLL_GPU2_pllgpu_tst_mask                                  (0x00000008)
#define SYS_PLL_GPU2_pllgpu_oeb_mask                                  (0x00000004)
#define SYS_PLL_GPU2_pllgpu_rstb_mask                                 (0x00000002)
#define SYS_PLL_GPU2_pllgpu_pow_mask                                  (0x00000001)
#define SYS_PLL_GPU2_pllgpu_tst(data)                                 (0x00000008&((data)<<3))
#define SYS_PLL_GPU2_pllgpu_oeb(data)                                 (0x00000004&((data)<<2))
#define SYS_PLL_GPU2_pllgpu_rstb(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_GPU2_pllgpu_pow(data)                                 (0x00000001&(data))
#define SYS_PLL_GPU2_get_pllgpu_tst(data)                             ((0x00000008&(data))>>3)
#define SYS_PLL_GPU2_get_pllgpu_oeb(data)                             ((0x00000004&(data))>>2)
#define SYS_PLL_GPU2_get_pllgpu_rstb(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_GPU2_get_pllgpu_pow(data)                             (0x00000001&(data))


#define SYS_PLL_2_GPU1                                                0x18000458
#define SYS_PLL_2_GPU1_reg_addr                                       "0xb8000458"
#define SYS_PLL_2_GPU1_reg                                            0xb8000458
#define SYS_PLL_2_GPU1_inst_addr                                      "0x0116"
#define SYS_PLL_2_GPU1_inst                                           0x0116
#define SYS_PLL_2_GPU1_pllgpu_n_2_shift                               (20)
#define SYS_PLL_2_GPU1_pllgpu_m_2_shift                               (12)
#define SYS_PLL_2_GPU1_pllgpu_ip_2_shift                              (9)
#define SYS_PLL_2_GPU1_pllgpu_o_2_shift                               (7)
#define SYS_PLL_2_GPU1_pllgpu_wdset_2_shift                           (6)
#define SYS_PLL_2_GPU1_pllgpu_wdrst_2_shift                           (5)
#define SYS_PLL_2_GPU1_pllgpu_cs_2_shift                              (3)
#define SYS_PLL_2_GPU1_pllgpu_rs_2_shift                              (0)
#define SYS_PLL_2_GPU1_pllgpu_n_2_mask                                (0x00300000)
#define SYS_PLL_2_GPU1_pllgpu_m_2_mask                                (0x0007F000)
#define SYS_PLL_2_GPU1_pllgpu_ip_2_mask                               (0x00000E00)
#define SYS_PLL_2_GPU1_pllgpu_o_2_mask                                (0x00000180)
#define SYS_PLL_2_GPU1_pllgpu_wdset_2_mask                            (0x00000040)
#define SYS_PLL_2_GPU1_pllgpu_wdrst_2_mask                            (0x00000020)
#define SYS_PLL_2_GPU1_pllgpu_cs_2_mask                               (0x00000018)
#define SYS_PLL_2_GPU1_pllgpu_rs_2_mask                               (0x00000007)
#define SYS_PLL_2_GPU1_pllgpu_n_2(data)                               (0x00300000&((data)<<20))
#define SYS_PLL_2_GPU1_pllgpu_m_2(data)                               (0x0007F000&((data)<<12))
#define SYS_PLL_2_GPU1_pllgpu_ip_2(data)                              (0x00000E00&((data)<<9))
#define SYS_PLL_2_GPU1_pllgpu_o_2(data)                               (0x00000180&((data)<<7))
#define SYS_PLL_2_GPU1_pllgpu_wdset_2(data)                           (0x00000040&((data)<<6))
#define SYS_PLL_2_GPU1_pllgpu_wdrst_2(data)                           (0x00000020&((data)<<5))
#define SYS_PLL_2_GPU1_pllgpu_cs_2(data)                              (0x00000018&((data)<<3))
#define SYS_PLL_2_GPU1_pllgpu_rs_2(data)                              (0x00000007&(data))
#define SYS_PLL_2_GPU1_get_pllgpu_n_2(data)                           ((0x00300000&(data))>>20)
#define SYS_PLL_2_GPU1_get_pllgpu_m_2(data)                           ((0x0007F000&(data))>>12)
#define SYS_PLL_2_GPU1_get_pllgpu_ip_2(data)                          ((0x00000E00&(data))>>9)
#define SYS_PLL_2_GPU1_get_pllgpu_o_2(data)                           ((0x00000180&(data))>>7)
#define SYS_PLL_2_GPU1_get_pllgpu_wdset_2(data)                       ((0x00000040&(data))>>6)
#define SYS_PLL_2_GPU1_get_pllgpu_wdrst_2(data)                       ((0x00000020&(data))>>5)
#define SYS_PLL_2_GPU1_get_pllgpu_cs_2(data)                          ((0x00000018&(data))>>3)
#define SYS_PLL_2_GPU1_get_pllgpu_rs_2(data)                          (0x00000007&(data))


#define SYS_PLL_2_GPU2                                                0x1800045c
#define SYS_PLL_2_GPU2_reg_addr                                       "0xb800045c"
#define SYS_PLL_2_GPU2_reg                                            0xb800045c
#define SYS_PLL_2_GPU2_inst_addr                                      "0x0117"
#define SYS_PLL_2_GPU2_inst                                           0x0117
#define SYS_PLL_2_GPU2_pllgpu_tst_2_shift                             (3)
#define SYS_PLL_2_GPU2_pllgpu_oeb_2_shift                             (2)
#define SYS_PLL_2_GPU2_pllgpu_rstb_2_shift                            (1)
#define SYS_PLL_2_GPU2_pllgpu_pow_2_shift                             (0)
#define SYS_PLL_2_GPU2_pllgpu_tst_2_mask                              (0x00000008)
#define SYS_PLL_2_GPU2_pllgpu_oeb_2_mask                              (0x00000004)
#define SYS_PLL_2_GPU2_pllgpu_rstb_2_mask                             (0x00000002)
#define SYS_PLL_2_GPU2_pllgpu_pow_2_mask                              (0x00000001)
#define SYS_PLL_2_GPU2_pllgpu_tst_2(data)                             (0x00000008&((data)<<3))
#define SYS_PLL_2_GPU2_pllgpu_oeb_2(data)                             (0x00000004&((data)<<2))
#define SYS_PLL_2_GPU2_pllgpu_rstb_2(data)                            (0x00000002&((data)<<1))
#define SYS_PLL_2_GPU2_pllgpu_pow_2(data)                             (0x00000001&(data))
#define SYS_PLL_2_GPU2_get_pllgpu_tst_2(data)                         ((0x00000008&(data))>>3)
#define SYS_PLL_2_GPU2_get_pllgpu_oeb_2(data)                         ((0x00000004&(data))>>2)
#define SYS_PLL_2_GPU2_get_pllgpu_rstb_2(data)                        ((0x00000002&(data))>>1)
#define SYS_PLL_2_GPU2_get_pllgpu_pow_2(data)                         (0x00000001&(data))


#define SYS_PLL_VODMA1                                                0x18000460
#define SYS_PLL_VODMA1_reg_addr                                       "0xb8000460"
#define SYS_PLL_VODMA1_reg                                            0xb8000460
#define SYS_PLL_VODMA1_inst_addr                                      "0x0118"
#define SYS_PLL_VODMA1_inst                                           0x0118
#define SYS_PLL_VODMA1_pllvodma_n_shift                               (20)
#define SYS_PLL_VODMA1_pllvodma_m_shift                               (12)
#define SYS_PLL_VODMA1_pllvodma_ip_shift                              (9)
#define SYS_PLL_VODMA1_pllvodma_o_shift                               (7)
#define SYS_PLL_VODMA1_pllvodma_wdset_shift                           (6)
#define SYS_PLL_VODMA1_pllvodma_wdrst_shift                           (5)
#define SYS_PLL_VODMA1_pllvodma_cs_shift                              (3)
#define SYS_PLL_VODMA1_pllvodma_rs_shift                              (0)
#define SYS_PLL_VODMA1_pllvodma_n_mask                                (0x00300000)
#define SYS_PLL_VODMA1_pllvodma_m_mask                                (0x0007F000)
#define SYS_PLL_VODMA1_pllvodma_ip_mask                               (0x00000E00)
#define SYS_PLL_VODMA1_pllvodma_o_mask                                (0x00000180)
#define SYS_PLL_VODMA1_pllvodma_wdset_mask                            (0x00000040)
#define SYS_PLL_VODMA1_pllvodma_wdrst_mask                            (0x00000020)
#define SYS_PLL_VODMA1_pllvodma_cs_mask                               (0x00000018)
#define SYS_PLL_VODMA1_pllvodma_rs_mask                               (0x00000007)
#define SYS_PLL_VODMA1_pllvodma_n(data)                               (0x00300000&((data)<<20))
#define SYS_PLL_VODMA1_pllvodma_m(data)                               (0x0007F000&((data)<<12))
#define SYS_PLL_VODMA1_pllvodma_ip(data)                              (0x00000E00&((data)<<9))
#define SYS_PLL_VODMA1_pllvodma_o(data)                               (0x00000180&((data)<<7))
#define SYS_PLL_VODMA1_pllvodma_wdset(data)                           (0x00000040&((data)<<6))
#define SYS_PLL_VODMA1_pllvodma_wdrst(data)                           (0x00000020&((data)<<5))
#define SYS_PLL_VODMA1_pllvodma_cs(data)                              (0x00000018&((data)<<3))
#define SYS_PLL_VODMA1_pllvodma_rs(data)                              (0x00000007&(data))
#define SYS_PLL_VODMA1_get_pllvodma_n(data)                           ((0x00300000&(data))>>20)
#define SYS_PLL_VODMA1_get_pllvodma_m(data)                           ((0x0007F000&(data))>>12)
#define SYS_PLL_VODMA1_get_pllvodma_ip(data)                          ((0x00000E00&(data))>>9)
#define SYS_PLL_VODMA1_get_pllvodma_o(data)                           ((0x00000180&(data))>>7)
#define SYS_PLL_VODMA1_get_pllvodma_wdset(data)                       ((0x00000040&(data))>>6)
#define SYS_PLL_VODMA1_get_pllvodma_wdrst(data)                       ((0x00000020&(data))>>5)
#define SYS_PLL_VODMA1_get_pllvodma_cs(data)                          ((0x00000018&(data))>>3)
#define SYS_PLL_VODMA1_get_pllvodma_rs(data)                          (0x00000007&(data))


#define SYS_PLL_VODMA2                                                0x18000464
#define SYS_PLL_VODMA2_reg_addr                                       "0xb8000464"
#define SYS_PLL_VODMA2_reg                                            0xb8000464
#define SYS_PLL_VODMA2_inst_addr                                      "0x0119"
#define SYS_PLL_VODMA2_inst                                           0x0119
#define SYS_PLL_VODMA2_pllvodma_tst_shift                             (3)
#define SYS_PLL_VODMA2_pllvodma_oeb_shift                             (2)
#define SYS_PLL_VODMA2_pllvodma_rstb_shift                            (1)
#define SYS_PLL_VODMA2_pllvodma_pow_shift                             (0)
#define SYS_PLL_VODMA2_pllvodma_tst_mask                              (0x00000008)
#define SYS_PLL_VODMA2_pllvodma_oeb_mask                              (0x00000004)
#define SYS_PLL_VODMA2_pllvodma_rstb_mask                             (0x00000002)
#define SYS_PLL_VODMA2_pllvodma_pow_mask                              (0x00000001)
#define SYS_PLL_VODMA2_pllvodma_tst(data)                             (0x00000008&((data)<<3))
#define SYS_PLL_VODMA2_pllvodma_oeb(data)                             (0x00000004&((data)<<2))
#define SYS_PLL_VODMA2_pllvodma_rstb(data)                            (0x00000002&((data)<<1))
#define SYS_PLL_VODMA2_pllvodma_pow(data)                             (0x00000001&(data))
#define SYS_PLL_VODMA2_get_pllvodma_tst(data)                         ((0x00000008&(data))>>3)
#define SYS_PLL_VODMA2_get_pllvodma_oeb(data)                         ((0x00000004&(data))>>2)
#define SYS_PLL_VODMA2_get_pllvodma_rstb(data)                        ((0x00000002&(data))>>1)
#define SYS_PLL_VODMA2_get_pllvodma_pow(data)                         (0x00000001&(data))


#define SYS_PLLBUS_TST                                                0x18000468
#define SYS_PLLBUS_TST_reg_addr                                       "0xb8000468"
#define SYS_PLLBUS_TST_reg                                            0xb8000468
#define SYS_PLLBUS_TST_inst_addr                                      "0x011A"
#define SYS_PLLBUS_TST_inst                                           0x011A
#define SYS_PLLBUS_TST_pllbus_reser_shift                             (16)
#define SYS_PLLBUS_TST_pllbus_reg_shift                               (12)
#define SYS_PLLBUS_TST_pllbustst_div_shift                            (8)
#define SYS_PLLBUS_TST_pllbustst_sel_shift                            (0)
#define SYS_PLLBUS_TST_pllbus_reser_mask                              (0x000F0000)
#define SYS_PLLBUS_TST_pllbus_reg_mask                                (0x00003000)
#define SYS_PLLBUS_TST_pllbustst_div_mask                             (0x00000300)
#define SYS_PLLBUS_TST_pllbustst_sel_mask                             (0x0000001F)
#define SYS_PLLBUS_TST_pllbus_reser(data)                             (0x000F0000&((data)<<16))
#define SYS_PLLBUS_TST_pllbus_reg(data)                               (0x00003000&((data)<<12))
#define SYS_PLLBUS_TST_pllbustst_div(data)                            (0x00000300&((data)<<8))
#define SYS_PLLBUS_TST_pllbustst_sel(data)                            (0x0000001F&(data))
#define SYS_PLLBUS_TST_get_pllbus_reser(data)                         ((0x000F0000&(data))>>16)
#define SYS_PLLBUS_TST_get_pllbus_reg(data)                           ((0x00003000&(data))>>12)
#define SYS_PLLBUS_TST_get_pllbustst_div(data)                        ((0x00000300&(data))>>8)
#define SYS_PLLBUS_TST_get_pllbustst_sel(data)                        (0x0000001F&(data))


#define SYS_PLL_DISP_SD1                                              0x18000470
#define SYS_PLL_DISP_SD1_reg_addr                                     "0xb8000470"
#define SYS_PLL_DISP_SD1_reg                                          0xb8000470
#define SYS_PLL_DISP_SD1_inst_addr                                    "0x011C"
#define SYS_PLL_DISP_SD1_inst                                         0x011C
#define SYS_PLL_DISP_SD1_plldds_n_shift                               (30)
#define SYS_PLL_DISP_SD1_plldds_m_shift                               (23)
#define SYS_PLL_DISP_SD1_plldds_ip_shift                              (20)
#define SYS_PLL_DISP_SD1_plldds_rs_shift                              (17)
#define SYS_PLL_DISP_SD1_plldds_cs_shift                              (15)
#define SYS_PLL_DISP_SD1_plldds_cp_shift                              (13)
#define SYS_PLL_DISP_SD1_plldds_r3_shift                              (10)
#define SYS_PLL_DISP_SD1_plldds_c3_shift                              (8)
#define SYS_PLL_DISP_SD1_plldds_pi_rl_shift                           (6)
#define SYS_PLL_DISP_SD1_plldds_pi_rs_shift                           (4)
#define SYS_PLL_DISP_SD1_plldds_pi_bias_shift                         (2)
#define SYS_PLL_DISP_SD1_plldds_wdmode_shift                          (0)
#define SYS_PLL_DISP_SD1_plldds_n_mask                                (0xC0000000)
#define SYS_PLL_DISP_SD1_plldds_m_mask                                (0x3F800000)
#define SYS_PLL_DISP_SD1_plldds_ip_mask                               (0x00700000)
#define SYS_PLL_DISP_SD1_plldds_rs_mask                               (0x000E0000)
#define SYS_PLL_DISP_SD1_plldds_cs_mask                               (0x00018000)
#define SYS_PLL_DISP_SD1_plldds_cp_mask                               (0x00006000)
#define SYS_PLL_DISP_SD1_plldds_r3_mask                               (0x00001C00)
#define SYS_PLL_DISP_SD1_plldds_c3_mask                               (0x00000300)
#define SYS_PLL_DISP_SD1_plldds_pi_rl_mask                            (0x000000C0)
#define SYS_PLL_DISP_SD1_plldds_pi_rs_mask                            (0x00000030)
#define SYS_PLL_DISP_SD1_plldds_pi_bias_mask                          (0x0000000C)
#define SYS_PLL_DISP_SD1_plldds_wdmode_mask                           (0x00000003)
#define SYS_PLL_DISP_SD1_plldds_n(data)                               (0xC0000000&((data)<<30))
#define SYS_PLL_DISP_SD1_plldds_m(data)                               (0x3F800000&((data)<<23))
#define SYS_PLL_DISP_SD1_plldds_ip(data)                              (0x00700000&((data)<<20))
#define SYS_PLL_DISP_SD1_plldds_rs(data)                              (0x000E0000&((data)<<17))
#define SYS_PLL_DISP_SD1_plldds_cs(data)                              (0x00018000&((data)<<15))
#define SYS_PLL_DISP_SD1_plldds_cp(data)                              (0x00006000&((data)<<13))
#define SYS_PLL_DISP_SD1_plldds_r3(data)                              (0x00001C00&((data)<<10))
#define SYS_PLL_DISP_SD1_plldds_c3(data)                              (0x00000300&((data)<<8))
#define SYS_PLL_DISP_SD1_plldds_pi_rl(data)                           (0x000000C0&((data)<<6))
#define SYS_PLL_DISP_SD1_plldds_pi_rs(data)                           (0x00000030&((data)<<4))
#define SYS_PLL_DISP_SD1_plldds_pi_bias(data)                         (0x0000000C&((data)<<2))
#define SYS_PLL_DISP_SD1_plldds_wdmode(data)                          (0x00000003&(data))
#define SYS_PLL_DISP_SD1_get_plldds_n(data)                           ((0xC0000000&(data))>>30)
#define SYS_PLL_DISP_SD1_get_plldds_m(data)                           ((0x3F800000&(data))>>23)
#define SYS_PLL_DISP_SD1_get_plldds_ip(data)                          ((0x00700000&(data))>>20)
#define SYS_PLL_DISP_SD1_get_plldds_rs(data)                          ((0x000E0000&(data))>>17)
#define SYS_PLL_DISP_SD1_get_plldds_cs(data)                          ((0x00018000&(data))>>15)
#define SYS_PLL_DISP_SD1_get_plldds_cp(data)                          ((0x00006000&(data))>>13)
#define SYS_PLL_DISP_SD1_get_plldds_r3(data)                          ((0x00001C00&(data))>>10)
#define SYS_PLL_DISP_SD1_get_plldds_c3(data)                          ((0x00000300&(data))>>8)
#define SYS_PLL_DISP_SD1_get_plldds_pi_rl(data)                       ((0x000000C0&(data))>>6)
#define SYS_PLL_DISP_SD1_get_plldds_pi_rs(data)                       ((0x00000030&(data))>>4)
#define SYS_PLL_DISP_SD1_get_plldds_pi_bias(data)                     ((0x0000000C&(data))>>2)
#define SYS_PLL_DISP_SD1_get_plldds_wdmode(data)                      (0x00000003&(data))


#define SYS_PLL_DISP_SD2                                              0x18000474
#define SYS_PLL_DISP_SD2_reg_addr                                     "0xb8000474"
#define SYS_PLL_DISP_SD2_reg                                          0xb8000474
#define SYS_PLL_DISP_SD2_inst_addr                                    "0x011D"
#define SYS_PLL_DISP_SD2_inst                                         0x011D
#define SYS_PLL_DISP_SD2_dummy18000474_28_25_shift                    (25)
#define SYS_PLL_DISP_SD2_pcr_a_smooth_en_shift                        (24)
#define SYS_PLL_DISP_SD2_dummy18000474_23_shift                       (23)
#define SYS_PLL_DISP_SD2_pcr_a_phase_sel_shift                        (22)
#define SYS_PLL_DISP_SD2_dummy18000474_21_shift                       (21)
#define SYS_PLL_DISP_SD2_pcr_a_ctl_en_shift                           (20)
#define SYS_PLL_DISP_SD2_dummy18000474_19_shift                       (19)
#define SYS_PLL_DISP_SD2_plldds_fupdn_shift                           (18)
#define SYS_PLL_DISP_SD2_dummy18000474_17_shift                       (17)
#define SYS_PLL_DISP_SD2_plldds_ddsen_shift                           (16)
#define SYS_PLL_DISP_SD2_dummy18000474_15_shift                       (15)
#define SYS_PLL_DISP_SD2_plldds_vcorb_shift                           (14)
#define SYS_PLL_DISP_SD2_dummy18000474_13_shift                       (13)
#define SYS_PLL_DISP_SD2_plldds_tst_shift                             (12)
#define SYS_PLL_DISP_SD2_plldds_pstst_shift                           (11)
#define SYS_PLL_DISP_SD2_dummy18000474_10_shift                       (10)
#define SYS_PLL_DISP_SD2_dummy18000474_28_25_mask                     (0x1E000000)
#define SYS_PLL_DISP_SD2_pcr_a_smooth_en_mask                         (0x01000000)
#define SYS_PLL_DISP_SD2_dummy18000474_23_mask                        (0x00800000)
#define SYS_PLL_DISP_SD2_pcr_a_phase_sel_mask                         (0x00400000)
#define SYS_PLL_DISP_SD2_dummy18000474_21_mask                        (0x00200000)
#define SYS_PLL_DISP_SD2_pcr_a_ctl_en_mask                            (0x00100000)
#define SYS_PLL_DISP_SD2_dummy18000474_19_mask                        (0x00080000)
#define SYS_PLL_DISP_SD2_plldds_fupdn_mask                            (0x00040000)
#define SYS_PLL_DISP_SD2_dummy18000474_17_mask                        (0x00020000)
#define SYS_PLL_DISP_SD2_plldds_ddsen_mask                            (0x00010000)
#define SYS_PLL_DISP_SD2_dummy18000474_15_mask                        (0x00008000)
#define SYS_PLL_DISP_SD2_plldds_vcorb_mask                            (0x00004000)
#define SYS_PLL_DISP_SD2_dummy18000474_13_mask                        (0x00002000)
#define SYS_PLL_DISP_SD2_plldds_tst_mask                              (0x00001000)
#define SYS_PLL_DISP_SD2_plldds_pstst_mask                            (0x00000800)
#define SYS_PLL_DISP_SD2_dummy18000474_10_mask                        (0x00000400)
#define SYS_PLL_DISP_SD2_dummy18000474_28_25(data)                    (0x1E000000&((data)<<25))
#define SYS_PLL_DISP_SD2_pcr_a_smooth_en(data)                        (0x01000000&((data)<<24))
#define SYS_PLL_DISP_SD2_dummy18000474_23(data)                       (0x00800000&((data)<<23))
#define SYS_PLL_DISP_SD2_pcr_a_phase_sel(data)                        (0x00400000&((data)<<22))
#define SYS_PLL_DISP_SD2_dummy18000474_21(data)                       (0x00200000&((data)<<21))
#define SYS_PLL_DISP_SD2_pcr_a_ctl_en(data)                           (0x00100000&((data)<<20))
#define SYS_PLL_DISP_SD2_dummy18000474_19(data)                       (0x00080000&((data)<<19))
#define SYS_PLL_DISP_SD2_plldds_fupdn(data)                           (0x00040000&((data)<<18))
#define SYS_PLL_DISP_SD2_dummy18000474_17(data)                       (0x00020000&((data)<<17))
#define SYS_PLL_DISP_SD2_plldds_ddsen(data)                           (0x00010000&((data)<<16))
#define SYS_PLL_DISP_SD2_dummy18000474_15(data)                       (0x00008000&((data)<<15))
#define SYS_PLL_DISP_SD2_plldds_vcorb(data)                           (0x00004000&((data)<<14))
#define SYS_PLL_DISP_SD2_dummy18000474_13(data)                       (0x00002000&((data)<<13))
#define SYS_PLL_DISP_SD2_plldds_tst(data)                             (0x00001000&((data)<<12))
#define SYS_PLL_DISP_SD2_plldds_pstst(data)                           (0x00000800&((data)<<11))
#define SYS_PLL_DISP_SD2_dummy18000474_10(data)                       (0x00000400&((data)<<10))
#define SYS_PLL_DISP_SD2_get_dummy18000474_28_25(data)                ((0x1E000000&(data))>>25)
#define SYS_PLL_DISP_SD2_get_pcr_a_smooth_en(data)                    ((0x01000000&(data))>>24)
#define SYS_PLL_DISP_SD2_get_dummy18000474_23(data)                   ((0x00800000&(data))>>23)
#define SYS_PLL_DISP_SD2_get_pcr_a_phase_sel(data)                    ((0x00400000&(data))>>22)
#define SYS_PLL_DISP_SD2_get_dummy18000474_21(data)                   ((0x00200000&(data))>>21)
#define SYS_PLL_DISP_SD2_get_pcr_a_ctl_en(data)                       ((0x00100000&(data))>>20)
#define SYS_PLL_DISP_SD2_get_dummy18000474_19(data)                   ((0x00080000&(data))>>19)
#define SYS_PLL_DISP_SD2_get_plldds_fupdn(data)                       ((0x00040000&(data))>>18)
#define SYS_PLL_DISP_SD2_get_dummy18000474_17(data)                   ((0x00020000&(data))>>17)
#define SYS_PLL_DISP_SD2_get_plldds_ddsen(data)                       ((0x00010000&(data))>>16)
#define SYS_PLL_DISP_SD2_get_dummy18000474_15(data)                   ((0x00008000&(data))>>15)
#define SYS_PLL_DISP_SD2_get_plldds_vcorb(data)                       ((0x00004000&(data))>>14)
#define SYS_PLL_DISP_SD2_get_dummy18000474_13(data)                   ((0x00002000&(data))>>13)
#define SYS_PLL_DISP_SD2_get_plldds_tst(data)                         ((0x00001000&(data))>>12)
#define SYS_PLL_DISP_SD2_get_plldds_pstst(data)                       ((0x00000800&(data))>>11)
#define SYS_PLL_DISP_SD2_get_dummy18000474_10(data)                   ((0x00000400&(data))>>10)


#define SYS_PLL_DISP_SD3                                              0x18000478
#define SYS_PLL_DISP_SD3_reg_addr                                     "0xb8000478"
#define SYS_PLL_DISP_SD3_reg                                          0xb8000478
#define SYS_PLL_DISP_SD3_inst_addr                                    "0x011E"
#define SYS_PLL_DISP_SD3_inst                                         0x011E
#define SYS_PLL_DISP_SD3_dummy18000478_30_shift                       (30)
#define SYS_PLL_DISP_SD3_psaud1_fupdn_shift                           (29)
#define SYS_PLL_DISP_SD3_psaud1_div_shift                             (28)
#define SYS_PLL_DISP_SD3_dummy18000478_27_shift                       (27)
#define SYS_PLL_DISP_SD3_psaud1_tst_shift                             (26)
#define SYS_PLL_DISP_SD3_psaud1_psen_shift                            (25)
#define SYS_PLL_DISP_SD3_dummy18000478_24_shift                       (24)
#define SYS_PLL_DISP_SD3_psaud2_fupdn_shift                           (23)
#define SYS_PLL_DISP_SD3_psaud2_div_shift                             (22)
#define SYS_PLL_DISP_SD3_psaud2_tst_shift                             (21)
#define SYS_PLL_DISP_SD3_psaud2_psen_shift                            (20)
#define SYS_PLL_DISP_SD3_psaud1_oeb_shift                             (3)
#define SYS_PLL_DISP_SD3_psaud1_rstb_shift                            (2)
#define SYS_PLL_DISP_SD3_psaud2_oeb_shift                             (1)
#define SYS_PLL_DISP_SD3_psaud2_rstb_shift                            (0)
#define SYS_PLL_DISP_SD3_dummy18000478_30_mask                        (0x40000000)
#define SYS_PLL_DISP_SD3_psaud1_fupdn_mask                            (0x20000000)
#define SYS_PLL_DISP_SD3_psaud1_div_mask                              (0x10000000)
#define SYS_PLL_DISP_SD3_dummy18000478_27_mask                        (0x08000000)
#define SYS_PLL_DISP_SD3_psaud1_tst_mask                              (0x04000000)
#define SYS_PLL_DISP_SD3_psaud1_psen_mask                             (0x02000000)
#define SYS_PLL_DISP_SD3_dummy18000478_24_mask                        (0x01000000)
#define SYS_PLL_DISP_SD3_psaud2_fupdn_mask                            (0x00800000)
#define SYS_PLL_DISP_SD3_psaud2_div_mask                              (0x00400000)
#define SYS_PLL_DISP_SD3_psaud2_tst_mask                              (0x00200000)
#define SYS_PLL_DISP_SD3_psaud2_psen_mask                             (0x00100000)
#define SYS_PLL_DISP_SD3_psaud1_oeb_mask                              (0x00000008)
#define SYS_PLL_DISP_SD3_psaud1_rstb_mask                             (0x00000004)
#define SYS_PLL_DISP_SD3_psaud2_oeb_mask                              (0x00000002)
#define SYS_PLL_DISP_SD3_psaud2_rstb_mask                             (0x00000001)
#define SYS_PLL_DISP_SD3_dummy18000478_30(data)                       (0x40000000&((data)<<30))
#define SYS_PLL_DISP_SD3_psaud1_fupdn(data)                           (0x20000000&((data)<<29))
#define SYS_PLL_DISP_SD3_psaud1_div(data)                             (0x10000000&((data)<<28))
#define SYS_PLL_DISP_SD3_dummy18000478_27(data)                       (0x08000000&((data)<<27))
#define SYS_PLL_DISP_SD3_psaud1_tst(data)                             (0x04000000&((data)<<26))
#define SYS_PLL_DISP_SD3_psaud1_psen(data)                            (0x02000000&((data)<<25))
#define SYS_PLL_DISP_SD3_dummy18000478_24(data)                       (0x01000000&((data)<<24))
#define SYS_PLL_DISP_SD3_psaud2_fupdn(data)                           (0x00800000&((data)<<23))
#define SYS_PLL_DISP_SD3_psaud2_div(data)                             (0x00400000&((data)<<22))
#define SYS_PLL_DISP_SD3_psaud2_tst(data)                             (0x00200000&((data)<<21))
#define SYS_PLL_DISP_SD3_psaud2_psen(data)                            (0x00100000&((data)<<20))
#define SYS_PLL_DISP_SD3_psaud1_oeb(data)                             (0x00000008&((data)<<3))
#define SYS_PLL_DISP_SD3_psaud1_rstb(data)                            (0x00000004&((data)<<2))
#define SYS_PLL_DISP_SD3_psaud2_oeb(data)                             (0x00000002&((data)<<1))
#define SYS_PLL_DISP_SD3_psaud2_rstb(data)                            (0x00000001&(data))
#define SYS_PLL_DISP_SD3_get_dummy18000478_30(data)                   ((0x40000000&(data))>>30)
#define SYS_PLL_DISP_SD3_get_psaud1_fupdn(data)                       ((0x20000000&(data))>>29)
#define SYS_PLL_DISP_SD3_get_psaud1_div(data)                         ((0x10000000&(data))>>28)
#define SYS_PLL_DISP_SD3_get_dummy18000478_27(data)                   ((0x08000000&(data))>>27)
#define SYS_PLL_DISP_SD3_get_psaud1_tst(data)                         ((0x04000000&(data))>>26)
#define SYS_PLL_DISP_SD3_get_psaud1_psen(data)                        ((0x02000000&(data))>>25)
#define SYS_PLL_DISP_SD3_get_dummy18000478_24(data)                   ((0x01000000&(data))>>24)
#define SYS_PLL_DISP_SD3_get_psaud2_fupdn(data)                       ((0x00800000&(data))>>23)
#define SYS_PLL_DISP_SD3_get_psaud2_div(data)                         ((0x00400000&(data))>>22)
#define SYS_PLL_DISP_SD3_get_psaud2_tst(data)                         ((0x00200000&(data))>>21)
#define SYS_PLL_DISP_SD3_get_psaud2_psen(data)                        ((0x00100000&(data))>>20)
#define SYS_PLL_DISP_SD3_get_psaud1_oeb(data)                         ((0x00000008&(data))>>3)
#define SYS_PLL_DISP_SD3_get_psaud1_rstb(data)                        ((0x00000004&(data))>>2)
#define SYS_PLL_DISP_SD3_get_psaud2_oeb(data)                         ((0x00000002&(data))>>1)
#define SYS_PLL_DISP_SD3_get_psaud2_rstb(data)                        (0x00000001&(data))


#define SYS_PLL_DISP_SD4                                              0x1800047c
#define SYS_PLL_DISP_SD4_reg_addr                                     "0xb800047c"
#define SYS_PLL_DISP_SD4_reg                                          0xb800047c
#define SYS_PLL_DISP_SD4_inst_addr                                    "0x011F"
#define SYS_PLL_DISP_SD4_inst                                         0x011F
#define SYS_PLL_DISP_SD4_plldds_o_shift                               (4)
#define SYS_PLL_DISP_SD4_plldds_oeb_shift                             (2)
#define SYS_PLL_DISP_SD4_plldds_rstb_shift                            (1)
#define SYS_PLL_DISP_SD4_plldds_pow_shift                             (0)
#define SYS_PLL_DISP_SD4_plldds_o_mask                                (0x00000030)
#define SYS_PLL_DISP_SD4_plldds_oeb_mask                              (0x00000004)
#define SYS_PLL_DISP_SD4_plldds_rstb_mask                             (0x00000002)
#define SYS_PLL_DISP_SD4_plldds_pow_mask                              (0x00000001)
#define SYS_PLL_DISP_SD4_plldds_o(data)                               (0x00000030&((data)<<4))
#define SYS_PLL_DISP_SD4_plldds_oeb(data)                             (0x00000004&((data)<<2))
#define SYS_PLL_DISP_SD4_plldds_rstb(data)                            (0x00000002&((data)<<1))
#define SYS_PLL_DISP_SD4_plldds_pow(data)                             (0x00000001&(data))
#define SYS_PLL_DISP_SD4_get_plldds_o(data)                           ((0x00000030&(data))>>4)
#define SYS_PLL_DISP_SD4_get_plldds_oeb(data)                         ((0x00000004&(data))>>2)
#define SYS_PLL_DISP_SD4_get_plldds_rstb(data)                        ((0x00000002&(data))>>1)
#define SYS_PLL_DISP_SD4_get_plldds_pow(data)                         (0x00000001&(data))


#define SYS_PLL_DISP_SD5                                              0x18000480
#define SYS_PLL_DISP_SD5_reg_addr                                     "0xb8000480"
#define SYS_PLL_DISP_SD5_reg                                          0xb8000480
#define SYS_PLL_DISP_SD5_inst_addr                                    "0x0120"
#define SYS_PLL_DISP_SD5_inst                                         0x0120
#define SYS_PLL_DISP_SD5_plldds_pcr_acc_shift                         (16)
#define SYS_PLL_DISP_SD5_plldds_pcr_overflow_shift                    (0)
#define SYS_PLL_DISP_SD5_plldds_pcr_acc_mask                          (0xFFFF0000)
#define SYS_PLL_DISP_SD5_plldds_pcr_overflow_mask                     (0x0000FFFF)
#define SYS_PLL_DISP_SD5_plldds_pcr_acc(data)                         (0xFFFF0000&((data)<<16))
#define SYS_PLL_DISP_SD5_plldds_pcr_overflow(data)                    (0x0000FFFF&(data))
#define SYS_PLL_DISP_SD5_get_plldds_pcr_acc(data)                     ((0xFFFF0000&(data))>>16)
#define SYS_PLL_DISP_SD5_get_plldds_pcr_overflow(data)                (0x0000FFFF&(data))


#define SYS_PLL_DISP_SD6                                              0x18000484
#define SYS_PLL_DISP_SD6_reg_addr                                     "0xb8000484"
#define SYS_PLL_DISP_SD6_reg                                          0xb8000484
#define SYS_PLL_DISP_SD6_inst_addr                                    "0x0121"
#define SYS_PLL_DISP_SD6_inst                                         0x0121
#define SYS_PLL_DISP_SD6_n_pcr_a_n_nxt_shift                          (16)
#define SYS_PLL_DISP_SD6_pcr_a_n_nxt_shift                            (0)
#define SYS_PLL_DISP_SD6_n_pcr_a_n_nxt_mask                           (0xFFFF0000)
#define SYS_PLL_DISP_SD6_pcr_a_n_nxt_mask                             (0x0000FFFF)
#define SYS_PLL_DISP_SD6_n_pcr_a_n_nxt(data)                          (0xFFFF0000&((data)<<16))
#define SYS_PLL_DISP_SD6_pcr_a_n_nxt(data)                            (0x0000FFFF&(data))
#define SYS_PLL_DISP_SD6_get_n_pcr_a_n_nxt(data)                      ((0xFFFF0000&(data))>>16)
#define SYS_PLL_DISP_SD6_get_pcr_a_n_nxt(data)                        (0x0000FFFF&(data))


#define SYS_PLL_DISP_SD7                                              0x18000488
#define SYS_PLL_DISP_SD7_reg_addr                                     "0xb8000488"
#define SYS_PLL_DISP_SD7_reg                                          0xb8000488
#define SYS_PLL_DISP_SD7_inst_addr                                    "0x0122"
#define SYS_PLL_DISP_SD7_inst                                         0x0122
#define SYS_PLL_DISP_SD7_pcr_a_n_nxt_add_shift                        (16)
#define SYS_PLL_DISP_SD7_pcr_a_n_nxt_add_period_shift                 (0)
#define SYS_PLL_DISP_SD7_pcr_a_n_nxt_add_mask                         (0x00FF0000)
#define SYS_PLL_DISP_SD7_pcr_a_n_nxt_add_period_mask                  (0x0000FFFF)
#define SYS_PLL_DISP_SD7_pcr_a_n_nxt_add(data)                        (0x00FF0000&((data)<<16))
#define SYS_PLL_DISP_SD7_pcr_a_n_nxt_add_period(data)                 (0x0000FFFF&(data))
#define SYS_PLL_DISP_SD7_get_pcr_a_n_nxt_add(data)                    ((0x00FF0000&(data))>>16)
#define SYS_PLL_DISP_SD7_get_pcr_a_n_nxt_add_period(data)             (0x0000FFFF&(data))


#define AI_CLKCR                                                      0x1800048c
#define AI_CLKCR_reg_addr                                             "0xb800048c"
#define AI_CLKCR_reg                                                  0xb800048c
#define AI_CLKCR_inst_addr                                            "0x0123"
#define AI_CLKCR_inst                                                 0x0123
#define AI_CLKCR_swsce_shift                                          (25)
#define AI_CLKCR_tme_shift                                            (23)
#define AI_CLKCR_tmps_shift                                           (20)
#define AI_CLKCR_psc_shift                                            (19)
#define AI_CLKCR_swcs_shift                                           (9)
#define AI_CLKCR_sd_shift                                             (1)
#define AI_CLKCR_su_shift                                             (0)
#define AI_CLKCR_swsce_mask                                           (0x02000000)
#define AI_CLKCR_tme_mask                                             (0x00800000)
#define AI_CLKCR_tmps_mask                                            (0x00100000)
#define AI_CLKCR_psc_mask                                             (0x00080000)
#define AI_CLKCR_swcs_mask                                            (0x0000FE00)
#define AI_CLKCR_sd_mask                                              (0x00000002)
#define AI_CLKCR_su_mask                                              (0x00000001)
#define AI_CLKCR_swsce(data)                                          (0x02000000&((data)<<25))
#define AI_CLKCR_tme(data)                                            (0x00800000&((data)<<23))
#define AI_CLKCR_tmps(data)                                           (0x00100000&((data)<<20))
#define AI_CLKCR_psc(data)                                            (0x00080000&((data)<<19))
#define AI_CLKCR_swcs(data)                                           (0x0000FE00&((data)<<9))
#define AI_CLKCR_sd(data)                                             (0x00000002&((data)<<1))
#define AI_CLKCR_su(data)                                             (0x00000001&(data))
#define AI_CLKCR_get_swsce(data)                                      ((0x02000000&(data))>>25)
#define AI_CLKCR_get_tme(data)                                        ((0x00800000&(data))>>23)
#define AI_CLKCR_get_tmps(data)                                       ((0x00100000&(data))>>20)
#define AI_CLKCR_get_psc(data)                                        ((0x00080000&(data))>>19)
#define AI_CLKCR_get_swcs(data)                                       ((0x0000FE00&(data))>>9)
#define AI_CLKCR_get_sd(data)                                         ((0x00000002&(data))>>1)
#define AI_CLKCR_get_su(data)                                         (0x00000001&(data))


#define SYS_PLL_DISP1                                                 0x18000490
#define SYS_PLL_DISP1_reg_addr                                        "0xb8000490"
#define SYS_PLL_DISP1_reg                                             0xb8000490
#define SYS_PLL_DISP1_inst_addr                                       "0x0124"
#define SYS_PLL_DISP1_inst                                            0x0124
#define SYS_PLL_DISP1_dpll_m_shift                                    (20)
#define SYS_PLL_DISP1_dpll_n_shift                                    (12)
#define SYS_PLL_DISP1_dpll_ip_shift                                   (8)
#define SYS_PLL_DISP1_dpll_rs_shift                                   (4)
#define SYS_PLL_DISP1_dpll_cp_shift                                   (2)
#define SYS_PLL_DISP1_dpll_cs_shift                                   (0)
#define SYS_PLL_DISP1_dpll_m_mask                                     (0x0FF00000)
#define SYS_PLL_DISP1_dpll_n_mask                                     (0x00007000)
#define SYS_PLL_DISP1_dpll_ip_mask                                    (0x00000700)
#define SYS_PLL_DISP1_dpll_rs_mask                                    (0x00000070)
#define SYS_PLL_DISP1_dpll_cp_mask                                    (0x0000000C)
#define SYS_PLL_DISP1_dpll_cs_mask                                    (0x00000003)
#define SYS_PLL_DISP1_dpll_m(data)                                    (0x0FF00000&((data)<<20))
#define SYS_PLL_DISP1_dpll_n(data)                                    (0x00007000&((data)<<12))
#define SYS_PLL_DISP1_dpll_ip(data)                                   (0x00000700&((data)<<8))
#define SYS_PLL_DISP1_dpll_rs(data)                                   (0x00000070&((data)<<4))
#define SYS_PLL_DISP1_dpll_cp(data)                                   (0x0000000C&((data)<<2))
#define SYS_PLL_DISP1_dpll_cs(data)                                   (0x00000003&(data))
#define SYS_PLL_DISP1_get_dpll_m(data)                                ((0x0FF00000&(data))>>20)
#define SYS_PLL_DISP1_get_dpll_n(data)                                ((0x00007000&(data))>>12)
#define SYS_PLL_DISP1_get_dpll_ip(data)                               ((0x00000700&(data))>>8)
#define SYS_PLL_DISP1_get_dpll_rs(data)                               ((0x00000070&(data))>>4)
#define SYS_PLL_DISP1_get_dpll_cp(data)                               ((0x0000000C&(data))>>2)
#define SYS_PLL_DISP1_get_dpll_cs(data)                               (0x00000003&(data))


#define SYS_PLL_DISP2                                                 0x18000494
#define SYS_PLL_DISP2_reg_addr                                        "0xb8000494"
#define SYS_PLL_DISP2_reg                                             0xb8000494
#define SYS_PLL_DISP2_inst_addr                                       "0x0125"
#define SYS_PLL_DISP2_inst                                            0x0125
#define SYS_PLL_DISP2_dpll_reser_shift                                (24)
#define SYS_PLL_DISP2_dpll_reg_shift                                  (22)
#define SYS_PLL_DISP2_dpll_fupdn_shift                                (21)
#define SYS_PLL_DISP2_dpll_stop_shift                                 (20)
#define SYS_PLL_DISP2_dpll_reserve_shift                              (17)
#define SYS_PLL_DISP2_dpll_bpphs_shift                                (16)
#define SYS_PLL_DISP2_dpll_bpn_shift                                  (14)
#define SYS_PLL_DISP2_dpll_o_shift                                    (12)
#define SYS_PLL_DISP2_dpll_rstb_shift                                 (6)
#define SYS_PLL_DISP2_dpll_wdrst_shift                                (5)
#define SYS_PLL_DISP2_dpll_wdset_shift                                (4)
#define SYS_PLL_DISP2_dpll_clksel_shift                               (3)
#define SYS_PLL_DISP2_dpll_freeze_shift                               (2)
#define SYS_PLL_DISP2_dpll_vcorstb_shift                              (1)
#define SYS_PLL_DISP2_dpll_pwdn_shift                                 (0)
#define SYS_PLL_DISP2_dpll_reser_mask                                 (0x0F000000)
#define SYS_PLL_DISP2_dpll_reg_mask                                   (0x00C00000)
#define SYS_PLL_DISP2_dpll_fupdn_mask                                 (0x00200000)
#define SYS_PLL_DISP2_dpll_stop_mask                                  (0x00100000)
#define SYS_PLL_DISP2_dpll_reserve_mask                               (0x00020000)
#define SYS_PLL_DISP2_dpll_bpphs_mask                                 (0x00010000)
#define SYS_PLL_DISP2_dpll_bpn_mask                                   (0x00004000)
#define SYS_PLL_DISP2_dpll_o_mask                                     (0x00003000)
#define SYS_PLL_DISP2_dpll_rstb_mask                                  (0x00000040)
#define SYS_PLL_DISP2_dpll_wdrst_mask                                 (0x00000020)
#define SYS_PLL_DISP2_dpll_wdset_mask                                 (0x00000010)
#define SYS_PLL_DISP2_dpll_clksel_mask                                (0x00000008)
#define SYS_PLL_DISP2_dpll_freeze_mask                                (0x00000004)
#define SYS_PLL_DISP2_dpll_vcorstb_mask                               (0x00000002)
#define SYS_PLL_DISP2_dpll_pwdn_mask                                  (0x00000001)
#define SYS_PLL_DISP2_dpll_reser(data)                                (0x0F000000&((data)<<24))
#define SYS_PLL_DISP2_dpll_reg(data)                                  (0x00C00000&((data)<<22))
#define SYS_PLL_DISP2_dpll_fupdn(data)                                (0x00200000&((data)<<21))
#define SYS_PLL_DISP2_dpll_stop(data)                                 (0x00100000&((data)<<20))
#define SYS_PLL_DISP2_dpll_reserve(data)                              (0x00020000&((data)<<17))
#define SYS_PLL_DISP2_dpll_bpphs(data)                                (0x00010000&((data)<<16))
#define SYS_PLL_DISP2_dpll_bpn(data)                                  (0x00004000&((data)<<14))
#define SYS_PLL_DISP2_dpll_o(data)                                    (0x00003000&((data)<<12))
#define SYS_PLL_DISP2_dpll_rstb(data)                                 (0x00000040&((data)<<6))
#define SYS_PLL_DISP2_dpll_wdrst(data)                                (0x00000020&((data)<<5))
#define SYS_PLL_DISP2_dpll_wdset(data)                                (0x00000010&((data)<<4))
#define SYS_PLL_DISP2_dpll_clksel(data)                               (0x00000008&((data)<<3))
#define SYS_PLL_DISP2_dpll_freeze(data)                               (0x00000004&((data)<<2))
#define SYS_PLL_DISP2_dpll_vcorstb(data)                              (0x00000002&((data)<<1))
#define SYS_PLL_DISP2_dpll_pwdn(data)                                 (0x00000001&(data))
#define SYS_PLL_DISP2_get_dpll_reser(data)                            ((0x0F000000&(data))>>24)
#define SYS_PLL_DISP2_get_dpll_reg(data)                              ((0x00C00000&(data))>>22)
#define SYS_PLL_DISP2_get_dpll_fupdn(data)                            ((0x00200000&(data))>>21)
#define SYS_PLL_DISP2_get_dpll_stop(data)                             ((0x00100000&(data))>>20)
#define SYS_PLL_DISP2_get_dpll_reserve(data)                          ((0x00020000&(data))>>17)
#define SYS_PLL_DISP2_get_dpll_bpphs(data)                            ((0x00010000&(data))>>16)
#define SYS_PLL_DISP2_get_dpll_bpn(data)                              ((0x00004000&(data))>>14)
#define SYS_PLL_DISP2_get_dpll_o(data)                                ((0x00003000&(data))>>12)
#define SYS_PLL_DISP2_get_dpll_rstb(data)                             ((0x00000040&(data))>>6)
#define SYS_PLL_DISP2_get_dpll_wdrst(data)                            ((0x00000020&(data))>>5)
#define SYS_PLL_DISP2_get_dpll_wdset(data)                            ((0x00000010&(data))>>4)
#define SYS_PLL_DISP2_get_dpll_clksel(data)                           ((0x00000008&(data))>>3)
#define SYS_PLL_DISP2_get_dpll_freeze(data)                           ((0x00000004&(data))>>2)
#define SYS_PLL_DISP2_get_dpll_vcorstb(data)                          ((0x00000002&(data))>>1)
#define SYS_PLL_DISP2_get_dpll_pwdn(data)                             (0x00000001&(data))


#define SYS_PLL_VBY11                                                 0x18000498
#define SYS_PLL_VBY11_reg_addr                                        "0xb8000498"
#define SYS_PLL_VBY11_reg                                             0xb8000498
#define SYS_PLL_VBY11_inst_addr                                       "0x0126"
#define SYS_PLL_VBY11_inst                                            0x0126
#define SYS_PLL_VBY11_vby1_dpll_m_shift                               (20)
#define SYS_PLL_VBY11_vby1_dpll_n_shift                               (12)
#define SYS_PLL_VBY11_vby1_dpll_ip_shift                              (8)
#define SYS_PLL_VBY11_vby1_dpll_rs_shift                              (4)
#define SYS_PLL_VBY11_vby1_dpll_cp_shift                              (2)
#define SYS_PLL_VBY11_vby1_dpll_cs_shift                              (0)
#define SYS_PLL_VBY11_vby1_dpll_m_mask                                (0x0FF00000)
#define SYS_PLL_VBY11_vby1_dpll_n_mask                                (0x00007000)
#define SYS_PLL_VBY11_vby1_dpll_ip_mask                               (0x00000700)
#define SYS_PLL_VBY11_vby1_dpll_rs_mask                               (0x00000070)
#define SYS_PLL_VBY11_vby1_dpll_cp_mask                               (0x0000000C)
#define SYS_PLL_VBY11_vby1_dpll_cs_mask                               (0x00000003)
#define SYS_PLL_VBY11_vby1_dpll_m(data)                               (0x0FF00000&((data)<<20))
#define SYS_PLL_VBY11_vby1_dpll_n(data)                               (0x00007000&((data)<<12))
#define SYS_PLL_VBY11_vby1_dpll_ip(data)                              (0x00000700&((data)<<8))
#define SYS_PLL_VBY11_vby1_dpll_rs(data)                              (0x00000070&((data)<<4))
#define SYS_PLL_VBY11_vby1_dpll_cp(data)                              (0x0000000C&((data)<<2))
#define SYS_PLL_VBY11_vby1_dpll_cs(data)                              (0x00000003&(data))
#define SYS_PLL_VBY11_get_vby1_dpll_m(data)                           ((0x0FF00000&(data))>>20)
#define SYS_PLL_VBY11_get_vby1_dpll_n(data)                           ((0x00007000&(data))>>12)
#define SYS_PLL_VBY11_get_vby1_dpll_ip(data)                          ((0x00000700&(data))>>8)
#define SYS_PLL_VBY11_get_vby1_dpll_rs(data)                          ((0x00000070&(data))>>4)
#define SYS_PLL_VBY11_get_vby1_dpll_cp(data)                          ((0x0000000C&(data))>>2)
#define SYS_PLL_VBY11_get_vby1_dpll_cs(data)                          (0x00000003&(data))


#define SYS_PLL_VBY12                                                 0x1800049c
#define SYS_PLL_VBY12_reg_addr                                        "0xb800049c"
#define SYS_PLL_VBY12_reg                                             0xb800049c
#define SYS_PLL_VBY12_inst_addr                                       "0x0127"
#define SYS_PLL_VBY12_inst                                            0x0127
#define SYS_PLL_VBY12_vby1_dpll_reser_shift                           (24)
#define SYS_PLL_VBY12_vby1_dpll_reg_shift                             (22)
#define SYS_PLL_VBY12_vby1_dpll_fupdn_shift                           (21)
#define SYS_PLL_VBY12_vby1_dpll_stop_shift                            (20)
#define SYS_PLL_VBY12_vby1_dpll_reserve_shift                         (17)
#define SYS_PLL_VBY12_vby1_dpll_bpphs_shift                           (16)
#define SYS_PLL_VBY12_vby1_dpll_bpn_shift                             (14)
#define SYS_PLL_VBY12_vby1_dpll_o_shift                               (12)
#define SYS_PLL_VBY12_vby1_dpll_rstb_shift                            (6)
#define SYS_PLL_VBY12_vby1_dpll_wdrst_shift                           (5)
#define SYS_PLL_VBY12_vby1_dpll_wdset_shift                           (4)
#define SYS_PLL_VBY12_vby1_dpll_clksel_shift                          (3)
#define SYS_PLL_VBY12_vby1_dpll_freeze_shift                          (2)
#define SYS_PLL_VBY12_vby1_dpll_vcorstb_shift                         (1)
#define SYS_PLL_VBY12_vby1_dpll_pwdn_shift                            (0)
#define SYS_PLL_VBY12_vby1_dpll_reser_mask                            (0x0F000000)
#define SYS_PLL_VBY12_vby1_dpll_reg_mask                              (0x00C00000)
#define SYS_PLL_VBY12_vby1_dpll_fupdn_mask                            (0x00200000)
#define SYS_PLL_VBY12_vby1_dpll_stop_mask                             (0x00100000)
#define SYS_PLL_VBY12_vby1_dpll_reserve_mask                          (0x00020000)
#define SYS_PLL_VBY12_vby1_dpll_bpphs_mask                            (0x00010000)
#define SYS_PLL_VBY12_vby1_dpll_bpn_mask                              (0x00004000)
#define SYS_PLL_VBY12_vby1_dpll_o_mask                                (0x00003000)
#define SYS_PLL_VBY12_vby1_dpll_rstb_mask                             (0x00000040)
#define SYS_PLL_VBY12_vby1_dpll_wdrst_mask                            (0x00000020)
#define SYS_PLL_VBY12_vby1_dpll_wdset_mask                            (0x00000010)
#define SYS_PLL_VBY12_vby1_dpll_clksel_mask                           (0x00000008)
#define SYS_PLL_VBY12_vby1_dpll_freeze_mask                           (0x00000004)
#define SYS_PLL_VBY12_vby1_dpll_vcorstb_mask                          (0x00000002)
#define SYS_PLL_VBY12_vby1_dpll_pwdn_mask                             (0x00000001)
#define SYS_PLL_VBY12_vby1_dpll_reser(data)                           (0x0F000000&((data)<<24))
#define SYS_PLL_VBY12_vby1_dpll_reg(data)                             (0x00C00000&((data)<<22))
#define SYS_PLL_VBY12_vby1_dpll_fupdn(data)                           (0x00200000&((data)<<21))
#define SYS_PLL_VBY12_vby1_dpll_stop(data)                            (0x00100000&((data)<<20))
#define SYS_PLL_VBY12_vby1_dpll_reserve(data)                         (0x00020000&((data)<<17))
#define SYS_PLL_VBY12_vby1_dpll_bpphs(data)                           (0x00010000&((data)<<16))
#define SYS_PLL_VBY12_vby1_dpll_bpn(data)                             (0x00004000&((data)<<14))
#define SYS_PLL_VBY12_vby1_dpll_o(data)                               (0x00003000&((data)<<12))
#define SYS_PLL_VBY12_vby1_dpll_rstb(data)                            (0x00000040&((data)<<6))
#define SYS_PLL_VBY12_vby1_dpll_wdrst(data)                           (0x00000020&((data)<<5))
#define SYS_PLL_VBY12_vby1_dpll_wdset(data)                           (0x00000010&((data)<<4))
#define SYS_PLL_VBY12_vby1_dpll_clksel(data)                          (0x00000008&((data)<<3))
#define SYS_PLL_VBY12_vby1_dpll_freeze(data)                          (0x00000004&((data)<<2))
#define SYS_PLL_VBY12_vby1_dpll_vcorstb(data)                         (0x00000002&((data)<<1))
#define SYS_PLL_VBY12_vby1_dpll_pwdn(data)                            (0x00000001&(data))
#define SYS_PLL_VBY12_get_vby1_dpll_reser(data)                       ((0x0F000000&(data))>>24)
#define SYS_PLL_VBY12_get_vby1_dpll_reg(data)                         ((0x00C00000&(data))>>22)
#define SYS_PLL_VBY12_get_vby1_dpll_fupdn(data)                       ((0x00200000&(data))>>21)
#define SYS_PLL_VBY12_get_vby1_dpll_stop(data)                        ((0x00100000&(data))>>20)
#define SYS_PLL_VBY12_get_vby1_dpll_reserve(data)                     ((0x00020000&(data))>>17)
#define SYS_PLL_VBY12_get_vby1_dpll_bpphs(data)                       ((0x00010000&(data))>>16)
#define SYS_PLL_VBY12_get_vby1_dpll_bpn(data)                         ((0x00004000&(data))>>14)
#define SYS_PLL_VBY12_get_vby1_dpll_o(data)                           ((0x00003000&(data))>>12)
#define SYS_PLL_VBY12_get_vby1_dpll_rstb(data)                        ((0x00000040&(data))>>6)
#define SYS_PLL_VBY12_get_vby1_dpll_wdrst(data)                       ((0x00000020&(data))>>5)
#define SYS_PLL_VBY12_get_vby1_dpll_wdset(data)                       ((0x00000010&(data))>>4)
#define SYS_PLL_VBY12_get_vby1_dpll_clksel(data)                      ((0x00000008&(data))>>3)
#define SYS_PLL_VBY12_get_vby1_dpll_freeze(data)                      ((0x00000004&(data))>>2)
#define SYS_PLL_VBY12_get_vby1_dpll_vcorstb(data)                     ((0x00000002&(data))>>1)
#define SYS_PLL_VBY12_get_vby1_dpll_pwdn(data)                        (0x00000001&(data))


#define SYS_PLL_ETN1                                                  0x180004a0
#define SYS_PLL_ETN1_reg_addr                                         "0xb80004a0"
#define SYS_PLL_ETN1_reg                                              0xb80004a0
#define SYS_PLL_ETN1_inst_addr                                        "0x0128"
#define SYS_PLL_ETN1_inst                                             0x0128
#define SYS_PLL_ETN1_plletn_n_shift                                   (24)
#define SYS_PLL_ETN1_plletn_m_shift                                   (16)
#define SYS_PLL_ETN1_plletn_ip_shift                                  (12)
#define SYS_PLL_ETN1_plletn_o_shift                                   (8)
#define SYS_PLL_ETN1_plletn_wdmode_shift                              (4)
#define SYS_PLL_ETN1_plletn_lf_cp_shift                               (2)
#define SYS_PLL_ETN1_plletn_lf_rs_shift                               (0)
#define SYS_PLL_ETN1_plletn_n_mask                                    (0x03000000)
#define SYS_PLL_ETN1_plletn_m_mask                                    (0x007F0000)
#define SYS_PLL_ETN1_plletn_ip_mask                                   (0x00007000)
#define SYS_PLL_ETN1_plletn_o_mask                                    (0x00000F00)
#define SYS_PLL_ETN1_plletn_wdmode_mask                               (0x00000030)
#define SYS_PLL_ETN1_plletn_lf_cp_mask                                (0x0000000C)
#define SYS_PLL_ETN1_plletn_lf_rs_mask                                (0x00000003)
#define SYS_PLL_ETN1_plletn_n(data)                                   (0x03000000&((data)<<24))
#define SYS_PLL_ETN1_plletn_m(data)                                   (0x007F0000&((data)<<16))
#define SYS_PLL_ETN1_plletn_ip(data)                                  (0x00007000&((data)<<12))
#define SYS_PLL_ETN1_plletn_o(data)                                   (0x00000F00&((data)<<8))
#define SYS_PLL_ETN1_plletn_wdmode(data)                              (0x00000030&((data)<<4))
#define SYS_PLL_ETN1_plletn_lf_cp(data)                               (0x0000000C&((data)<<2))
#define SYS_PLL_ETN1_plletn_lf_rs(data)                               (0x00000003&(data))
#define SYS_PLL_ETN1_get_plletn_n(data)                               ((0x03000000&(data))>>24)
#define SYS_PLL_ETN1_get_plletn_m(data)                               ((0x007F0000&(data))>>16)
#define SYS_PLL_ETN1_get_plletn_ip(data)                              ((0x00007000&(data))>>12)
#define SYS_PLL_ETN1_get_plletn_o(data)                               ((0x00000F00&(data))>>8)
#define SYS_PLL_ETN1_get_plletn_wdmode(data)                          ((0x00000030&(data))>>4)
#define SYS_PLL_ETN1_get_plletn_lf_cp(data)                           ((0x0000000C&(data))>>2)
#define SYS_PLL_ETN1_get_plletn_lf_rs(data)                           (0x00000003&(data))


#define SYS_PLL_ETN2                                                  0x180004a4
#define SYS_PLL_ETN2_reg_addr                                         "0xb80004a4"
#define SYS_PLL_ETN2_reg                                              0xb80004a4
#define SYS_PLL_ETN2_inst_addr                                        "0x0129"
#define SYS_PLL_ETN2_inst                                             0x0129
#define SYS_PLL_ETN2_plletn_ldo_sel_shift                             (5)
#define SYS_PLL_ETN2_plletn_ldo_pow_shift                             (4)
#define SYS_PLL_ETN2_plletn_rstb_shift                                (1)
#define SYS_PLL_ETN2_plletn_pow_shift                                 (0)
#define SYS_PLL_ETN2_plletn_ldo_sel_mask                              (0x00000060)
#define SYS_PLL_ETN2_plletn_ldo_pow_mask                              (0x00000010)
#define SYS_PLL_ETN2_plletn_rstb_mask                                 (0x00000002)
#define SYS_PLL_ETN2_plletn_pow_mask                                  (0x00000001)
#define SYS_PLL_ETN2_plletn_ldo_sel(data)                             (0x00000060&((data)<<5))
#define SYS_PLL_ETN2_plletn_ldo_pow(data)                             (0x00000010&((data)<<4))
#define SYS_PLL_ETN2_plletn_rstb(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_ETN2_plletn_pow(data)                                 (0x00000001&(data))
#define SYS_PLL_ETN2_get_plletn_ldo_sel(data)                         ((0x00000060&(data))>>5)
#define SYS_PLL_ETN2_get_plletn_ldo_pow(data)                         ((0x00000010&(data))>>4)
#define SYS_PLL_ETN2_get_plletn_rstb(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_ETN2_get_plletn_pow(data)                             (0x00000001&(data))


#define SYS_PLL_WD_OUT                                                0x180004ac
#define SYS_PLL_WD_OUT_reg_addr                                       "0xb80004ac"
#define SYS_PLL_WD_OUT_reg                                            0xb80004ac
#define SYS_PLL_WD_OUT_inst_addr                                      "0x012B"
#define SYS_PLL_WD_OUT_inst                                           0x012B
#define SYS_PLL_WD_OUT_pllvodma_wdout_shift                           (17)
#define SYS_PLL_WD_OUT_pllgpu2_wdout_shift                            (16)
#define SYS_PLL_WD_OUT_pllvby1_wdout_shift                            (15)
#define SYS_PLL_WD_OUT_pllaud_status_shift                            (14)
#define SYS_PLL_WD_OUT_pll512fs_wdout_shift                           (13)
#define SYS_PLL_WD_OUT_pllbush_wdout_shift                            (12)
#define SYS_PLL_WD_OUT_pllgpu_wdout_shift                             (11)
#define SYS_PLL_WD_OUT_plldif_wdout_shift                             (10)
#define SYS_PLL_WD_OUT_pllbus2_wdout_shift                            (9)
#define SYS_PLL_WD_OUT_plletn_wdout_shift                             (8)
#define SYS_PLL_WD_OUT_pllbus_wdout_shift                             (6)
#define SYS_PLL_WD_OUT_plldisp_wdout_shift                            (5)
#define SYS_PLL_WD_OUT_plldds_wdout_shift                             (3)
#define SYS_PLL_WD_OUT_pllvcpu_wdout_shift                            (2)
#define SYS_PLL_WD_OUT_pllacpu_wdout_shift                            (1)
#define SYS_PLL_WD_OUT_pllscpu_wdout_shift                            (0)
#define SYS_PLL_WD_OUT_pllvodma_wdout_mask                            (0x00020000)
#define SYS_PLL_WD_OUT_pllgpu2_wdout_mask                             (0x00010000)
#define SYS_PLL_WD_OUT_pllvby1_wdout_mask                             (0x00008000)
#define SYS_PLL_WD_OUT_pllaud_status_mask                             (0x00004000)
#define SYS_PLL_WD_OUT_pll512fs_wdout_mask                            (0x00002000)
#define SYS_PLL_WD_OUT_pllbush_wdout_mask                             (0x00001000)
#define SYS_PLL_WD_OUT_pllgpu_wdout_mask                              (0x00000800)
#define SYS_PLL_WD_OUT_plldif_wdout_mask                              (0x00000400)
#define SYS_PLL_WD_OUT_pllbus2_wdout_mask                             (0x00000200)
#define SYS_PLL_WD_OUT_plletn_wdout_mask                              (0x00000100)
#define SYS_PLL_WD_OUT_pllbus_wdout_mask                              (0x00000040)
#define SYS_PLL_WD_OUT_plldisp_wdout_mask                             (0x00000020)
#define SYS_PLL_WD_OUT_plldds_wdout_mask                              (0x00000008)
#define SYS_PLL_WD_OUT_pllvcpu_wdout_mask                             (0x00000004)
#define SYS_PLL_WD_OUT_pllacpu_wdout_mask                             (0x00000002)
#define SYS_PLL_WD_OUT_pllscpu_wdout_mask                             (0x00000001)
#define SYS_PLL_WD_OUT_pllvodma_wdout(data)                           (0x00020000&((data)<<17))
#define SYS_PLL_WD_OUT_pllgpu2_wdout(data)                            (0x00010000&((data)<<16))
#define SYS_PLL_WD_OUT_pllvby1_wdout(data)                            (0x00008000&((data)<<15))
#define SYS_PLL_WD_OUT_pllaud_status(data)                            (0x00004000&((data)<<14))
#define SYS_PLL_WD_OUT_pll512fs_wdout(data)                           (0x00002000&((data)<<13))
#define SYS_PLL_WD_OUT_pllbush_wdout(data)                            (0x00001000&((data)<<12))
#define SYS_PLL_WD_OUT_pllgpu_wdout(data)                             (0x00000800&((data)<<11))
#define SYS_PLL_WD_OUT_plldif_wdout(data)                             (0x00000400&((data)<<10))
#define SYS_PLL_WD_OUT_pllbus2_wdout(data)                            (0x00000200&((data)<<9))
#define SYS_PLL_WD_OUT_plletn_wdout(data)                             (0x00000100&((data)<<8))
#define SYS_PLL_WD_OUT_pllbus_wdout(data)                             (0x00000040&((data)<<6))
#define SYS_PLL_WD_OUT_plldisp_wdout(data)                            (0x00000020&((data)<<5))
#define SYS_PLL_WD_OUT_plldds_wdout(data)                             (0x00000008&((data)<<3))
#define SYS_PLL_WD_OUT_pllvcpu_wdout(data)                            (0x00000004&((data)<<2))
#define SYS_PLL_WD_OUT_pllacpu_wdout(data)                            (0x00000002&((data)<<1))
#define SYS_PLL_WD_OUT_pllscpu_wdout(data)                            (0x00000001&(data))
#define SYS_PLL_WD_OUT_get_pllvodma_wdout(data)                       ((0x00020000&(data))>>17)
#define SYS_PLL_WD_OUT_get_pllgpu2_wdout(data)                        ((0x00010000&(data))>>16)
#define SYS_PLL_WD_OUT_get_pllvby1_wdout(data)                        ((0x00008000&(data))>>15)
#define SYS_PLL_WD_OUT_get_pllaud_status(data)                        ((0x00004000&(data))>>14)
#define SYS_PLL_WD_OUT_get_pll512fs_wdout(data)                       ((0x00002000&(data))>>13)
#define SYS_PLL_WD_OUT_get_pllbush_wdout(data)                        ((0x00001000&(data))>>12)
#define SYS_PLL_WD_OUT_get_pllgpu_wdout(data)                         ((0x00000800&(data))>>11)
#define SYS_PLL_WD_OUT_get_plldif_wdout(data)                         ((0x00000400&(data))>>10)
#define SYS_PLL_WD_OUT_get_pllbus2_wdout(data)                        ((0x00000200&(data))>>9)
#define SYS_PLL_WD_OUT_get_plletn_wdout(data)                         ((0x00000100&(data))>>8)
#define SYS_PLL_WD_OUT_get_pllbus_wdout(data)                         ((0x00000040&(data))>>6)
#define SYS_PLL_WD_OUT_get_plldisp_wdout(data)                        ((0x00000020&(data))>>5)
#define SYS_PLL_WD_OUT_get_plldds_wdout(data)                         ((0x00000008&(data))>>3)
#define SYS_PLL_WD_OUT_get_pllvcpu_wdout(data)                        ((0x00000004&(data))>>2)
#define SYS_PLL_WD_OUT_get_pllacpu_wdout(data)                        ((0x00000002&(data))>>1)
#define SYS_PLL_WD_OUT_get_pllscpu_wdout(data)                        (0x00000001&(data))


#define SYS_PLL_512FS1                                                0x180004b0
#define SYS_PLL_512FS1_reg_addr                                       "0xb80004b0"
#define SYS_PLL_512FS1_reg                                            0xb80004b0
#define SYS_PLL_512FS1_inst_addr                                      "0x012C"
#define SYS_PLL_512FS1_inst                                           0x012C
#define SYS_PLL_512FS1_pll512fs_n_shift                               (28)
#define SYS_PLL_512FS1_pll512fs_m_shift                               (20)
#define SYS_PLL_512FS1_pll512fs_bpn_shift                             (19)
#define SYS_PLL_512FS1_pll512fs_bps_shift                             (18)
#define SYS_PLL_512FS1_pll512fs_cs_shift                              (16)
#define SYS_PLL_512FS1_pll512fs_ip_shift                              (12)
#define SYS_PLL_512FS1_pll512fs_s_shift                               (9)
#define SYS_PLL_512FS1_pll512fs_q_shift                               (6)
#define SYS_PLL_512FS1_pll512fs_rs_shift                              (3)
#define SYS_PLL_512FS1_pll512fs_tst_shift                             (2)
#define SYS_PLL_512FS1_pll512fs_wdrst_shift                           (1)
#define SYS_PLL_512FS1_pll512fs_wdset_shift                           (0)
#define SYS_PLL_512FS1_pll512fs_n_mask                                (0x70000000)
#define SYS_PLL_512FS1_pll512fs_m_mask                                (0x07F00000)
#define SYS_PLL_512FS1_pll512fs_bpn_mask                              (0x00080000)
#define SYS_PLL_512FS1_pll512fs_bps_mask                              (0x00040000)
#define SYS_PLL_512FS1_pll512fs_cs_mask                               (0x00030000)
#define SYS_PLL_512FS1_pll512fs_ip_mask                               (0x00007000)
#define SYS_PLL_512FS1_pll512fs_s_mask                                (0x00000E00)
#define SYS_PLL_512FS1_pll512fs_q_mask                                (0x000001C0)
#define SYS_PLL_512FS1_pll512fs_rs_mask                               (0x00000038)
#define SYS_PLL_512FS1_pll512fs_tst_mask                              (0x00000004)
#define SYS_PLL_512FS1_pll512fs_wdrst_mask                            (0x00000002)
#define SYS_PLL_512FS1_pll512fs_wdset_mask                            (0x00000001)
#define SYS_PLL_512FS1_pll512fs_n(data)                               (0x70000000&((data)<<28))
#define SYS_PLL_512FS1_pll512fs_m(data)                               (0x07F00000&((data)<<20))
#define SYS_PLL_512FS1_pll512fs_bpn(data)                             (0x00080000&((data)<<19))
#define SYS_PLL_512FS1_pll512fs_bps(data)                             (0x00040000&((data)<<18))
#define SYS_PLL_512FS1_pll512fs_cs(data)                              (0x00030000&((data)<<16))
#define SYS_PLL_512FS1_pll512fs_ip(data)                              (0x00007000&((data)<<12))
#define SYS_PLL_512FS1_pll512fs_s(data)                               (0x00000E00&((data)<<9))
#define SYS_PLL_512FS1_pll512fs_q(data)                               (0x000001C0&((data)<<6))
#define SYS_PLL_512FS1_pll512fs_rs(data)                              (0x00000038&((data)<<3))
#define SYS_PLL_512FS1_pll512fs_tst(data)                             (0x00000004&((data)<<2))
#define SYS_PLL_512FS1_pll512fs_wdrst(data)                           (0x00000002&((data)<<1))
#define SYS_PLL_512FS1_pll512fs_wdset(data)                           (0x00000001&(data))
#define SYS_PLL_512FS1_get_pll512fs_n(data)                           ((0x70000000&(data))>>28)
#define SYS_PLL_512FS1_get_pll512fs_m(data)                           ((0x07F00000&(data))>>20)
#define SYS_PLL_512FS1_get_pll512fs_bpn(data)                         ((0x00080000&(data))>>19)
#define SYS_PLL_512FS1_get_pll512fs_bps(data)                         ((0x00040000&(data))>>18)
#define SYS_PLL_512FS1_get_pll512fs_cs(data)                          ((0x00030000&(data))>>16)
#define SYS_PLL_512FS1_get_pll512fs_ip(data)                          ((0x00007000&(data))>>12)
#define SYS_PLL_512FS1_get_pll512fs_s(data)                           ((0x00000E00&(data))>>9)
#define SYS_PLL_512FS1_get_pll512fs_q(data)                           ((0x000001C0&(data))>>6)
#define SYS_PLL_512FS1_get_pll512fs_rs(data)                          ((0x00000038&(data))>>3)
#define SYS_PLL_512FS1_get_pll512fs_tst(data)                         ((0x00000004&(data))>>2)
#define SYS_PLL_512FS1_get_pll512fs_wdrst(data)                       ((0x00000002&(data))>>1)
#define SYS_PLL_512FS1_get_pll512fs_wdset(data)                       (0x00000001&(data))


#define SYS_PLL_512FS2                                                0x180004b4
#define SYS_PLL_512FS2_reg_addr                                       "0xb80004b4"
#define SYS_PLL_512FS2_reg                                            0xb80004b4
#define SYS_PLL_512FS2_inst_addr                                      "0x012D"
#define SYS_PLL_512FS2_inst                                           0x012D
#define SYS_PLL_512FS2_pll512fs_oeb_shift                             (2)
#define SYS_PLL_512FS2_pll512fs_rstb_shift                            (1)
#define SYS_PLL_512FS2_pll512fs_pow_shift                             (0)
#define SYS_PLL_512FS2_pll512fs_oeb_mask                              (0x00000004)
#define SYS_PLL_512FS2_pll512fs_rstb_mask                             (0x00000002)
#define SYS_PLL_512FS2_pll512fs_pow_mask                              (0x00000001)
#define SYS_PLL_512FS2_pll512fs_oeb(data)                             (0x00000004&((data)<<2))
#define SYS_PLL_512FS2_pll512fs_rstb(data)                            (0x00000002&((data)<<1))
#define SYS_PLL_512FS2_pll512fs_pow(data)                             (0x00000001&(data))
#define SYS_PLL_512FS2_get_pll512fs_oeb(data)                         ((0x00000004&(data))>>2)
#define SYS_PLL_512FS2_get_pll512fs_rstb(data)                        ((0x00000002&(data))>>1)
#define SYS_PLL_512FS2_get_pll512fs_pow(data)                         (0x00000001&(data))


#define SYS_PLL_DIF1                                                  0x180004c0
#define SYS_PLL_DIF1_reg_addr                                         "0xb80004c0"
#define SYS_PLL_DIF1_reg                                              0xb80004c0
#define SYS_PLL_DIF1_inst_addr                                        "0x0130"
#define SYS_PLL_DIF1_inst                                             0x0130
#define SYS_PLL_DIF1_plldif_n_shift                                   (28)
#define SYS_PLL_DIF1_plldif_m_shift                                   (20)
#define SYS_PLL_DIF1_plldif_ip_shift                                  (16)
#define SYS_PLL_DIF1_plldif_lf_rs_shift                               (14)
#define SYS_PLL_DIF1_plldif_lf_cp_shift                               (12)
#define SYS_PLL_DIF1_plldif_n_mask                                    (0x30000000)
#define SYS_PLL_DIF1_plldif_m_mask                                    (0x07F00000)
#define SYS_PLL_DIF1_plldif_ip_mask                                   (0x00070000)
#define SYS_PLL_DIF1_plldif_lf_rs_mask                                (0x0000C000)
#define SYS_PLL_DIF1_plldif_lf_cp_mask                                (0x00003000)
#define SYS_PLL_DIF1_plldif_n(data)                                   (0x30000000&((data)<<28))
#define SYS_PLL_DIF1_plldif_m(data)                                   (0x07F00000&((data)<<20))
#define SYS_PLL_DIF1_plldif_ip(data)                                  (0x00070000&((data)<<16))
#define SYS_PLL_DIF1_plldif_lf_rs(data)                               (0x0000C000&((data)<<14))
#define SYS_PLL_DIF1_plldif_lf_cp(data)                               (0x00003000&((data)<<12))
#define SYS_PLL_DIF1_get_plldif_n(data)                               ((0x30000000&(data))>>28)
#define SYS_PLL_DIF1_get_plldif_m(data)                               ((0x07F00000&(data))>>20)
#define SYS_PLL_DIF1_get_plldif_ip(data)                              ((0x00070000&(data))>>16)
#define SYS_PLL_DIF1_get_plldif_lf_rs(data)                           ((0x0000C000&(data))>>14)
#define SYS_PLL_DIF1_get_plldif_lf_cp(data)                           ((0x00003000&(data))>>12)


#define SYS_PLL_DIF2                                                  0x180004c4
#define SYS_PLL_DIF2_reg_addr                                         "0xb80004c4"
#define SYS_PLL_DIF2_reg                                              0xb80004c4
#define SYS_PLL_DIF2_inst_addr                                        "0x0131"
#define SYS_PLL_DIF2_inst                                             0x0131
#define SYS_PLL_DIF2_plldif_wdmode_shift                              (8)
#define SYS_PLL_DIF2_plldif_divdig_sel_shift                          (4)
#define SYS_PLL_DIF2_plldif_divadc_sel_shift                          (0)
#define SYS_PLL_DIF2_plldif_wdmode_mask                               (0x00000300)
#define SYS_PLL_DIF2_plldif_divdig_sel_mask                           (0x00000030)
#define SYS_PLL_DIF2_plldif_divadc_sel_mask                           (0x00000003)
#define SYS_PLL_DIF2_plldif_wdmode(data)                              (0x00000300&((data)<<8))
#define SYS_PLL_DIF2_plldif_divdig_sel(data)                          (0x00000030&((data)<<4))
#define SYS_PLL_DIF2_plldif_divadc_sel(data)                          (0x00000003&(data))
#define SYS_PLL_DIF2_get_plldif_wdmode(data)                          ((0x00000300&(data))>>8)
#define SYS_PLL_DIF2_get_plldif_divdig_sel(data)                      ((0x00000030&(data))>>4)
#define SYS_PLL_DIF2_get_plldif_divadc_sel(data)                      (0x00000003&(data))


#define SYS_PLL_DIF3                                                  0x180004c8
#define SYS_PLL_DIF3_reg_addr                                         "0xb80004c8"
#define SYS_PLL_DIF3_reg                                              0xb80004c8
#define SYS_PLL_DIF3_inst_addr                                        "0x0132"
#define SYS_PLL_DIF3_inst                                             0x0132
#define SYS_PLL_DIF3_plldif_pd_d2s_shift                              (3)
#define SYS_PLL_DIF3_plldif_vco_rstb_shift                            (2)
#define SYS_PLL_DIF3_plldif_rstb_shift                                (1)
#define SYS_PLL_DIF3_plldif_pow_shift                                 (0)
#define SYS_PLL_DIF3_plldif_pd_d2s_mask                               (0x00000008)
#define SYS_PLL_DIF3_plldif_vco_rstb_mask                             (0x00000004)
#define SYS_PLL_DIF3_plldif_rstb_mask                                 (0x00000002)
#define SYS_PLL_DIF3_plldif_pow_mask                                  (0x00000001)
#define SYS_PLL_DIF3_plldif_pd_d2s(data)                              (0x00000008&((data)<<3))
#define SYS_PLL_DIF3_plldif_vco_rstb(data)                            (0x00000004&((data)<<2))
#define SYS_PLL_DIF3_plldif_rstb(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_DIF3_plldif_pow(data)                                 (0x00000001&(data))
#define SYS_PLL_DIF3_get_plldif_pd_d2s(data)                          ((0x00000008&(data))>>3)
#define SYS_PLL_DIF3_get_plldif_vco_rstb(data)                        ((0x00000004&(data))>>2)
#define SYS_PLL_DIF3_get_plldif_rstb(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_DIF3_get_plldif_pow(data)                             (0x00000001&(data))


#define SYS_PLL_27X1                                                  0x180004d0
#define SYS_PLL_27X1_reg_addr                                         "0xb80004d0"
#define SYS_PLL_27X1_reg                                              0xb80004d0
#define SYS_PLL_27X1_inst_addr                                        "0x0134"
#define SYS_PLL_27X1_inst                                             0x0134
#define SYS_PLL_27X1_pll27x_wdmode_shift                              (28)
#define SYS_PLL_27X1_pll27x_lf_cp_shift                               (24)
#define SYS_PLL_27X1_pll27x_lf_rs_shift                               (20)
#define SYS_PLL_27X1_pll27x_ip_shift                                  (16)
#define SYS_PLL_27X1_pll27x_m_sel_shift                               (12)
#define SYS_PLL_27X1_pll27x_n_shift                                   (8)
#define SYS_PLL_27X1_pll27x_m_shift                                   (0)
#define SYS_PLL_27X1_pll27x_wdmode_mask                               (0x30000000)
#define SYS_PLL_27X1_pll27x_lf_cp_mask                                (0x03000000)
#define SYS_PLL_27X1_pll27x_lf_rs_mask                                (0x00300000)
#define SYS_PLL_27X1_pll27x_ip_mask                                   (0x00070000)
#define SYS_PLL_27X1_pll27x_m_sel_mask                                (0x00001000)
#define SYS_PLL_27X1_pll27x_n_mask                                    (0x00000300)
#define SYS_PLL_27X1_pll27x_m_mask                                    (0x0000007F)
#define SYS_PLL_27X1_pll27x_wdmode(data)                              (0x30000000&((data)<<28))
#define SYS_PLL_27X1_pll27x_lf_cp(data)                               (0x03000000&((data)<<24))
#define SYS_PLL_27X1_pll27x_lf_rs(data)                               (0x00300000&((data)<<20))
#define SYS_PLL_27X1_pll27x_ip(data)                                  (0x00070000&((data)<<16))
#define SYS_PLL_27X1_pll27x_m_sel(data)                               (0x00001000&((data)<<12))
#define SYS_PLL_27X1_pll27x_n(data)                                   (0x00000300&((data)<<8))
#define SYS_PLL_27X1_pll27x_m(data)                                   (0x0000007F&(data))
#define SYS_PLL_27X1_get_pll27x_wdmode(data)                          ((0x30000000&(data))>>28)
#define SYS_PLL_27X1_get_pll27x_lf_cp(data)                           ((0x03000000&(data))>>24)
#define SYS_PLL_27X1_get_pll27x_lf_rs(data)                           ((0x00300000&(data))>>20)
#define SYS_PLL_27X1_get_pll27x_ip(data)                              ((0x00070000&(data))>>16)
#define SYS_PLL_27X1_get_pll27x_m_sel(data)                           ((0x00001000&(data))>>12)
#define SYS_PLL_27X1_get_pll27x_n(data)                               ((0x00000300&(data))>>8)
#define SYS_PLL_27X1_get_pll27x_m(data)                               (0x0000007F&(data))


#define SYS_PLL_27X2                                                  0x180004d4
#define SYS_PLL_27X2_reg_addr                                         "0xb80004d4"
#define SYS_PLL_27X2_reg                                              0xb80004d4
#define SYS_PLL_27X2_inst_addr                                        "0x0135"
#define SYS_PLL_27X2_inst                                             0x0135
#define SYS_PLL_27X2_xixo_load_shift                                  (18)
#define SYS_PLL_27X2_xixo_drive_sel_shift                             (16)
#define SYS_PLL_27X2_pll27x_pow_ldo11v_shift                          (14)
#define SYS_PLL_27X2_pll27x_ldo11v_sel_shift                          (12)
#define SYS_PLL_27X2_pll27x_pow_ldo_shift                             (10)
#define SYS_PLL_27X2_pll27x_ldo_sel_shift                             (8)
#define SYS_PLL_27X2_pll27x_ps_54m_delay_shift                        (4)
#define SYS_PLL_27X2_pll27x_ps_psel_pulse_w_shift                     (1)
#define SYS_PLL_27X2_pll27x_ps_duty_sel_shift                         (0)
#define SYS_PLL_27X2_xixo_load_mask                                   (0x00040000)
#define SYS_PLL_27X2_xixo_drive_sel_mask                              (0x00030000)
#define SYS_PLL_27X2_pll27x_pow_ldo11v_mask                           (0x00004000)
#define SYS_PLL_27X2_pll27x_ldo11v_sel_mask                           (0x00003000)
#define SYS_PLL_27X2_pll27x_pow_ldo_mask                              (0x00000400)
#define SYS_PLL_27X2_pll27x_ldo_sel_mask                              (0x00000300)
#define SYS_PLL_27X2_pll27x_ps_54m_delay_mask                         (0x00000030)
#define SYS_PLL_27X2_pll27x_ps_psel_pulse_w_mask                      (0x00000002)
#define SYS_PLL_27X2_pll27x_ps_duty_sel_mask                          (0x00000001)
#define SYS_PLL_27X2_xixo_load(data)                                  (0x00040000&((data)<<18))
#define SYS_PLL_27X2_xixo_drive_sel(data)                             (0x00030000&((data)<<16))
#define SYS_PLL_27X2_pll27x_pow_ldo11v(data)                          (0x00004000&((data)<<14))
#define SYS_PLL_27X2_pll27x_ldo11v_sel(data)                          (0x00003000&((data)<<12))
#define SYS_PLL_27X2_pll27x_pow_ldo(data)                             (0x00000400&((data)<<10))
#define SYS_PLL_27X2_pll27x_ldo_sel(data)                             (0x00000300&((data)<<8))
#define SYS_PLL_27X2_pll27x_ps_54m_delay(data)                        (0x00000030&((data)<<4))
#define SYS_PLL_27X2_pll27x_ps_psel_pulse_w(data)                     (0x00000002&((data)<<1))
#define SYS_PLL_27X2_pll27x_ps_duty_sel(data)                         (0x00000001&(data))
#define SYS_PLL_27X2_get_xixo_load(data)                              ((0x00040000&(data))>>18)
#define SYS_PLL_27X2_get_xixo_drive_sel(data)                         ((0x00030000&(data))>>16)
#define SYS_PLL_27X2_get_pll27x_pow_ldo11v(data)                      ((0x00004000&(data))>>14)
#define SYS_PLL_27X2_get_pll27x_ldo11v_sel(data)                      ((0x00003000&(data))>>12)
#define SYS_PLL_27X2_get_pll27x_pow_ldo(data)                         ((0x00000400&(data))>>10)
#define SYS_PLL_27X2_get_pll27x_ldo_sel(data)                         ((0x00000300&(data))>>8)
#define SYS_PLL_27X2_get_pll27x_ps_54m_delay(data)                    ((0x00000030&(data))>>4)
#define SYS_PLL_27X2_get_pll27x_ps_psel_pulse_w(data)                 ((0x00000002&(data))>>1)
#define SYS_PLL_27X2_get_pll27x_ps_duty_sel(data)                     (0x00000001&(data))


#define SYS_PLL_27X3                                                  0x180004d8
#define SYS_PLL_27X3_reg_addr                                         "0xb80004d8"
#define SYS_PLL_27X3_reg                                              0xb80004d8
#define SYS_PLL_27X3_inst_addr                                        "0x0136"
#define SYS_PLL_27X3_inst                                             0x0136
#define SYS_PLL_27X3_pll27x_reserve_shift                             (8)
#define SYS_PLL_27X3_pll27x_ps_en_shift                               (4)
#define SYS_PLL_27X3_pll27x_vcorstb_shift                             (2)
#define SYS_PLL_27X3_pll27x_rstb_shift                                (1)
#define SYS_PLL_27X3_pll27x_pow_shift                                 (0)
#define SYS_PLL_27X3_pll27x_reserve_mask                              (0x0003FF00)
#define SYS_PLL_27X3_pll27x_ps_en_mask                                (0x00000010)
#define SYS_PLL_27X3_pll27x_vcorstb_mask                              (0x00000004)
#define SYS_PLL_27X3_pll27x_rstb_mask                                 (0x00000002)
#define SYS_PLL_27X3_pll27x_pow_mask                                  (0x00000001)
#define SYS_PLL_27X3_pll27x_reserve(data)                             (0x0003FF00&((data)<<8))
#define SYS_PLL_27X3_pll27x_ps_en(data)                               (0x00000010&((data)<<4))
#define SYS_PLL_27X3_pll27x_vcorstb(data)                             (0x00000004&((data)<<2))
#define SYS_PLL_27X3_pll27x_rstb(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_27X3_pll27x_pow(data)                                 (0x00000001&(data))
#define SYS_PLL_27X3_get_pll27x_reserve(data)                         ((0x0003FF00&(data))>>8)
#define SYS_PLL_27X3_get_pll27x_ps_en(data)                           ((0x00000010&(data))>>4)
#define SYS_PLL_27X3_get_pll27x_vcorstb(data)                         ((0x00000004&(data))>>2)
#define SYS_PLL_27X3_get_pll27x_rstb(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_27X3_get_pll27x_pow(data)                             (0x00000001&(data))


#define SYS_PLL_27X4                                                  0x180004dc
#define SYS_PLL_27X4_reg_addr                                         "0xb80004dc"
#define SYS_PLL_27X4_reg                                              0xb80004dc
#define SYS_PLL_27X4_inst_addr                                        "0x0137"
#define SYS_PLL_27X4_inst                                             0x0137
#define SYS_PLL_27X4_pll27x_d16_en_shift                              (24)
#define SYS_PLL_27X4_pll27x_pll_tst_shift                             (21)
#define SYS_PLL_27X4_pll27x_en_tst_shift                              (20)
#define SYS_PLL_27X4_pll27x_ck108m_div_shift                          (16)
#define SYS_PLL_27X4_pll27x_yppadc_cko_sel_shift                      (14)
#define SYS_PLL_27X4_pll27x_yppadc_cko_en_shift                       (13)
#define SYS_PLL_27X4_pll27x_yppadc_ck54m_en_shift                     (12)
#define SYS_PLL_27X4_pll27x_ifadc_cko_sel_shift                       (10)
#define SYS_PLL_27X4_pll27x_ifadc_div_shift                           (9)
#define SYS_PLL_27X4_pll27x_ifadc_cko_en_shift                        (8)
#define SYS_PLL_27X4_ckin_pllaud_mux_shift                            (4)
#define SYS_PLL_27X4_ck_ifadc_mux_shift                               (0)
#define SYS_PLL_27X4_pll27x_d16_en_mask                               (0x01000000)
#define SYS_PLL_27X4_pll27x_pll_tst_mask                              (0x00E00000)
#define SYS_PLL_27X4_pll27x_en_tst_mask                               (0x00100000)
#define SYS_PLL_27X4_pll27x_ck108m_div_mask                           (0x00030000)
#define SYS_PLL_27X4_pll27x_yppadc_cko_sel_mask                       (0x0000C000)
#define SYS_PLL_27X4_pll27x_yppadc_cko_en_mask                        (0x00002000)
#define SYS_PLL_27X4_pll27x_yppadc_ck54m_en_mask                      (0x00001000)
#define SYS_PLL_27X4_pll27x_ifadc_cko_sel_mask                        (0x00000C00)
#define SYS_PLL_27X4_pll27x_ifadc_div_mask                            (0x00000200)
#define SYS_PLL_27X4_pll27x_ifadc_cko_en_mask                         (0x00000100)
#define SYS_PLL_27X4_ckin_pllaud_mux_mask                             (0x00000010)
#define SYS_PLL_27X4_ck_ifadc_mux_mask                                (0x00000001)
#define SYS_PLL_27X4_pll27x_d16_en(data)                              (0x01000000&((data)<<24))
#define SYS_PLL_27X4_pll27x_pll_tst(data)                             (0x00E00000&((data)<<21))
#define SYS_PLL_27X4_pll27x_en_tst(data)                              (0x00100000&((data)<<20))
#define SYS_PLL_27X4_pll27x_ck108m_div(data)                          (0x00030000&((data)<<16))
#define SYS_PLL_27X4_pll27x_yppadc_cko_sel(data)                      (0x0000C000&((data)<<14))
#define SYS_PLL_27X4_pll27x_yppadc_cko_en(data)                       (0x00002000&((data)<<13))
#define SYS_PLL_27X4_pll27x_yppadc_ck54m_en(data)                     (0x00001000&((data)<<12))
#define SYS_PLL_27X4_pll27x_ifadc_cko_sel(data)                       (0x00000C00&((data)<<10))
#define SYS_PLL_27X4_pll27x_ifadc_div(data)                           (0x00000200&((data)<<9))
#define SYS_PLL_27X4_pll27x_ifadc_cko_en(data)                        (0x00000100&((data)<<8))
#define SYS_PLL_27X4_ckin_pllaud_mux(data)                            (0x00000010&((data)<<4))
#define SYS_PLL_27X4_ck_ifadc_mux(data)                               (0x00000001&(data))
#define SYS_PLL_27X4_get_pll27x_d16_en(data)                          ((0x01000000&(data))>>24)
#define SYS_PLL_27X4_get_pll27x_pll_tst(data)                         ((0x00E00000&(data))>>21)
#define SYS_PLL_27X4_get_pll27x_en_tst(data)                          ((0x00100000&(data))>>20)
#define SYS_PLL_27X4_get_pll27x_ck108m_div(data)                      ((0x00030000&(data))>>16)
#define SYS_PLL_27X4_get_pll27x_yppadc_cko_sel(data)                  ((0x0000C000&(data))>>14)
#define SYS_PLL_27X4_get_pll27x_yppadc_cko_en(data)                   ((0x00002000&(data))>>13)
#define SYS_PLL_27X4_get_pll27x_yppadc_ck54m_en(data)                 ((0x00001000&(data))>>12)
#define SYS_PLL_27X4_get_pll27x_ifadc_cko_sel(data)                   ((0x00000C00&(data))>>10)
#define SYS_PLL_27X4_get_pll27x_ifadc_div(data)                       ((0x00000200&(data))>>9)
#define SYS_PLL_27X4_get_pll27x_ifadc_cko_en(data)                    ((0x00000100&(data))>>8)
#define SYS_PLL_27X4_get_ckin_pllaud_mux(data)                        ((0x00000010&(data))>>4)
#define SYS_PLL_27X4_get_ck_ifadc_mux(data)                           (0x00000001&(data))


#define SYS_PLL_AUD1                                                  0x180004e0
#define SYS_PLL_AUD1_reg_addr                                         "0xb80004e0"
#define SYS_PLL_AUD1_reg                                              0xb80004e0
#define SYS_PLL_AUD1_inst_addr                                        "0x0138"
#define SYS_PLL_AUD1_inst                                             0x0138
#define SYS_PLL_AUD1_pllaud_ip_shift                                  (15)
#define SYS_PLL_AUD1_pllaud_rs_shift                                  (11)
#define SYS_PLL_AUD1_pllaud_cs_shift                                  (8)
#define SYS_PLL_AUD1_pllaud_wdrst_shift                               (2)
#define SYS_PLL_AUD1_pllaud_wdset_shift                               (1)
#define SYS_PLL_AUD1_pllaud_tst_shift                                 (0)
#define SYS_PLL_AUD1_pllaud_ip_mask                                   (0x00038000)
#define SYS_PLL_AUD1_pllaud_rs_mask                                   (0x00003800)
#define SYS_PLL_AUD1_pllaud_cs_mask                                   (0x00000300)
#define SYS_PLL_AUD1_pllaud_wdrst_mask                                (0x00000004)
#define SYS_PLL_AUD1_pllaud_wdset_mask                                (0x00000002)
#define SYS_PLL_AUD1_pllaud_tst_mask                                  (0x00000001)
#define SYS_PLL_AUD1_pllaud_ip(data)                                  (0x00038000&((data)<<15))
#define SYS_PLL_AUD1_pllaud_rs(data)                                  (0x00003800&((data)<<11))
#define SYS_PLL_AUD1_pllaud_cs(data)                                  (0x00000300&((data)<<8))
#define SYS_PLL_AUD1_pllaud_wdrst(data)                               (0x00000004&((data)<<2))
#define SYS_PLL_AUD1_pllaud_wdset(data)                               (0x00000002&((data)<<1))
#define SYS_PLL_AUD1_pllaud_tst(data)                                 (0x00000001&(data))
#define SYS_PLL_AUD1_get_pllaud_ip(data)                              ((0x00038000&(data))>>15)
#define SYS_PLL_AUD1_get_pllaud_rs(data)                              ((0x00003800&(data))>>11)
#define SYS_PLL_AUD1_get_pllaud_cs(data)                              ((0x00000300&(data))>>8)
#define SYS_PLL_AUD1_get_pllaud_wdrst(data)                           ((0x00000004&(data))>>2)
#define SYS_PLL_AUD1_get_pllaud_wdset(data)                           ((0x00000002&(data))>>1)
#define SYS_PLL_AUD1_get_pllaud_tst(data)                             (0x00000001&(data))


#define SYS_PLL_AUD3                                                  0x180004e4
#define SYS_PLL_AUD3_reg_addr                                         "0xb80004e4"
#define SYS_PLL_AUD3_reg                                              0xb80004e4
#define SYS_PLL_AUD3_inst_addr                                        "0x0139"
#define SYS_PLL_AUD3_inst                                             0x0139
#define SYS_PLL_AUD3_pllaud_rstb_shift                                (3)
#define SYS_PLL_AUD3_pllaud_oeb1_shift                                (2)
#define SYS_PLL_AUD3_pllaud_oeb2_shift                                (1)
#define SYS_PLL_AUD3_pllaud_pwdn_shift                                (0)
#define SYS_PLL_AUD3_pllaud_rstb_mask                                 (0x00000008)
#define SYS_PLL_AUD3_pllaud_oeb1_mask                                 (0x00000004)
#define SYS_PLL_AUD3_pllaud_oeb2_mask                                 (0x00000002)
#define SYS_PLL_AUD3_pllaud_pwdn_mask                                 (0x00000001)
#define SYS_PLL_AUD3_pllaud_rstb(data)                                (0x00000008&((data)<<3))
#define SYS_PLL_AUD3_pllaud_oeb1(data)                                (0x00000004&((data)<<2))
#define SYS_PLL_AUD3_pllaud_oeb2(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_AUD3_pllaud_pwdn(data)                                (0x00000001&(data))
#define SYS_PLL_AUD3_get_pllaud_rstb(data)                            ((0x00000008&(data))>>3)
#define SYS_PLL_AUD3_get_pllaud_oeb1(data)                            ((0x00000004&(data))>>2)
#define SYS_PLL_AUD3_get_pllaud_oeb2(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_AUD3_get_pllaud_pwdn(data)                            (0x00000001&(data))


#define SYS_PLL_AUD4                                                  0x180004e8
#define SYS_PLL_AUD4_reg_addr                                         "0xb80004e8"
#define SYS_PLL_AUD4_reg                                              0xb80004e8
#define SYS_PLL_AUD4_inst_addr                                        "0x013A"
#define SYS_PLL_AUD4_inst                                             0x013A
#define SYS_PLL_AUD4_bb_micbias_clksel_shift                          (0)
#define SYS_PLL_AUD4_bb_micbias_clksel_mask                           (0x00000003)
#define SYS_PLL_AUD4_bb_micbias_clksel(data)                          (0x00000003&(data))
#define SYS_PLL_AUD4_get_bb_micbias_clksel(data)                      (0x00000003&(data))


#define SYS_PLL_PSAUD1                                                0x180004f0
#define SYS_PLL_PSAUD1_reg_addr                                       "0xb80004f0"
#define SYS_PLL_PSAUD1_reg                                            0xb80004f0
#define SYS_PLL_PSAUD1_inst_addr                                      "0x013C"
#define SYS_PLL_PSAUD1_inst                                           0x013C
#define SYS_PLL_PSAUD1_psaud_psen_shift                               (3)
#define SYS_PLL_PSAUD1_psaud_en_shift                                 (2)
#define SYS_PLL_PSAUD1_psaud_tst_shift                                (1)
#define SYS_PLL_PSAUD1_psaud_ctrl_shift                               (0)
#define SYS_PLL_PSAUD1_psaud_psen_mask                                (0x00000008)
#define SYS_PLL_PSAUD1_psaud_en_mask                                  (0x00000004)
#define SYS_PLL_PSAUD1_psaud_tst_mask                                 (0x00000002)
#define SYS_PLL_PSAUD1_psaud_ctrl_mask                                (0x00000001)
#define SYS_PLL_PSAUD1_psaud_psen(data)                               (0x00000008&((data)<<3))
#define SYS_PLL_PSAUD1_psaud_en(data)                                 (0x00000004&((data)<<2))
#define SYS_PLL_PSAUD1_psaud_tst(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_PSAUD1_psaud_ctrl(data)                               (0x00000001&(data))
#define SYS_PLL_PSAUD1_get_psaud_psen(data)                           ((0x00000008&(data))>>3)
#define SYS_PLL_PSAUD1_get_psaud_en(data)                             ((0x00000004&(data))>>2)
#define SYS_PLL_PSAUD1_get_psaud_tst(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_PSAUD1_get_psaud_ctrl(data)                           (0x00000001&(data))


#define SYS_PLL_PSAUD2                                                0x180004f4
#define SYS_PLL_PSAUD2_reg_addr                                       "0xb80004f4"
#define SYS_PLL_PSAUD2_reg                                            0xb80004f4
#define SYS_PLL_PSAUD2_inst_addr                                      "0x013D"
#define SYS_PLL_PSAUD2_inst                                           0x013D
#define SYS_PLL_PSAUD2_psaud_div_shift                                (0)
#define SYS_PLL_PSAUD2_psaud_div_mask                                 (0x0000000F)
#define SYS_PLL_PSAUD2_psaud_div(data)                                (0x0000000F&(data))
#define SYS_PLL_PSAUD2_get_psaud_div(data)                            (0x0000000F&(data))


#define SYS_PLL_DDR1                                                  0x18000500
#define SYS_PLL_DDR1_reg_addr                                         "0xb8000500"
#define SYS_PLL_DDR1_reg                                              0xb8000500
#define SYS_PLL_DDR1_inst_addr                                        "0x0140"
#define SYS_PLL_DDR1_inst                                             0x0140
#define SYS_PLL_DDR1_reg_pll_dbug_en_shift                            (8)
#define SYS_PLL_DDR1_reg_oeb5_shift                                   (7)
#define SYS_PLL_DDR1_reg_oeb4_shift                                   (6)
#define SYS_PLL_DDR1_reg_oeb3_shift                                   (5)
#define SYS_PLL_DDR1_reg_oeb2_shift                                   (4)
#define SYS_PLL_DDR1_reg_oeb1_shift                                   (3)
#define SYS_PLL_DDR1_reg_oeb0_shift                                   (2)
#define SYS_PLL_DDR1_reg_pll_rstb_in_shift                            (1)
#define SYS_PLL_DDR1_reg_pll_en_shift                                 (0)
#define SYS_PLL_DDR1_reg_pll_dbug_en_mask                             (0x00000100)
#define SYS_PLL_DDR1_reg_oeb5_mask                                    (0x00000080)
#define SYS_PLL_DDR1_reg_oeb4_mask                                    (0x00000040)
#define SYS_PLL_DDR1_reg_oeb3_mask                                    (0x00000020)
#define SYS_PLL_DDR1_reg_oeb2_mask                                    (0x00000010)
#define SYS_PLL_DDR1_reg_oeb1_mask                                    (0x00000008)
#define SYS_PLL_DDR1_reg_oeb0_mask                                    (0x00000004)
#define SYS_PLL_DDR1_reg_pll_rstb_in_mask                             (0x00000002)
#define SYS_PLL_DDR1_reg_pll_en_mask                                  (0x00000001)
#define SYS_PLL_DDR1_reg_pll_dbug_en(data)                            (0x00000100&((data)<<8))
#define SYS_PLL_DDR1_reg_oeb5(data)                                   (0x00000080&((data)<<7))
#define SYS_PLL_DDR1_reg_oeb4(data)                                   (0x00000040&((data)<<6))
#define SYS_PLL_DDR1_reg_oeb3(data)                                   (0x00000020&((data)<<5))
#define SYS_PLL_DDR1_reg_oeb2(data)                                   (0x00000010&((data)<<4))
#define SYS_PLL_DDR1_reg_oeb1(data)                                   (0x00000008&((data)<<3))
#define SYS_PLL_DDR1_reg_oeb0(data)                                   (0x00000004&((data)<<2))
#define SYS_PLL_DDR1_reg_pll_rstb_in(data)                            (0x00000002&((data)<<1))
#define SYS_PLL_DDR1_reg_pll_en(data)                                 (0x00000001&(data))
#define SYS_PLL_DDR1_get_reg_pll_dbug_en(data)                        ((0x00000100&(data))>>8)
#define SYS_PLL_DDR1_get_reg_oeb5(data)                               ((0x00000080&(data))>>7)
#define SYS_PLL_DDR1_get_reg_oeb4(data)                               ((0x00000040&(data))>>6)
#define SYS_PLL_DDR1_get_reg_oeb3(data)                               ((0x00000020&(data))>>5)
#define SYS_PLL_DDR1_get_reg_oeb2(data)                               ((0x00000010&(data))>>4)
#define SYS_PLL_DDR1_get_reg_oeb1(data)                               ((0x00000008&(data))>>3)
#define SYS_PLL_DDR1_get_reg_oeb0(data)                               ((0x00000004&(data))>>2)
#define SYS_PLL_DDR1_get_reg_pll_rstb_in(data)                        ((0x00000002&(data))>>1)
#define SYS_PLL_DDR1_get_reg_pll_en(data)                             (0x00000001&(data))


#define SYS_PLL_DDR2                                                  0x18000504
#define SYS_PLL_DDR2_reg_addr                                         "0xb8000504"
#define SYS_PLL_DDR2_reg                                              0xb8000504
#define SYS_PLL_DDR2_inst_addr                                        "0x0141"
#define SYS_PLL_DDR2_inst                                             0x0141
#define SYS_PLL_DDR2_reg_en_post_pi_shift                             (25)
#define SYS_PLL_DDR2_reg_reserved_shift                               (21)
#define SYS_PLL_DDR2_reg_post_pi_rs_shift                             (20)
#define SYS_PLL_DDR2_reg_pll_sel_cpmode_shift                         (19)
#define SYS_PLL_DDR2_reg_pdiv_shift                                   (17)
#define SYS_PLL_DDR2_reg_cco_kvco_shift                               (16)
#define SYS_PLL_DDR2_reg_icp_shift                                    (12)
#define SYS_PLL_DDR2_reg_post_pi_bias_shift                           (10)
#define SYS_PLL_DDR2_reg_post_pi_rl_shift                             (8)
#define SYS_PLL_DDR2_reg_pll_ldo_vsel_shift                           (6)
#define SYS_PLL_DDR2_reg_lpf_sr_shift                                 (3)
#define SYS_PLL_DDR2_reg_lpf_cp_shift                                 (2)
#define SYS_PLL_DDR2_reg_loop_pi_isel_shift                           (0)
#define SYS_PLL_DDR2_reg_en_post_pi_mask                              (0xFE000000)
#define SYS_PLL_DDR2_reg_reserved_mask                                (0x01E00000)
#define SYS_PLL_DDR2_reg_post_pi_rs_mask                              (0x00100000)
#define SYS_PLL_DDR2_reg_pll_sel_cpmode_mask                          (0x00080000)
#define SYS_PLL_DDR2_reg_pdiv_mask                                    (0x00060000)
#define SYS_PLL_DDR2_reg_cco_kvco_mask                                (0x00010000)
#define SYS_PLL_DDR2_reg_icp_mask                                     (0x0000F000)
#define SYS_PLL_DDR2_reg_post_pi_bias_mask                            (0x00000C00)
#define SYS_PLL_DDR2_reg_post_pi_rl_mask                              (0x00000300)
#define SYS_PLL_DDR2_reg_pll_ldo_vsel_mask                            (0x000000C0)
#define SYS_PLL_DDR2_reg_lpf_sr_mask                                  (0x00000038)
#define SYS_PLL_DDR2_reg_lpf_cp_mask                                  (0x00000004)
#define SYS_PLL_DDR2_reg_loop_pi_isel_mask                            (0x00000003)
#define SYS_PLL_DDR2_reg_en_post_pi(data)                             (0xFE000000&((data)<<25))
#define SYS_PLL_DDR2_reg_reserved(data)                               (0x01E00000&((data)<<21))
#define SYS_PLL_DDR2_reg_post_pi_rs(data)                             (0x00100000&((data)<<20))
#define SYS_PLL_DDR2_reg_pll_sel_cpmode(data)                         (0x00080000&((data)<<19))
#define SYS_PLL_DDR2_reg_pdiv(data)                                   (0x00060000&((data)<<17))
#define SYS_PLL_DDR2_reg_cco_kvco(data)                               (0x00010000&((data)<<16))
#define SYS_PLL_DDR2_reg_icp(data)                                    (0x0000F000&((data)<<12))
#define SYS_PLL_DDR2_reg_post_pi_bias(data)                           (0x00000C00&((data)<<10))
#define SYS_PLL_DDR2_reg_post_pi_rl(data)                             (0x00000300&((data)<<8))
#define SYS_PLL_DDR2_reg_pll_ldo_vsel(data)                           (0x000000C0&((data)<<6))
#define SYS_PLL_DDR2_reg_lpf_sr(data)                                 (0x00000038&((data)<<3))
#define SYS_PLL_DDR2_reg_lpf_cp(data)                                 (0x00000004&((data)<<2))
#define SYS_PLL_DDR2_reg_loop_pi_isel(data)                           (0x00000003&(data))
#define SYS_PLL_DDR2_get_reg_en_post_pi(data)                         ((0xFE000000&(data))>>25)
#define SYS_PLL_DDR2_get_reg_reserved(data)                           ((0x01E00000&(data))>>21)
#define SYS_PLL_DDR2_get_reg_post_pi_rs(data)                         ((0x00100000&(data))>>20)
#define SYS_PLL_DDR2_get_reg_pll_sel_cpmode(data)                     ((0x00080000&(data))>>19)
#define SYS_PLL_DDR2_get_reg_pdiv(data)                               ((0x00060000&(data))>>17)
#define SYS_PLL_DDR2_get_reg_cco_kvco(data)                           ((0x00010000&(data))>>16)
#define SYS_PLL_DDR2_get_reg_icp(data)                                ((0x0000F000&(data))>>12)
#define SYS_PLL_DDR2_get_reg_post_pi_bias(data)                       ((0x00000C00&(data))>>10)
#define SYS_PLL_DDR2_get_reg_post_pi_rl(data)                         ((0x00000300&(data))>>8)
#define SYS_PLL_DDR2_get_reg_pll_ldo_vsel(data)                       ((0x000000C0&(data))>>6)
#define SYS_PLL_DDR2_get_reg_lpf_sr(data)                             ((0x00000038&(data))>>3)
#define SYS_PLL_DDR2_get_reg_lpf_cp(data)                             ((0x00000004&(data))>>2)
#define SYS_PLL_DDR2_get_reg_loop_pi_isel(data)                       (0x00000003&(data))


#define SYS_PLL_DDR3                                                  0x18000508
#define SYS_PLL_DDR3_reg_addr                                         "0xb8000508"
#define SYS_PLL_DDR3_reg                                              0xb8000508
#define SYS_PLL_DDR3_inst_addr                                        "0x0142"
#define SYS_PLL_DDR3_inst                                             0x0142
#define SYS_PLL_DDR3_reg_post_pi_sel3_shift                           (24)
#define SYS_PLL_DDR3_reg_post_pi_sel2_shift                           (16)
#define SYS_PLL_DDR3_reg_post_pi_sel1_shift                           (8)
#define SYS_PLL_DDR3_reg_post_pi_sel0_shift                           (0)
#define SYS_PLL_DDR3_reg_post_pi_sel3_mask                            (0x3F000000)
#define SYS_PLL_DDR3_reg_post_pi_sel2_mask                            (0x003F0000)
#define SYS_PLL_DDR3_reg_post_pi_sel1_mask                            (0x00003F00)
#define SYS_PLL_DDR3_reg_post_pi_sel0_mask                            (0x0000003F)
#define SYS_PLL_DDR3_reg_post_pi_sel3(data)                           (0x3F000000&((data)<<24))
#define SYS_PLL_DDR3_reg_post_pi_sel2(data)                           (0x003F0000&((data)<<16))
#define SYS_PLL_DDR3_reg_post_pi_sel1(data)                           (0x00003F00&((data)<<8))
#define SYS_PLL_DDR3_reg_post_pi_sel0(data)                           (0x0000003F&(data))
#define SYS_PLL_DDR3_get_reg_post_pi_sel3(data)                       ((0x3F000000&(data))>>24)
#define SYS_PLL_DDR3_get_reg_post_pi_sel2(data)                       ((0x003F0000&(data))>>16)
#define SYS_PLL_DDR3_get_reg_post_pi_sel1(data)                       ((0x00003F00&(data))>>8)
#define SYS_PLL_DDR3_get_reg_post_pi_sel0(data)                       (0x0000003F&(data))


#define SYS_PLL_DDR4                                                  0x1800050c
#define SYS_PLL_DDR4_reg_addr                                         "0xb800050c"
#define SYS_PLL_DDR4_reg                                              0xb800050c
#define SYS_PLL_DDR4_inst_addr                                        "0x0143"
#define SYS_PLL_DDR4_inst                                             0x0143
#define SYS_PLL_DDR4_reg_post_pi_sel6_shift                           (16)
#define SYS_PLL_DDR4_reg_post_pi_sel5_shift                           (8)
#define SYS_PLL_DDR4_reg_post_pi_sel4_shift                           (0)
#define SYS_PLL_DDR4_reg_post_pi_sel6_mask                            (0x003F0000)
#define SYS_PLL_DDR4_reg_post_pi_sel5_mask                            (0x00003F00)
#define SYS_PLL_DDR4_reg_post_pi_sel4_mask                            (0x0000003F)
#define SYS_PLL_DDR4_reg_post_pi_sel6(data)                           (0x003F0000&((data)<<16))
#define SYS_PLL_DDR4_reg_post_pi_sel5(data)                           (0x00003F00&((data)<<8))
#define SYS_PLL_DDR4_reg_post_pi_sel4(data)                           (0x0000003F&(data))
#define SYS_PLL_DDR4_get_reg_post_pi_sel6(data)                       ((0x003F0000&(data))>>16)
#define SYS_PLL_DDR4_get_reg_post_pi_sel5(data)                       ((0x00003F00&(data))>>8)
#define SYS_PLL_DDR4_get_reg_post_pi_sel4(data)                       (0x0000003F&(data))


#define SYS_PLL_DDR_SSC1                                              0x18000510
#define SYS_PLL_DDR_SSC1_reg_addr                                     "0xb8000510"
#define SYS_PLL_DDR_SSC1_reg                                          0xb8000510
#define SYS_PLL_DDR_SSC1_inst_addr                                    "0x0144"
#define SYS_PLL_DDR_SSC1_inst                                         0x0144
#define SYS_PLL_DDR_SSC1_reg_f390k_shift                              (8)
#define SYS_PLL_DDR_SSC1_reg_wd_enable_shift                          (7)
#define SYS_PLL_DDR_SSC1_reg_time2_rst_width_shift                    (5)
#define SYS_PLL_DDR_SSC1_reg_time_rdy_ckout_shift                     (3)
#define SYS_PLL_DDR_SSC1_reg_time0_ck_shift                           (0)
#define SYS_PLL_DDR_SSC1_reg_f390k_mask                               (0x00000300)
#define SYS_PLL_DDR_SSC1_reg_wd_enable_mask                           (0x00000080)
#define SYS_PLL_DDR_SSC1_reg_time2_rst_width_mask                     (0x00000060)
#define SYS_PLL_DDR_SSC1_reg_time_rdy_ckout_mask                      (0x00000018)
#define SYS_PLL_DDR_SSC1_reg_time0_ck_mask                            (0x00000007)
#define SYS_PLL_DDR_SSC1_reg_f390k(data)                              (0x00000300&((data)<<8))
#define SYS_PLL_DDR_SSC1_reg_wd_enable(data)                          (0x00000080&((data)<<7))
#define SYS_PLL_DDR_SSC1_reg_time2_rst_width(data)                    (0x00000060&((data)<<5))
#define SYS_PLL_DDR_SSC1_reg_time_rdy_ckout(data)                     (0x00000018&((data)<<3))
#define SYS_PLL_DDR_SSC1_reg_time0_ck(data)                           (0x00000007&(data))
#define SYS_PLL_DDR_SSC1_get_reg_f390k(data)                          ((0x00000300&(data))>>8)
#define SYS_PLL_DDR_SSC1_get_reg_wd_enable(data)                      ((0x00000080&(data))>>7)
#define SYS_PLL_DDR_SSC1_get_reg_time2_rst_width(data)                ((0x00000060&(data))>>5)
#define SYS_PLL_DDR_SSC1_get_reg_time_rdy_ckout(data)                 ((0x00000018&(data))>>3)
#define SYS_PLL_DDR_SSC1_get_reg_time0_ck(data)                       (0x00000007&(data))


#define SYS_PLL_DDR_SSC2                                              0x18000514
#define SYS_PLL_DDR_SSC2_reg_addr                                     "0xb8000514"
#define SYS_PLL_DDR_SSC2_reg                                          0xb8000514
#define SYS_PLL_DDR_SSC2_inst_addr                                    "0x0145"
#define SYS_PLL_DDR_SSC2_inst                                         0x0145
#define SYS_PLL_DDR_SSC2_reg_sel_mode_shift                           (28)
#define SYS_PLL_DDR_SSC2_reg_n_code_shift                             (20)
#define SYS_PLL_DDR_SSC2_reg_f_code_shift                             (4)
#define SYS_PLL_DDR_SSC2_reg_en_ssc_shift                             (2)
#define SYS_PLL_DDR_SSC2_reg_bypass_pi_shift                          (1)
#define SYS_PLL_DDR_SSC2_reg_en_center_in_shift                       (0)
#define SYS_PLL_DDR_SSC2_reg_sel_mode_mask                            (0x10000000)
#define SYS_PLL_DDR_SSC2_reg_n_code_mask                              (0x0FF00000)
#define SYS_PLL_DDR_SSC2_reg_f_code_mask                              (0x0001FFF0)
#define SYS_PLL_DDR_SSC2_reg_en_ssc_mask                              (0x00000004)
#define SYS_PLL_DDR_SSC2_reg_bypass_pi_mask                           (0x00000002)
#define SYS_PLL_DDR_SSC2_reg_en_center_in_mask                        (0x00000001)
#define SYS_PLL_DDR_SSC2_reg_sel_mode(data)                           (0x10000000&((data)<<28))
#define SYS_PLL_DDR_SSC2_reg_n_code(data)                             (0x0FF00000&((data)<<20))
#define SYS_PLL_DDR_SSC2_reg_f_code(data)                             (0x0001FFF0&((data)<<4))
#define SYS_PLL_DDR_SSC2_reg_en_ssc(data)                             (0x00000004&((data)<<2))
#define SYS_PLL_DDR_SSC2_reg_bypass_pi(data)                          (0x00000002&((data)<<1))
#define SYS_PLL_DDR_SSC2_reg_en_center_in(data)                       (0x00000001&(data))
#define SYS_PLL_DDR_SSC2_get_reg_sel_mode(data)                       ((0x10000000&(data))>>28)
#define SYS_PLL_DDR_SSC2_get_reg_n_code(data)                         ((0x0FF00000&(data))>>20)
#define SYS_PLL_DDR_SSC2_get_reg_f_code(data)                         ((0x0001FFF0&(data))>>4)
#define SYS_PLL_DDR_SSC2_get_reg_en_ssc(data)                         ((0x00000004&(data))>>2)
#define SYS_PLL_DDR_SSC2_get_reg_bypass_pi(data)                      ((0x00000002&(data))>>1)
#define SYS_PLL_DDR_SSC2_get_reg_en_center_in(data)                   (0x00000001&(data))


#define SYS_PLL_DDR_SSC3                                              0x18000518
#define SYS_PLL_DDR_SSC3_reg_addr                                     "0xb8000518"
#define SYS_PLL_DDR_SSC3_reg                                          0xb8000518
#define SYS_PLL_DDR_SSC3_inst_addr                                    "0x0146"
#define SYS_PLL_DDR_SSC3_inst                                         0x0146
#define SYS_PLL_DDR_SSC3_reg_weighting_sel_shift                      (29)
#define SYS_PLL_DDR_SSC3_reg_sel_order_shift                          (28)
#define SYS_PLL_DDR_SSC3_reg_tbase_shift                              (16)
#define SYS_PLL_DDR_SSC3_reg_step_in_shift                            (0)
#define SYS_PLL_DDR_SSC3_reg_weighting_sel_mask                       (0xE0000000)
#define SYS_PLL_DDR_SSC3_reg_sel_order_mask                           (0x10000000)
#define SYS_PLL_DDR_SSC3_reg_tbase_mask                               (0x0FFF0000)
#define SYS_PLL_DDR_SSC3_reg_step_in_mask                             (0x00001FFF)
#define SYS_PLL_DDR_SSC3_reg_weighting_sel(data)                      (0xE0000000&((data)<<29))
#define SYS_PLL_DDR_SSC3_reg_sel_order(data)                          (0x10000000&((data)<<28))
#define SYS_PLL_DDR_SSC3_reg_tbase(data)                              (0x0FFF0000&((data)<<16))
#define SYS_PLL_DDR_SSC3_reg_step_in(data)                            (0x00001FFF&(data))
#define SYS_PLL_DDR_SSC3_get_reg_weighting_sel(data)                  ((0xE0000000&(data))>>29)
#define SYS_PLL_DDR_SSC3_get_reg_sel_order(data)                      ((0x10000000&(data))>>28)
#define SYS_PLL_DDR_SSC3_get_reg_tbase(data)                          ((0x0FFF0000&(data))>>16)
#define SYS_PLL_DDR_SSC3_get_reg_step_in(data)                        (0x00001FFF&(data))


#define SYS_PLL_DDR5                                                  0x1800051c
#define SYS_PLL_DDR5_reg_addr                                         "0xb800051c"
#define SYS_PLL_DDR5_reg                                              0xb800051c
#define SYS_PLL_DDR5_inst_addr                                        "0x0147"
#define SYS_PLL_DDR5_inst                                             0x0147
#define SYS_PLL_DDR5_reg_ck3_div2_ph_shift                            (9)
#define SYS_PLL_DDR5_reg_ck2x3_sel_shift                              (8)
#define SYS_PLL_DDR5_reg_ck2_div2_ph_shift                            (5)
#define SYS_PLL_DDR5_reg_ck2x2_sel_shift                              (4)
#define SYS_PLL_DDR5_reg_ck1_div2_ph_shift                            (1)
#define SYS_PLL_DDR5_reg_ck2x1_sel_shift                              (0)
#define SYS_PLL_DDR5_reg_ck3_div2_ph_mask                             (0x00000200)
#define SYS_PLL_DDR5_reg_ck2x3_sel_mask                               (0x00000100)
#define SYS_PLL_DDR5_reg_ck2_div2_ph_mask                             (0x00000020)
#define SYS_PLL_DDR5_reg_ck2x2_sel_mask                               (0x00000010)
#define SYS_PLL_DDR5_reg_ck1_div2_ph_mask                             (0x00000002)
#define SYS_PLL_DDR5_reg_ck2x1_sel_mask                               (0x00000001)
#define SYS_PLL_DDR5_reg_ck3_div2_ph(data)                            (0x00000200&((data)<<9))
#define SYS_PLL_DDR5_reg_ck2x3_sel(data)                              (0x00000100&((data)<<8))
#define SYS_PLL_DDR5_reg_ck2_div2_ph(data)                            (0x00000020&((data)<<5))
#define SYS_PLL_DDR5_reg_ck2x2_sel(data)                              (0x00000010&((data)<<4))
#define SYS_PLL_DDR5_reg_ck1_div2_ph(data)                            (0x00000002&((data)<<1))
#define SYS_PLL_DDR5_reg_ck2x1_sel(data)                              (0x00000001&(data))
#define SYS_PLL_DDR5_get_reg_ck3_div2_ph(data)                        ((0x00000200&(data))>>9)
#define SYS_PLL_DDR5_get_reg_ck2x3_sel(data)                          ((0x00000100&(data))>>8)
#define SYS_PLL_DDR5_get_reg_ck2_div2_ph(data)                        ((0x00000020&(data))>>5)
#define SYS_PLL_DDR5_get_reg_ck2x2_sel(data)                          ((0x00000010&(data))>>4)
#define SYS_PLL_DDR5_get_reg_ck1_div2_ph(data)                        ((0x00000002&(data))>>1)
#define SYS_PLL_DDR5_get_reg_ck2x1_sel(data)                          (0x00000001&(data))


#define SYS_PLL_DDR1_2                                                0x18000520
#define SYS_PLL_DDR1_2_reg_addr                                       "0xb8000520"
#define SYS_PLL_DDR1_2_reg                                            0xb8000520
#define SYS_PLL_DDR1_2_inst_addr                                      "0x0148"
#define SYS_PLL_DDR1_2_inst                                           0x0148
#define SYS_PLL_DDR1_2_reg_pll_dbug_en_shift                          (8)
#define SYS_PLL_DDR1_2_reg_oeb5_shift                                 (7)
#define SYS_PLL_DDR1_2_reg_oeb4_shift                                 (6)
#define SYS_PLL_DDR1_2_reg_oeb3_shift                                 (5)
#define SYS_PLL_DDR1_2_reg_oeb2_shift                                 (4)
#define SYS_PLL_DDR1_2_reg_oeb1_shift                                 (3)
#define SYS_PLL_DDR1_2_reg_oeb0_shift                                 (2)
#define SYS_PLL_DDR1_2_reg_pll_rstb_in_shift                          (1)
#define SYS_PLL_DDR1_2_reg_pll_en_shift                               (0)
#define SYS_PLL_DDR1_2_reg_pll_dbug_en_mask                           (0x00000100)
#define SYS_PLL_DDR1_2_reg_oeb5_mask                                  (0x00000080)
#define SYS_PLL_DDR1_2_reg_oeb4_mask                                  (0x00000040)
#define SYS_PLL_DDR1_2_reg_oeb3_mask                                  (0x00000020)
#define SYS_PLL_DDR1_2_reg_oeb2_mask                                  (0x00000010)
#define SYS_PLL_DDR1_2_reg_oeb1_mask                                  (0x00000008)
#define SYS_PLL_DDR1_2_reg_oeb0_mask                                  (0x00000004)
#define SYS_PLL_DDR1_2_reg_pll_rstb_in_mask                           (0x00000002)
#define SYS_PLL_DDR1_2_reg_pll_en_mask                                (0x00000001)
#define SYS_PLL_DDR1_2_reg_pll_dbug_en(data)                          (0x00000100&((data)<<8))
#define SYS_PLL_DDR1_2_reg_oeb5(data)                                 (0x00000080&((data)<<7))
#define SYS_PLL_DDR1_2_reg_oeb4(data)                                 (0x00000040&((data)<<6))
#define SYS_PLL_DDR1_2_reg_oeb3(data)                                 (0x00000020&((data)<<5))
#define SYS_PLL_DDR1_2_reg_oeb2(data)                                 (0x00000010&((data)<<4))
#define SYS_PLL_DDR1_2_reg_oeb1(data)                                 (0x00000008&((data)<<3))
#define SYS_PLL_DDR1_2_reg_oeb0(data)                                 (0x00000004&((data)<<2))
#define SYS_PLL_DDR1_2_reg_pll_rstb_in(data)                          (0x00000002&((data)<<1))
#define SYS_PLL_DDR1_2_reg_pll_en(data)                               (0x00000001&(data))
#define SYS_PLL_DDR1_2_get_reg_pll_dbug_en(data)                      ((0x00000100&(data))>>8)
#define SYS_PLL_DDR1_2_get_reg_oeb5(data)                             ((0x00000080&(data))>>7)
#define SYS_PLL_DDR1_2_get_reg_oeb4(data)                             ((0x00000040&(data))>>6)
#define SYS_PLL_DDR1_2_get_reg_oeb3(data)                             ((0x00000020&(data))>>5)
#define SYS_PLL_DDR1_2_get_reg_oeb2(data)                             ((0x00000010&(data))>>4)
#define SYS_PLL_DDR1_2_get_reg_oeb1(data)                             ((0x00000008&(data))>>3)
#define SYS_PLL_DDR1_2_get_reg_oeb0(data)                             ((0x00000004&(data))>>2)
#define SYS_PLL_DDR1_2_get_reg_pll_rstb_in(data)                      ((0x00000002&(data))>>1)
#define SYS_PLL_DDR1_2_get_reg_pll_en(data)                           (0x00000001&(data))


#define SYS_PLL_DDR2_2                                                0x18000524
#define SYS_PLL_DDR2_2_reg_addr                                       "0xb8000524"
#define SYS_PLL_DDR2_2_reg                                            0xb8000524
#define SYS_PLL_DDR2_2_inst_addr                                      "0x0149"
#define SYS_PLL_DDR2_2_inst                                           0x0149
#define SYS_PLL_DDR2_2_reg_en_post_pi_shift                           (25)
#define SYS_PLL_DDR2_2_reg_reserved_shift                             (21)
#define SYS_PLL_DDR2_2_reg_post_pi_rs_shift                           (20)
#define SYS_PLL_DDR2_2_reg_pll_sel_cpmode_shift                       (19)
#define SYS_PLL_DDR2_2_reg_pdiv_shift                                 (17)
#define SYS_PLL_DDR2_2_reg_cco_kvco_shift                             (16)
#define SYS_PLL_DDR2_2_reg_icp_shift                                  (12)
#define SYS_PLL_DDR2_2_reg_post_pi_bias_shift                         (10)
#define SYS_PLL_DDR2_2_reg_post_pi_rl_shift                           (8)
#define SYS_PLL_DDR2_2_reg_pll_ldo_vsel_shift                         (6)
#define SYS_PLL_DDR2_2_reg_lpf_sr_shift                               (3)
#define SYS_PLL_DDR2_2_reg_lpf_cp_shift                               (2)
#define SYS_PLL_DDR2_2_reg_loop_pi_isel_shift                         (0)
#define SYS_PLL_DDR2_2_reg_en_post_pi_mask                            (0xFE000000)
#define SYS_PLL_DDR2_2_reg_reserved_mask                              (0x01E00000)
#define SYS_PLL_DDR2_2_reg_post_pi_rs_mask                            (0x00100000)
#define SYS_PLL_DDR2_2_reg_pll_sel_cpmode_mask                        (0x00080000)
#define SYS_PLL_DDR2_2_reg_pdiv_mask                                  (0x00060000)
#define SYS_PLL_DDR2_2_reg_cco_kvco_mask                              (0x00010000)
#define SYS_PLL_DDR2_2_reg_icp_mask                                   (0x0000F000)
#define SYS_PLL_DDR2_2_reg_post_pi_bias_mask                          (0x00000C00)
#define SYS_PLL_DDR2_2_reg_post_pi_rl_mask                            (0x00000300)
#define SYS_PLL_DDR2_2_reg_pll_ldo_vsel_mask                          (0x000000C0)
#define SYS_PLL_DDR2_2_reg_lpf_sr_mask                                (0x00000038)
#define SYS_PLL_DDR2_2_reg_lpf_cp_mask                                (0x00000004)
#define SYS_PLL_DDR2_2_reg_loop_pi_isel_mask                          (0x00000003)
#define SYS_PLL_DDR2_2_reg_en_post_pi(data)                           (0xFE000000&((data)<<25))
#define SYS_PLL_DDR2_2_reg_reserved(data)                             (0x01E00000&((data)<<21))
#define SYS_PLL_DDR2_2_reg_post_pi_rs(data)                           (0x00100000&((data)<<20))
#define SYS_PLL_DDR2_2_reg_pll_sel_cpmode(data)                       (0x00080000&((data)<<19))
#define SYS_PLL_DDR2_2_reg_pdiv(data)                                 (0x00060000&((data)<<17))
#define SYS_PLL_DDR2_2_reg_cco_kvco(data)                             (0x00010000&((data)<<16))
#define SYS_PLL_DDR2_2_reg_icp(data)                                  (0x0000F000&((data)<<12))
#define SYS_PLL_DDR2_2_reg_post_pi_bias(data)                         (0x00000C00&((data)<<10))
#define SYS_PLL_DDR2_2_reg_post_pi_rl(data)                           (0x00000300&((data)<<8))
#define SYS_PLL_DDR2_2_reg_pll_ldo_vsel(data)                         (0x000000C0&((data)<<6))
#define SYS_PLL_DDR2_2_reg_lpf_sr(data)                               (0x00000038&((data)<<3))
#define SYS_PLL_DDR2_2_reg_lpf_cp(data)                               (0x00000004&((data)<<2))
#define SYS_PLL_DDR2_2_reg_loop_pi_isel(data)                         (0x00000003&(data))
#define SYS_PLL_DDR2_2_get_reg_en_post_pi(data)                       ((0xFE000000&(data))>>25)
#define SYS_PLL_DDR2_2_get_reg_reserved(data)                         ((0x01E00000&(data))>>21)
#define SYS_PLL_DDR2_2_get_reg_post_pi_rs(data)                       ((0x00100000&(data))>>20)
#define SYS_PLL_DDR2_2_get_reg_pll_sel_cpmode(data)                   ((0x00080000&(data))>>19)
#define SYS_PLL_DDR2_2_get_reg_pdiv(data)                             ((0x00060000&(data))>>17)
#define SYS_PLL_DDR2_2_get_reg_cco_kvco(data)                         ((0x00010000&(data))>>16)
#define SYS_PLL_DDR2_2_get_reg_icp(data)                              ((0x0000F000&(data))>>12)
#define SYS_PLL_DDR2_2_get_reg_post_pi_bias(data)                     ((0x00000C00&(data))>>10)
#define SYS_PLL_DDR2_2_get_reg_post_pi_rl(data)                       ((0x00000300&(data))>>8)
#define SYS_PLL_DDR2_2_get_reg_pll_ldo_vsel(data)                     ((0x000000C0&(data))>>6)
#define SYS_PLL_DDR2_2_get_reg_lpf_sr(data)                           ((0x00000038&(data))>>3)
#define SYS_PLL_DDR2_2_get_reg_lpf_cp(data)                           ((0x00000004&(data))>>2)
#define SYS_PLL_DDR2_2_get_reg_loop_pi_isel(data)                     (0x00000003&(data))


#define SYS_PLL_DDR3_2                                                0x18000528
#define SYS_PLL_DDR3_2_reg_addr                                       "0xb8000528"
#define SYS_PLL_DDR3_2_reg                                            0xb8000528
#define SYS_PLL_DDR3_2_inst_addr                                      "0x014A"
#define SYS_PLL_DDR3_2_inst                                           0x014A
#define SYS_PLL_DDR3_2_reg_post_pi_sel3_shift                         (24)
#define SYS_PLL_DDR3_2_reg_post_pi_sel2_shift                         (16)
#define SYS_PLL_DDR3_2_reg_post_pi_sel1_shift                         (8)
#define SYS_PLL_DDR3_2_reg_post_pi_sel0_shift                         (0)
#define SYS_PLL_DDR3_2_reg_post_pi_sel3_mask                          (0x3F000000)
#define SYS_PLL_DDR3_2_reg_post_pi_sel2_mask                          (0x003F0000)
#define SYS_PLL_DDR3_2_reg_post_pi_sel1_mask                          (0x00003F00)
#define SYS_PLL_DDR3_2_reg_post_pi_sel0_mask                          (0x0000003F)
#define SYS_PLL_DDR3_2_reg_post_pi_sel3(data)                         (0x3F000000&((data)<<24))
#define SYS_PLL_DDR3_2_reg_post_pi_sel2(data)                         (0x003F0000&((data)<<16))
#define SYS_PLL_DDR3_2_reg_post_pi_sel1(data)                         (0x00003F00&((data)<<8))
#define SYS_PLL_DDR3_2_reg_post_pi_sel0(data)                         (0x0000003F&(data))
#define SYS_PLL_DDR3_2_get_reg_post_pi_sel3(data)                     ((0x3F000000&(data))>>24)
#define SYS_PLL_DDR3_2_get_reg_post_pi_sel2(data)                     ((0x003F0000&(data))>>16)
#define SYS_PLL_DDR3_2_get_reg_post_pi_sel1(data)                     ((0x00003F00&(data))>>8)
#define SYS_PLL_DDR3_2_get_reg_post_pi_sel0(data)                     (0x0000003F&(data))


#define SYS_PLL_DDR4_2                                                0x1800052c
#define SYS_PLL_DDR4_2_reg_addr                                       "0xb800052c"
#define SYS_PLL_DDR4_2_reg                                            0xb800052c
#define SYS_PLL_DDR4_2_inst_addr                                      "0x014B"
#define SYS_PLL_DDR4_2_inst                                           0x014B
#define SYS_PLL_DDR4_2_reg_post_pi_sel6_shift                         (16)
#define SYS_PLL_DDR4_2_reg_post_pi_sel5_shift                         (8)
#define SYS_PLL_DDR4_2_reg_post_pi_sel4_shift                         (0)
#define SYS_PLL_DDR4_2_reg_post_pi_sel6_mask                          (0x003F0000)
#define SYS_PLL_DDR4_2_reg_post_pi_sel5_mask                          (0x00003F00)
#define SYS_PLL_DDR4_2_reg_post_pi_sel4_mask                          (0x0000003F)
#define SYS_PLL_DDR4_2_reg_post_pi_sel6(data)                         (0x003F0000&((data)<<16))
#define SYS_PLL_DDR4_2_reg_post_pi_sel5(data)                         (0x00003F00&((data)<<8))
#define SYS_PLL_DDR4_2_reg_post_pi_sel4(data)                         (0x0000003F&(data))
#define SYS_PLL_DDR4_2_get_reg_post_pi_sel6(data)                     ((0x003F0000&(data))>>16)
#define SYS_PLL_DDR4_2_get_reg_post_pi_sel5(data)                     ((0x00003F00&(data))>>8)
#define SYS_PLL_DDR4_2_get_reg_post_pi_sel4(data)                     (0x0000003F&(data))


#define SYS_PLL_DDR_SSC1_2                                            0x18000530
#define SYS_PLL_DDR_SSC1_2_reg_addr                                   "0xb8000530"
#define SYS_PLL_DDR_SSC1_2_reg                                        0xb8000530
#define SYS_PLL_DDR_SSC1_2_inst_addr                                  "0x014C"
#define SYS_PLL_DDR_SSC1_2_inst                                       0x014C
#define SYS_PLL_DDR_SSC1_2_reg_f390k_shift                            (8)
#define SYS_PLL_DDR_SSC1_2_reg_wd_enable_shift                        (7)
#define SYS_PLL_DDR_SSC1_2_reg_time2_rst_width_shift                  (5)
#define SYS_PLL_DDR_SSC1_2_reg_time_rdy_ckout_shift                   (3)
#define SYS_PLL_DDR_SSC1_2_reg_time0_ck_shift                         (0)
#define SYS_PLL_DDR_SSC1_2_reg_f390k_mask                             (0x00000300)
#define SYS_PLL_DDR_SSC1_2_reg_wd_enable_mask                         (0x00000080)
#define SYS_PLL_DDR_SSC1_2_reg_time2_rst_width_mask                   (0x00000060)
#define SYS_PLL_DDR_SSC1_2_reg_time_rdy_ckout_mask                    (0x00000018)
#define SYS_PLL_DDR_SSC1_2_reg_time0_ck_mask                          (0x00000007)
#define SYS_PLL_DDR_SSC1_2_reg_f390k(data)                            (0x00000300&((data)<<8))
#define SYS_PLL_DDR_SSC1_2_reg_wd_enable(data)                        (0x00000080&((data)<<7))
#define SYS_PLL_DDR_SSC1_2_reg_time2_rst_width(data)                  (0x00000060&((data)<<5))
#define SYS_PLL_DDR_SSC1_2_reg_time_rdy_ckout(data)                   (0x00000018&((data)<<3))
#define SYS_PLL_DDR_SSC1_2_reg_time0_ck(data)                         (0x00000007&(data))
#define SYS_PLL_DDR_SSC1_2_get_reg_f390k(data)                        ((0x00000300&(data))>>8)
#define SYS_PLL_DDR_SSC1_2_get_reg_wd_enable(data)                    ((0x00000080&(data))>>7)
#define SYS_PLL_DDR_SSC1_2_get_reg_time2_rst_width(data)              ((0x00000060&(data))>>5)
#define SYS_PLL_DDR_SSC1_2_get_reg_time_rdy_ckout(data)               ((0x00000018&(data))>>3)
#define SYS_PLL_DDR_SSC1_2_get_reg_time0_ck(data)                     (0x00000007&(data))


#define SYS_PLL_DDR_SSC2_2                                            0x18000534
#define SYS_PLL_DDR_SSC2_2_reg_addr                                   "0xb8000534"
#define SYS_PLL_DDR_SSC2_2_reg                                        0xb8000534
#define SYS_PLL_DDR_SSC2_2_inst_addr                                  "0x014D"
#define SYS_PLL_DDR_SSC2_2_inst                                       0x014D
#define SYS_PLL_DDR_SSC2_2_reg_sel_mode_shift                         (28)
#define SYS_PLL_DDR_SSC2_2_reg_n_code_shift                           (20)
#define SYS_PLL_DDR_SSC2_2_reg_f_code_shift                           (4)
#define SYS_PLL_DDR_SSC2_2_reg_en_ssc_shift                           (2)
#define SYS_PLL_DDR_SSC2_2_reg_bypass_pi_shift                        (1)
#define SYS_PLL_DDR_SSC2_2_reg_en_center_in_shift                     (0)
#define SYS_PLL_DDR_SSC2_2_reg_sel_mode_mask                          (0x10000000)
#define SYS_PLL_DDR_SSC2_2_reg_n_code_mask                            (0x0FF00000)
#define SYS_PLL_DDR_SSC2_2_reg_f_code_mask                            (0x0001FFF0)
#define SYS_PLL_DDR_SSC2_2_reg_en_ssc_mask                            (0x00000004)
#define SYS_PLL_DDR_SSC2_2_reg_bypass_pi_mask                         (0x00000002)
#define SYS_PLL_DDR_SSC2_2_reg_en_center_in_mask                      (0x00000001)
#define SYS_PLL_DDR_SSC2_2_reg_sel_mode(data)                         (0x10000000&((data)<<28))
#define SYS_PLL_DDR_SSC2_2_reg_n_code(data)                           (0x0FF00000&((data)<<20))
#define SYS_PLL_DDR_SSC2_2_reg_f_code(data)                           (0x0001FFF0&((data)<<4))
#define SYS_PLL_DDR_SSC2_2_reg_en_ssc(data)                           (0x00000004&((data)<<2))
#define SYS_PLL_DDR_SSC2_2_reg_bypass_pi(data)                        (0x00000002&((data)<<1))
#define SYS_PLL_DDR_SSC2_2_reg_en_center_in(data)                     (0x00000001&(data))
#define SYS_PLL_DDR_SSC2_2_get_reg_sel_mode(data)                     ((0x10000000&(data))>>28)
#define SYS_PLL_DDR_SSC2_2_get_reg_n_code(data)                       ((0x0FF00000&(data))>>20)
#define SYS_PLL_DDR_SSC2_2_get_reg_f_code(data)                       ((0x0001FFF0&(data))>>4)
#define SYS_PLL_DDR_SSC2_2_get_reg_en_ssc(data)                       ((0x00000004&(data))>>2)
#define SYS_PLL_DDR_SSC2_2_get_reg_bypass_pi(data)                    ((0x00000002&(data))>>1)
#define SYS_PLL_DDR_SSC2_2_get_reg_en_center_in(data)                 (0x00000001&(data))


#define SYS_PLL_DDR_SSC3_2                                            0x18000538
#define SYS_PLL_DDR_SSC3_2_reg_addr                                   "0xb8000538"
#define SYS_PLL_DDR_SSC3_2_reg                                        0xb8000538
#define SYS_PLL_DDR_SSC3_2_inst_addr                                  "0x014E"
#define SYS_PLL_DDR_SSC3_2_inst                                       0x014E
#define SYS_PLL_DDR_SSC3_2_reg_weighting_sel_shift                    (29)
#define SYS_PLL_DDR_SSC3_2_reg_sel_order_shift                        (28)
#define SYS_PLL_DDR_SSC3_2_reg_tbase_shift                            (16)
#define SYS_PLL_DDR_SSC3_2_reg_step_in_shift                          (0)
#define SYS_PLL_DDR_SSC3_2_reg_weighting_sel_mask                     (0xE0000000)
#define SYS_PLL_DDR_SSC3_2_reg_sel_order_mask                         (0x10000000)
#define SYS_PLL_DDR_SSC3_2_reg_tbase_mask                             (0x0FFF0000)
#define SYS_PLL_DDR_SSC3_2_reg_step_in_mask                           (0x00001FFF)
#define SYS_PLL_DDR_SSC3_2_reg_weighting_sel(data)                    (0xE0000000&((data)<<29))
#define SYS_PLL_DDR_SSC3_2_reg_sel_order(data)                        (0x10000000&((data)<<28))
#define SYS_PLL_DDR_SSC3_2_reg_tbase(data)                            (0x0FFF0000&((data)<<16))
#define SYS_PLL_DDR_SSC3_2_reg_step_in(data)                          (0x00001FFF&(data))
#define SYS_PLL_DDR_SSC3_2_get_reg_weighting_sel(data)                ((0xE0000000&(data))>>29)
#define SYS_PLL_DDR_SSC3_2_get_reg_sel_order(data)                    ((0x10000000&(data))>>28)
#define SYS_PLL_DDR_SSC3_2_get_reg_tbase(data)                        ((0x0FFF0000&(data))>>16)
#define SYS_PLL_DDR_SSC3_2_get_reg_step_in(data)                      (0x00001FFF&(data))


#define SYS_PLL_DDR5_2                                                0x1800053c
#define SYS_PLL_DDR5_2_reg_addr                                       "0xb800053c"
#define SYS_PLL_DDR5_2_reg                                            0xb800053c
#define SYS_PLL_DDR5_2_inst_addr                                      "0x014F"
#define SYS_PLL_DDR5_2_inst                                           0x014F
#define SYS_PLL_DDR5_2_reg_ck3_div2_ph_shift                          (9)
#define SYS_PLL_DDR5_2_reg_ck2x3_sel_shift                            (8)
#define SYS_PLL_DDR5_2_reg_ck2_div2_ph_shift                          (5)
#define SYS_PLL_DDR5_2_reg_ck2x2_sel_shift                            (4)
#define SYS_PLL_DDR5_2_reg_ck1_div2_ph_shift                          (1)
#define SYS_PLL_DDR5_2_reg_ck2x1_sel_shift                            (0)
#define SYS_PLL_DDR5_2_reg_ck3_div2_ph_mask                           (0x00000200)
#define SYS_PLL_DDR5_2_reg_ck2x3_sel_mask                             (0x00000100)
#define SYS_PLL_DDR5_2_reg_ck2_div2_ph_mask                           (0x00000020)
#define SYS_PLL_DDR5_2_reg_ck2x2_sel_mask                             (0x00000010)
#define SYS_PLL_DDR5_2_reg_ck1_div2_ph_mask                           (0x00000002)
#define SYS_PLL_DDR5_2_reg_ck2x1_sel_mask                             (0x00000001)
#define SYS_PLL_DDR5_2_reg_ck3_div2_ph(data)                          (0x00000200&((data)<<9))
#define SYS_PLL_DDR5_2_reg_ck2x3_sel(data)                            (0x00000100&((data)<<8))
#define SYS_PLL_DDR5_2_reg_ck2_div2_ph(data)                          (0x00000020&((data)<<5))
#define SYS_PLL_DDR5_2_reg_ck2x2_sel(data)                            (0x00000010&((data)<<4))
#define SYS_PLL_DDR5_2_reg_ck1_div2_ph(data)                          (0x00000002&((data)<<1))
#define SYS_PLL_DDR5_2_reg_ck2x1_sel(data)                            (0x00000001&(data))
#define SYS_PLL_DDR5_2_get_reg_ck3_div2_ph(data)                      ((0x00000200&(data))>>9)
#define SYS_PLL_DDR5_2_get_reg_ck2x3_sel(data)                        ((0x00000100&(data))>>8)
#define SYS_PLL_DDR5_2_get_reg_ck2_div2_ph(data)                      ((0x00000020&(data))>>5)
#define SYS_PLL_DDR5_2_get_reg_ck2x2_sel(data)                        ((0x00000010&(data))>>4)
#define SYS_PLL_DDR5_2_get_reg_ck1_div2_ph(data)                      ((0x00000002&(data))>>1)
#define SYS_PLL_DDR5_2_get_reg_ck2x1_sel(data)                        (0x00000001&(data))


#define SYS_DCLKSS                                                    0x18000640
#define SYS_DCLKSS_reg_addr                                           "0xb8000640"
#define SYS_DCLKSS_reg                                                0xb8000640
#define SYS_DCLKSS_inst_addr                                          "0x0190"
#define SYS_DCLKSS_inst                                               0x0190
#define SYS_DCLKSS_dclk_field_flag_mode_en_shift                      (31)
#define SYS_DCLKSS_dclk_filed_flag_slt_shift                          (28)
#define SYS_DCLKSS_dclk_offset_11_0_shift                             (16)
#define SYS_DCLKSS_dclk_new_en_shift                                  (15)
#define SYS_DCLKSS_dclk_ss_test_shift                                 (14)
#define SYS_DCLKSS_dclk_freq_syn_slt_shift                            (8)
#define SYS_DCLKSS_dclk_ss_rag_shift                                  (4)
#define SYS_DCLKSS_dummy18000640_3_shift                              (3)
#define SYS_DCLKSS_dclk_ss_load_shift                                 (2)
#define SYS_DCLKSS_dummy18000640_1_shift                              (1)
#define SYS_DCLKSS_dclk_ss_en_shift                                   (0)
#define SYS_DCLKSS_dclk_field_flag_mode_en_mask                       (0x80000000)
#define SYS_DCLKSS_dclk_filed_flag_slt_mask                           (0x70000000)
#define SYS_DCLKSS_dclk_offset_11_0_mask                              (0x0FFF0000)
#define SYS_DCLKSS_dclk_new_en_mask                                   (0x00008000)
#define SYS_DCLKSS_dclk_ss_test_mask                                  (0x00004000)
#define SYS_DCLKSS_dclk_freq_syn_slt_mask                             (0x00003F00)
#define SYS_DCLKSS_dclk_ss_rag_mask                                   (0x000000F0)
#define SYS_DCLKSS_dummy18000640_3_mask                               (0x00000008)
#define SYS_DCLKSS_dclk_ss_load_mask                                  (0x00000004)
#define SYS_DCLKSS_dummy18000640_1_mask                               (0x00000002)
#define SYS_DCLKSS_dclk_ss_en_mask                                    (0x00000001)
#define SYS_DCLKSS_dclk_field_flag_mode_en(data)                      (0x80000000&((data)<<31))
#define SYS_DCLKSS_dclk_filed_flag_slt(data)                          (0x70000000&((data)<<28))
#define SYS_DCLKSS_dclk_offset_11_0(data)                             (0x0FFF0000&((data)<<16))
#define SYS_DCLKSS_dclk_new_en(data)                                  (0x00008000&((data)<<15))
#define SYS_DCLKSS_dclk_ss_test(data)                                 (0x00004000&((data)<<14))
#define SYS_DCLKSS_dclk_freq_syn_slt(data)                            (0x00003F00&((data)<<8))
#define SYS_DCLKSS_dclk_ss_rag(data)                                  (0x000000F0&((data)<<4))
#define SYS_DCLKSS_dummy18000640_3(data)                              (0x00000008&((data)<<3))
#define SYS_DCLKSS_dclk_ss_load(data)                                 (0x00000004&((data)<<2))
#define SYS_DCLKSS_dummy18000640_1(data)                              (0x00000002&((data)<<1))
#define SYS_DCLKSS_dclk_ss_en(data)                                   (0x00000001&(data))
#define SYS_DCLKSS_get_dclk_field_flag_mode_en(data)                  ((0x80000000&(data))>>31)
#define SYS_DCLKSS_get_dclk_filed_flag_slt(data)                      ((0x70000000&(data))>>28)
#define SYS_DCLKSS_get_dclk_offset_11_0(data)                         ((0x0FFF0000&(data))>>16)
#define SYS_DCLKSS_get_dclk_new_en(data)                              ((0x00008000&(data))>>15)
#define SYS_DCLKSS_get_dclk_ss_test(data)                             ((0x00004000&(data))>>14)
#define SYS_DCLKSS_get_dclk_freq_syn_slt(data)                        ((0x00003F00&(data))>>8)
#define SYS_DCLKSS_get_dclk_ss_rag(data)                              ((0x000000F0&(data))>>4)
#define SYS_DCLKSS_get_dummy18000640_3(data)                          ((0x00000008&(data))>>3)
#define SYS_DCLKSS_get_dclk_ss_load(data)                             ((0x00000004&(data))>>2)
#define SYS_DCLKSS_get_dummy18000640_1(data)                          ((0x00000002&(data))>>1)
#define SYS_DCLKSS_get_dclk_ss_en(data)                               (0x00000001&(data))


#define DPLL_IN_FSYNC_TRACKING_CTRL                                   0x18000644
#define DPLL_IN_FSYNC_TRACKING_CTRL_reg_addr                          "0xb8000644"
#define DPLL_IN_FSYNC_TRACKING_CTRL_reg                               0xb8000644
#define DPLL_IN_FSYNC_TRACKING_CTRL_inst_addr                         "0x0191"
#define DPLL_IN_FSYNC_TRACKING_CTRL_inst                              0x0191
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_mcode_slow_modify_valid_shift  (31)
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_mcode_slow_modify_stable_shift  (30)
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_mcode_slow_modify_pixel_shift  (18)
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_offset_slow_modify_valid_shift  (17)
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_offset_slow_modify_stable_shift  (16)
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_offset_slow_modify_pixel_shift  (4)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_offset_inverse_shift  (3)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_ypbpr_en_shift  (2)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_vd_dec_en_shift (1)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_general_en_shift  (0)
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_mcode_slow_modify_valid_mask (0x80000000)
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_mcode_slow_modify_stable_mask  (0x40000000)
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_mcode_slow_modify_pixel_mask (0x3FFC0000)
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_offset_slow_modify_valid_mask  (0x00020000)
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_offset_slow_modify_stable_mask  (0x00010000)
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_offset_slow_modify_pixel_mask  (0x0000FFF0)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_offset_inverse_mask  (0x00000008)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_ypbpr_en_mask   (0x00000004)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_vd_dec_en_mask  (0x00000002)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_general_en_mask (0x00000001)
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_mcode_slow_modify_valid(data)  (0x80000000&((data)<<31))
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_mcode_slow_modify_stable(data)  (0x40000000&((data)<<30))
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_mcode_slow_modify_pixel(data)  (0x3FFC0000&((data)<<18))
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_offset_slow_modify_valid(data)  (0x00020000&((data)<<17))
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_offset_slow_modify_stable(data)  (0x00010000&((data)<<16))
#define DPLL_IN_FSYNC_TRACKING_CTRL_sscg_offset_slow_modify_pixel(data)  (0x0000FFF0&((data)<<4))
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_offset_inverse(data)  (0x00000008&((data)<<3))
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_ypbpr_en(data)  (0x00000004&((data)<<2))
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_vd_dec_en(data) (0x00000002&((data)<<1))
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_general_en(data)  (0x00000001&(data))
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_sscg_mcode_slow_modify_valid(data)  ((0x80000000&(data))>>31)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_sscg_mcode_slow_modify_stable(data)  ((0x40000000&(data))>>30)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_sscg_mcode_slow_modify_pixel(data)  ((0x3FFC0000&(data))>>18)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_sscg_offset_slow_modify_valid(data)  ((0x00020000&(data))>>17)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_sscg_offset_slow_modify_stable(data)  ((0x00010000&(data))>>16)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_sscg_offset_slow_modify_pixel(data)  ((0x0000FFF0&(data))>>4)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_offset_inverse(data)  ((0x00000008&(data))>>3)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_ypbpr_en(data)  ((0x00000004&(data))>>2)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_vd_dec_en(data)  ((0x00000002&(data))>>1)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_general_en(data)  (0x00000001&(data))


#define DPLL_IN_FSYNC_TRACKING_CTRL2                                  0x18000648
#define DPLL_IN_FSYNC_TRACKING_CTRL2_reg_addr                         "0xb8000648"
#define DPLL_IN_FSYNC_TRACKING_CTRL2_reg                              0xb8000648
#define DPLL_IN_FSYNC_TRACKING_CTRL2_inst_addr                        "0x0192"
#define DPLL_IN_FSYNC_TRACKING_CTRL2_inst                             0x0192
#define DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_neg_th_shift   (20)
#define DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_pos_th_shift   (8)
#define DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_mul_shift      (0)
#define DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_neg_th_mask    (0xFFF00000)
#define DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_pos_th_mask    (0x000FFF00)
#define DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_mul_mask       (0x000000FF)
#define DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_neg_th(data)   (0xFFF00000&((data)<<20))
#define DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_pos_th(data)   (0x000FFF00&((data)<<8))
#define DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_mul(data)      (0x000000FF&(data))
#define DPLL_IN_FSYNC_TRACKING_CTRL2_get_in_frame_tracking_neg_th(data)  ((0xFFF00000&(data))>>20)
#define DPLL_IN_FSYNC_TRACKING_CTRL2_get_in_frame_tracking_pos_th(data)  ((0x000FFF00&(data))>>8)
#define DPLL_IN_FSYNC_TRACKING_CTRL2_get_in_frame_tracking_mul(data)  (0x000000FF&(data))


#define DPLL_IN_FSYNC_TRACKING_DEBUG                                  0x1800064c
#define DPLL_IN_FSYNC_TRACKING_DEBUG_reg_addr                         "0xb800064c"
#define DPLL_IN_FSYNC_TRACKING_DEBUG_reg                              0xb800064c
#define DPLL_IN_FSYNC_TRACKING_DEBUG_inst_addr                        "0x0193"
#define DPLL_IN_FSYNC_TRACKING_DEBUG_inst                             0x0193
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_offset_over_flag_shift      (31)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_profile_over_underflow_flag_shift  (30)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_profile_protection_shift    (29)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_offset_over_th_max_shift    (16)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_dpll_mcode_protection_shift      (15)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_dpll_mcode_protection_ready_width_shift  (13)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_offset_over_th_value_shift  (0)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_offset_over_flag_mask       (0x80000000)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_profile_over_underflow_flag_mask  (0x40000000)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_profile_protection_mask     (0x20000000)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_offset_over_th_max_mask     (0x1FFF0000)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_dpll_mcode_protection_mask       (0x00008000)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_dpll_mcode_protection_ready_width_mask  (0x00006000)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_offset_over_th_value_mask   (0x00001FFF)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_offset_over_flag(data)      (0x80000000&((data)<<31))
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_profile_over_underflow_flag(data)  (0x40000000&((data)<<30))
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_profile_protection(data)    (0x20000000&((data)<<29))
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_offset_over_th_max(data)    (0x1FFF0000&((data)<<16))
#define DPLL_IN_FSYNC_TRACKING_DEBUG_dpll_mcode_protection(data)      (0x00008000&((data)<<15))
#define DPLL_IN_FSYNC_TRACKING_DEBUG_dpll_mcode_protection_ready_width(data)  (0x00006000&((data)<<13))
#define DPLL_IN_FSYNC_TRACKING_DEBUG_sscg_offset_over_th_value(data)  (0x00001FFF&(data))
#define DPLL_IN_FSYNC_TRACKING_DEBUG_get_sscg_offset_over_flag(data)  ((0x80000000&(data))>>31)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_get_sscg_profile_over_underflow_flag(data)  ((0x40000000&(data))>>30)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_get_sscg_profile_protection(data)  ((0x20000000&(data))>>29)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_get_sscg_offset_over_th_max(data)  ((0x1FFF0000&(data))>>16)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_get_dpll_mcode_protection(data)  ((0x00008000&(data))>>15)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_get_dpll_mcode_protection_ready_width(data)  ((0x00006000&(data))>>13)
#define DPLL_IN_FSYNC_TRACKING_DEBUG_get_sscg_offset_over_th_value(data)  (0x00001FFF&(data))


#define DCLK_FRC2FSYNC_SPEEDUP                                        0x18000650
#define DCLK_FRC2FSYNC_SPEEDUP_reg_addr                               "0xb8000650"
#define DCLK_FRC2FSYNC_SPEEDUP_reg                                    0xb8000650
#define DCLK_FRC2FSYNC_SPEEDUP_inst_addr                              "0x0194"
#define DCLK_FRC2FSYNC_SPEEDUP_inst                                   0x0194
#define DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_m_code_shift         (16)
#define DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_offset_shift         (0)
#define DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_m_code_mask          (0x00070000)
#define DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_offset_mask          (0x000007FF)
#define DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_m_code(data)         (0x00070000&((data)<<16))
#define DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_offset(data)         (0x000007FF&(data))
#define DCLK_FRC2FSYNC_SPEEDUP_get_frc2fsync_speedup_m_code(data)     ((0x00070000&(data))>>16)
#define DCLK_FRC2FSYNC_SPEEDUP_get_frc2fsync_speedup_offset(data)     (0x000007FF&(data))


#define DPLL_STATUS_RO                                                0x18000654
#define DPLL_STATUS_RO_reg_addr                                       "0xb8000654"
#define DPLL_STATUS_RO_reg                                            0xb8000654
#define DPLL_STATUS_RO_inst_addr                                      "0x0195"
#define DPLL_STATUS_RO_inst                                           0x0195
#define DPLL_STATUS_RO_final_m_code_shift                             (16)
#define DPLL_STATUS_RO_final_profile_shift                            (0)
#define DPLL_STATUS_RO_final_m_code_mask                              (0x03FF0000)
#define DPLL_STATUS_RO_final_profile_mask                             (0x00001FFF)
#define DPLL_STATUS_RO_final_m_code(data)                             (0x03FF0000&((data)<<16))
#define DPLL_STATUS_RO_final_profile(data)                            (0x00001FFF&(data))
#define DPLL_STATUS_RO_get_final_m_code(data)                         ((0x03FF0000&(data))>>16)
#define DPLL_STATUS_RO_get_final_profile(data)                        (0x00001FFF&(data))


#define DCLKSS_FREQ                                                   0x18000658
#define DCLKSS_FREQ_reg_addr                                          "0xb8000658"
#define DCLKSS_FREQ_reg                                               0xb8000658
#define DCLKSS_FREQ_inst_addr                                         "0x0196"
#define DCLKSS_FREQ_inst                                              0x0196
#define DCLKSS_FREQ_final_profile_force_64n_en_shift                  (30)
#define DCLKSS_FREQ_dclk_ss_async_protection_shift                    (29)
#define DCLKSS_FREQ_dclk_ss_fmdiv_shift                               (8)
#define DCLKSS_FREQ_dclk_ss_protection_cnt_max_shift                  (0)
#define DCLKSS_FREQ_final_profile_force_64n_en_mask                   (0xC0000000)
#define DCLKSS_FREQ_dclk_ss_async_protection_mask                     (0x20000000)
#define DCLKSS_FREQ_dclk_ss_fmdiv_mask                                (0x00007F00)
#define DCLKSS_FREQ_dclk_ss_protection_cnt_max_mask                   (0x0000007F)
#define DCLKSS_FREQ_final_profile_force_64n_en(data)                  (0xC0000000&((data)<<30))
#define DCLKSS_FREQ_dclk_ss_async_protection(data)                    (0x20000000&((data)<<29))
#define DCLKSS_FREQ_dclk_ss_fmdiv(data)                               (0x00007F00&((data)<<8))
#define DCLKSS_FREQ_dclk_ss_protection_cnt_max(data)                  (0x0000007F&(data))
#define DCLKSS_FREQ_get_final_profile_force_64n_en(data)              ((0xC0000000&(data))>>30)
#define DCLKSS_FREQ_get_dclk_ss_async_protection(data)                ((0x20000000&(data))>>29)
#define DCLKSS_FREQ_get_dclk_ss_fmdiv(data)                           ((0x00007F00&(data))>>8)
#define DCLKSS_FREQ_get_dclk_ss_protection_cnt_max(data)              (0x0000007F&(data))


#define DCLKSS_PROFILE0                                               0x1800065c
#define DCLKSS_PROFILE0_reg_addr                                      "0xb800065c"
#define DCLKSS_PROFILE0_reg                                           0xb800065c
#define DCLKSS_PROFILE0_inst_addr                                     "0x0197"
#define DCLKSS_PROFILE0_inst                                          0x0197
#define DCLKSS_PROFILE0_dummy1800065c_31_30_shift                     (30)
#define DCLKSS_PROFILE0_dclk_ss_shuffle_en_shift                      (29)
#define DCLKSS_PROFILE0_dclk_profile_remap_en_shift                   (28)
#define DCLKSS_PROFILE0_dclk_profile_remap_1_shift                    (16)
#define DCLKSS_PROFILE0_dclk_profile_remap_0_shift                    (0)
#define DCLKSS_PROFILE0_dummy1800065c_31_30_mask                      (0xC0000000)
#define DCLKSS_PROFILE0_dclk_ss_shuffle_en_mask                       (0x20000000)
#define DCLKSS_PROFILE0_dclk_profile_remap_en_mask                    (0x10000000)
#define DCLKSS_PROFILE0_dclk_profile_remap_1_mask                     (0x0FFF0000)
#define DCLKSS_PROFILE0_dclk_profile_remap_0_mask                     (0x00000FFF)
#define DCLKSS_PROFILE0_dummy1800065c_31_30(data)                     (0xC0000000&((data)<<30))
#define DCLKSS_PROFILE0_dclk_ss_shuffle_en(data)                      (0x20000000&((data)<<29))
#define DCLKSS_PROFILE0_dclk_profile_remap_en(data)                   (0x10000000&((data)<<28))
#define DCLKSS_PROFILE0_dclk_profile_remap_1(data)                    (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE0_dclk_profile_remap_0(data)                    (0x00000FFF&(data))
#define DCLKSS_PROFILE0_get_dummy1800065c_31_30(data)                 ((0xC0000000&(data))>>30)
#define DCLKSS_PROFILE0_get_dclk_ss_shuffle_en(data)                  ((0x20000000&(data))>>29)
#define DCLKSS_PROFILE0_get_dclk_profile_remap_en(data)               ((0x10000000&(data))>>28)
#define DCLKSS_PROFILE0_get_dclk_profile_remap_1(data)                ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE0_get_dclk_profile_remap_0(data)                (0x00000FFF&(data))


#define DCLKSS_PROFILE1                                               0x18000660
#define DCLKSS_PROFILE1_reg_addr                                      "0xb8000660"
#define DCLKSS_PROFILE1_reg                                           0xb8000660
#define DCLKSS_PROFILE1_inst_addr                                     "0x0198"
#define DCLKSS_PROFILE1_inst                                          0x0198
#define DCLKSS_PROFILE1_dclk_profile_remap_3_shift                    (16)
#define DCLKSS_PROFILE1_dclk_profile_remap_2_shift                    (0)
#define DCLKSS_PROFILE1_dclk_profile_remap_3_mask                     (0x0FFF0000)
#define DCLKSS_PROFILE1_dclk_profile_remap_2_mask                     (0x00000FFF)
#define DCLKSS_PROFILE1_dclk_profile_remap_3(data)                    (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE1_dclk_profile_remap_2(data)                    (0x00000FFF&(data))
#define DCLKSS_PROFILE1_get_dclk_profile_remap_3(data)                ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE1_get_dclk_profile_remap_2(data)                (0x00000FFF&(data))


#define DCLKSS_PROFILE2                                               0x18000664
#define DCLKSS_PROFILE2_reg_addr                                      "0xb8000664"
#define DCLKSS_PROFILE2_reg                                           0xb8000664
#define DCLKSS_PROFILE2_inst_addr                                     "0x0199"
#define DCLKSS_PROFILE2_inst                                          0x0199
#define DCLKSS_PROFILE2_dclk_profile_remap_5_shift                    (16)
#define DCLKSS_PROFILE2_dclk_profile_remap_4_shift                    (0)
#define DCLKSS_PROFILE2_dclk_profile_remap_5_mask                     (0x0FFF0000)
#define DCLKSS_PROFILE2_dclk_profile_remap_4_mask                     (0x00000FFF)
#define DCLKSS_PROFILE2_dclk_profile_remap_5(data)                    (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE2_dclk_profile_remap_4(data)                    (0x00000FFF&(data))
#define DCLKSS_PROFILE2_get_dclk_profile_remap_5(data)                ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE2_get_dclk_profile_remap_4(data)                (0x00000FFF&(data))


#define DCLKSS_PROFILE3                                               0x18000668
#define DCLKSS_PROFILE3_reg_addr                                      "0xb8000668"
#define DCLKSS_PROFILE3_reg                                           0xb8000668
#define DCLKSS_PROFILE3_inst_addr                                     "0x019A"
#define DCLKSS_PROFILE3_inst                                          0x019A
#define DCLKSS_PROFILE3_dclk_profile_remap_7_shift                    (16)
#define DCLKSS_PROFILE3_dclk_profile_remap_6_shift                    (0)
#define DCLKSS_PROFILE3_dclk_profile_remap_7_mask                     (0x0FFF0000)
#define DCLKSS_PROFILE3_dclk_profile_remap_6_mask                     (0x00000FFF)
#define DCLKSS_PROFILE3_dclk_profile_remap_7(data)                    (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE3_dclk_profile_remap_6(data)                    (0x00000FFF&(data))
#define DCLKSS_PROFILE3_get_dclk_profile_remap_7(data)                ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE3_get_dclk_profile_remap_6(data)                (0x00000FFF&(data))


#define DCLKSS_PROFILE4                                               0x1800066c
#define DCLKSS_PROFILE4_reg_addr                                      "0xb800066c"
#define DCLKSS_PROFILE4_reg                                           0xb800066c
#define DCLKSS_PROFILE4_inst_addr                                     "0x019B"
#define DCLKSS_PROFILE4_inst                                          0x019B
#define DCLKSS_PROFILE4_dclk_profile_remap_9_shift                    (16)
#define DCLKSS_PROFILE4_dclk_profile_remap_8_shift                    (0)
#define DCLKSS_PROFILE4_dclk_profile_remap_9_mask                     (0x0FFF0000)
#define DCLKSS_PROFILE4_dclk_profile_remap_8_mask                     (0x00000FFF)
#define DCLKSS_PROFILE4_dclk_profile_remap_9(data)                    (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE4_dclk_profile_remap_8(data)                    (0x00000FFF&(data))
#define DCLKSS_PROFILE4_get_dclk_profile_remap_9(data)                ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE4_get_dclk_profile_remap_8(data)                (0x00000FFF&(data))


#define DCLKSS_PROFILE5                                               0x18000670
#define DCLKSS_PROFILE5_reg_addr                                      "0xb8000670"
#define DCLKSS_PROFILE5_reg                                           0xb8000670
#define DCLKSS_PROFILE5_inst_addr                                     "0x019C"
#define DCLKSS_PROFILE5_inst                                          0x019C
#define DCLKSS_PROFILE5_dclk_profile_remap_11_shift                   (16)
#define DCLKSS_PROFILE5_dclk_profile_remap_10_shift                   (0)
#define DCLKSS_PROFILE5_dclk_profile_remap_11_mask                    (0x0FFF0000)
#define DCLKSS_PROFILE5_dclk_profile_remap_10_mask                    (0x00000FFF)
#define DCLKSS_PROFILE5_dclk_profile_remap_11(data)                   (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE5_dclk_profile_remap_10(data)                   (0x00000FFF&(data))
#define DCLKSS_PROFILE5_get_dclk_profile_remap_11(data)               ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE5_get_dclk_profile_remap_10(data)               (0x00000FFF&(data))


#define DCLKSS_PROFILE6                                               0x18000674
#define DCLKSS_PROFILE6_reg_addr                                      "0xb8000674"
#define DCLKSS_PROFILE6_reg                                           0xb8000674
#define DCLKSS_PROFILE6_inst_addr                                     "0x019D"
#define DCLKSS_PROFILE6_inst                                          0x019D
#define DCLKSS_PROFILE6_dclk_profile_remap_13_shift                   (16)
#define DCLKSS_PROFILE6_dclk_profile_remap_12_shift                   (0)
#define DCLKSS_PROFILE6_dclk_profile_remap_13_mask                    (0x0FFF0000)
#define DCLKSS_PROFILE6_dclk_profile_remap_12_mask                    (0x00000FFF)
#define DCLKSS_PROFILE6_dclk_profile_remap_13(data)                   (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE6_dclk_profile_remap_12(data)                   (0x00000FFF&(data))
#define DCLKSS_PROFILE6_get_dclk_profile_remap_13(data)               ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE6_get_dclk_profile_remap_12(data)               (0x00000FFF&(data))


#define DCLKSS_PROFILE7                                               0x18000678
#define DCLKSS_PROFILE7_reg_addr                                      "0xb8000678"
#define DCLKSS_PROFILE7_reg                                           0xb8000678
#define DCLKSS_PROFILE7_inst_addr                                     "0x019E"
#define DCLKSS_PROFILE7_inst                                          0x019E
#define DCLKSS_PROFILE7_dclk_profile_remap_15_shift                   (16)
#define DCLKSS_PROFILE7_dclk_profile_remap_14_shift                   (0)
#define DCLKSS_PROFILE7_dclk_profile_remap_15_mask                    (0x0FFF0000)
#define DCLKSS_PROFILE7_dclk_profile_remap_14_mask                    (0x00000FFF)
#define DCLKSS_PROFILE7_dclk_profile_remap_15(data)                   (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE7_dclk_profile_remap_14(data)                   (0x00000FFF&(data))
#define DCLKSS_PROFILE7_get_dclk_profile_remap_15(data)               ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE7_get_dclk_profile_remap_14(data)               (0x00000FFF&(data))


#define DCLKSS_PROFILE8                                               0x1800067c
#define DCLKSS_PROFILE8_reg_addr                                      "0xb800067c"
#define DCLKSS_PROFILE8_reg                                           0xb800067c
#define DCLKSS_PROFILE8_inst_addr                                     "0x019F"
#define DCLKSS_PROFILE8_inst                                          0x019F
#define DCLKSS_PROFILE8_dclk_profile_remap_17_shift                   (16)
#define DCLKSS_PROFILE8_dclk_profile_remap_16_shift                   (0)
#define DCLKSS_PROFILE8_dclk_profile_remap_17_mask                    (0x0FFF0000)
#define DCLKSS_PROFILE8_dclk_profile_remap_16_mask                    (0x00000FFF)
#define DCLKSS_PROFILE8_dclk_profile_remap_17(data)                   (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE8_dclk_profile_remap_16(data)                   (0x00000FFF&(data))
#define DCLKSS_PROFILE8_get_dclk_profile_remap_17(data)               ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE8_get_dclk_profile_remap_16(data)               (0x00000FFF&(data))


#define DCLKSS_PROFILE9                                               0x18000680
#define DCLKSS_PROFILE9_reg_addr                                      "0xb8000680"
#define DCLKSS_PROFILE9_reg                                           0xb8000680
#define DCLKSS_PROFILE9_inst_addr                                     "0x01A0"
#define DCLKSS_PROFILE9_inst                                          0x01A0
#define DCLKSS_PROFILE9_dclk_profile_remap_19_shift                   (16)
#define DCLKSS_PROFILE9_dclk_profile_remap_18_shift                   (0)
#define DCLKSS_PROFILE9_dclk_profile_remap_19_mask                    (0x0FFF0000)
#define DCLKSS_PROFILE9_dclk_profile_remap_18_mask                    (0x00000FFF)
#define DCLKSS_PROFILE9_dclk_profile_remap_19(data)                   (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE9_dclk_profile_remap_18(data)                   (0x00000FFF&(data))
#define DCLKSS_PROFILE9_get_dclk_profile_remap_19(data)               ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE9_get_dclk_profile_remap_18(data)               (0x00000FFF&(data))


#define DCLKSS_PROFILE10                                              0x18000684
#define DCLKSS_PROFILE10_reg_addr                                     "0xb8000684"
#define DCLKSS_PROFILE10_reg                                          0xb8000684
#define DCLKSS_PROFILE10_inst_addr                                    "0x01A1"
#define DCLKSS_PROFILE10_inst                                         0x01A1
#define DCLKSS_PROFILE10_dclk_profile_remap_21_shift                  (16)
#define DCLKSS_PROFILE10_dclk_profile_remap_20_shift                  (0)
#define DCLKSS_PROFILE10_dclk_profile_remap_21_mask                   (0x0FFF0000)
#define DCLKSS_PROFILE10_dclk_profile_remap_20_mask                   (0x00000FFF)
#define DCLKSS_PROFILE10_dclk_profile_remap_21(data)                  (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE10_dclk_profile_remap_20(data)                  (0x00000FFF&(data))
#define DCLKSS_PROFILE10_get_dclk_profile_remap_21(data)              ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE10_get_dclk_profile_remap_20(data)              (0x00000FFF&(data))


#define DCLKSS_PROFILE11                                              0x18000688
#define DCLKSS_PROFILE11_reg_addr                                     "0xb8000688"
#define DCLKSS_PROFILE11_reg                                          0xb8000688
#define DCLKSS_PROFILE11_inst_addr                                    "0x01A2"
#define DCLKSS_PROFILE11_inst                                         0x01A2
#define DCLKSS_PROFILE11_dclk_profile_remap_23_shift                  (16)
#define DCLKSS_PROFILE11_dclk_profile_remap_22_shift                  (0)
#define DCLKSS_PROFILE11_dclk_profile_remap_23_mask                   (0x0FFF0000)
#define DCLKSS_PROFILE11_dclk_profile_remap_22_mask                   (0x00000FFF)
#define DCLKSS_PROFILE11_dclk_profile_remap_23(data)                  (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE11_dclk_profile_remap_22(data)                  (0x00000FFF&(data))
#define DCLKSS_PROFILE11_get_dclk_profile_remap_23(data)              ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE11_get_dclk_profile_remap_22(data)              (0x00000FFF&(data))


#define DCLKSS_PROFILE12                                              0x1800068c
#define DCLKSS_PROFILE12_reg_addr                                     "0xb800068c"
#define DCLKSS_PROFILE12_reg                                          0xb800068c
#define DCLKSS_PROFILE12_inst_addr                                    "0x01A3"
#define DCLKSS_PROFILE12_inst                                         0x01A3
#define DCLKSS_PROFILE12_dclk_profile_remap_25_shift                  (16)
#define DCLKSS_PROFILE12_dclk_profile_remap_24_shift                  (0)
#define DCLKSS_PROFILE12_dclk_profile_remap_25_mask                   (0x0FFF0000)
#define DCLKSS_PROFILE12_dclk_profile_remap_24_mask                   (0x00000FFF)
#define DCLKSS_PROFILE12_dclk_profile_remap_25(data)                  (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE12_dclk_profile_remap_24(data)                  (0x00000FFF&(data))
#define DCLKSS_PROFILE12_get_dclk_profile_remap_25(data)              ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE12_get_dclk_profile_remap_24(data)              (0x00000FFF&(data))


#define DCLKSS_PROFILE13                                              0x18000690
#define DCLKSS_PROFILE13_reg_addr                                     "0xb8000690"
#define DCLKSS_PROFILE13_reg                                          0xb8000690
#define DCLKSS_PROFILE13_inst_addr                                    "0x01A4"
#define DCLKSS_PROFILE13_inst                                         0x01A4
#define DCLKSS_PROFILE13_dclk_profile_remap_27_shift                  (16)
#define DCLKSS_PROFILE13_dclk_profile_remap_26_shift                  (0)
#define DCLKSS_PROFILE13_dclk_profile_remap_27_mask                   (0x0FFF0000)
#define DCLKSS_PROFILE13_dclk_profile_remap_26_mask                   (0x00000FFF)
#define DCLKSS_PROFILE13_dclk_profile_remap_27(data)                  (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE13_dclk_profile_remap_26(data)                  (0x00000FFF&(data))
#define DCLKSS_PROFILE13_get_dclk_profile_remap_27(data)              ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE13_get_dclk_profile_remap_26(data)              (0x00000FFF&(data))


#define DCLKSS_PROFILE14                                              0x18000694
#define DCLKSS_PROFILE14_reg_addr                                     "0xb8000694"
#define DCLKSS_PROFILE14_reg                                          0xb8000694
#define DCLKSS_PROFILE14_inst_addr                                    "0x01A5"
#define DCLKSS_PROFILE14_inst                                         0x01A5
#define DCLKSS_PROFILE14_dclk_profile_remap_29_shift                  (16)
#define DCLKSS_PROFILE14_dclk_profile_remap_28_shift                  (0)
#define DCLKSS_PROFILE14_dclk_profile_remap_29_mask                   (0x0FFF0000)
#define DCLKSS_PROFILE14_dclk_profile_remap_28_mask                   (0x00000FFF)
#define DCLKSS_PROFILE14_dclk_profile_remap_29(data)                  (0x0FFF0000&((data)<<16))
#define DCLKSS_PROFILE14_dclk_profile_remap_28(data)                  (0x00000FFF&(data))
#define DCLKSS_PROFILE14_get_dclk_profile_remap_29(data)              ((0x0FFF0000&(data))>>16)
#define DCLKSS_PROFILE14_get_dclk_profile_remap_28(data)              (0x00000FFF&(data))


#define DCLKSS_PROFILE15                                              0x18000698
#define DCLKSS_PROFILE15_reg_addr                                     "0xb8000698"
#define DCLKSS_PROFILE15_reg                                          0xb8000698
#define DCLKSS_PROFILE15_inst_addr                                    "0x01A6"
#define DCLKSS_PROFILE15_inst                                         0x01A6
#define DCLKSS_PROFILE15_dclk_profile_remap_31_shift                  (16)
#define DCLKSS_PROFILE15_dclk_profile_remap_30_shift                  (0)
#define DCLKSS_PROFILE15_dclk_profile_remap_31_mask                   (0x1FFF0000)
#define DCLKSS_PROFILE15_dclk_profile_remap_30_mask                   (0x00000FFF)
#define DCLKSS_PROFILE15_dclk_profile_remap_31(data)                  (0x1FFF0000&((data)<<16))
#define DCLKSS_PROFILE15_dclk_profile_remap_30(data)                  (0x00000FFF&(data))
#define DCLKSS_PROFILE15_get_dclk_profile_remap_31(data)              ((0x1FFF0000&(data))>>16)
#define DCLKSS_PROFILE15_get_dclk_profile_remap_30(data)              (0x00000FFF&(data))
#endif

