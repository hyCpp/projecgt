在binaryMakefile文件夹下运行
python makeBinary.py /home/xxxx/ + 源代码仓库路径  /home/xxxx/ + 二进制仓库路径
之后会在二进制仓库路径下生成nutshell.mk和yaml文件
如果原仓库路径中有proto文件则会在控制台打印出来，之后自行添加nutshell.mk中proto的include拷贝和yaml中proto的拷贝
repo init -u ssh://igerrit.storm:29418/Src/17Model/17Cy/manifest -b origin/17cyplus/master/t1t2plus -m vendor.xml


<action_result>
    <system_state></system_state>
    <system_state_action></system_state_action>   // SYSTEM_STATE_BEGIN,SYSTEM_STATE_END
</action_result>

system_state:
DISABLE, //灰光圈
SYSTEM_STATE_READY, // engine initialize,small red point
SYSTEM_STATE_BASIC_INIT, + SYSTEM_STATE_END, //正常光圈  idle
SYSTEM_STATE_BASIC_INIT + FC_VUI_RESULT_ASR_BEGIN, //灰光圈
SYSTEM_STATE_DIALOG + SYSTEM_STATE_BEGIN, // idle
SYSTEM_STATE_DIALOG + SYSTEM_STATE_END, //stop,
SYSTEM_STATE_PROMPTING,  // ttsprompting
SYSTEM_STATE_SPEECH + SYSTEM_STATE_BEGIN, // listening 
FC_VUI_RESULT_ASR_SPEECH + FC_VUI_RESULT_ASR_END, // processing
SYSTEM_STATE_RECOGNITION, 


