# a boris pusher implemented in python before

def UpdateV(x1, x2, v1, v2, v3,dt, depth,ddepth_dt):
    global Calc_Eind
    E1, E2, E3, B1, B2, B3 = CalcEB(x1,x2, depth, ddepth_dt)
    v1_m = v1 + q * E1 *dt /2
    v2_m = v2 + q * E2 *dt /2
    v3_m = v3 + q * E3 *dt /2
    t1 = q * B1 * dt / 2
    t2 = q * B2 * dt / 2
    t3 = q * B3 * dt / 2
    v1_s = v1_m + v2_m * t3 - v3_m * t2
    v2_s = v2_m + v3_m * t1 - v1_m * t3
    v3_s = v3_m + v1_m * t2 - v2_m * t1
    tsq = t1**2+t2**2+t3**2
    s1 = t1*2/(1+tsq)
    s2 = t2*2/(1+tsq)
    s3 = t3*2/(1+tsq)
    v1_p = v1_m + v2_s * s3 - v3_s * s2
    v2_p = v2_m + v3_s * s1 - v1_s * s3
    v3_p = v3_m + v1_s * s2 - v2_s * s1
    v1_p += q * E1 *dt /2
    v2_p += q * E2 *dt /2
    v3_p += q * E3 *dt /2
    return v1_p, v2_p, v3_p


