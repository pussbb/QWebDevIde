#include "mimedata.h"
QHash<QString, QString> ff(){
   QHash<QString, QString> m_hash;
   m_hash.insert("ai","application/illustrator");
   m_hash.insert("nb","application/mathematica");
   m_hash.insert("bin","application/octet-stream");
   m_hash.insert("oda","application/oda");
   m_hash.insert("pdf","application/pdf");
   m_hash.insert("xspf","application/xspf+xml");
   m_hash.insert("pla","audio/x-iriver-pla");
   m_hash.insert("pgp","application/pgp-encrypted");
   m_hash.insert("gpg","application/pgp-encrypted");
   m_hash.insert("asc","application/pgp-encrypted");
   m_hash.insert("skr","application/pgp-keys");
   m_hash.insert("pkr","application/pgp-keys");
   m_hash.insert("asc","application/pgp-keys");
   m_hash.insert("p7s","application/pkcs7-signature");
   m_hash.insert("p10","application/pkcs10");
   m_hash.insert("ps","application/postscript");
   m_hash.insert("rtf","application/rtf");
   m_hash.insert("siv","application/sieve");
   m_hash.insert("smil","application/smil");
   m_hash.insert("smi","application/smil");
   m_hash.insert("sml","application/smil");
   m_hash.insert("kino","application/smil");
   m_hash.insert("sit","application/stuffit");
   m_hash.insert("ged","application/x-gedcom");
   m_hash.insert("gedcom","application/x-gedcom");
   m_hash.insert("flv","application/x-flash-video");
   m_hash.insert("sgf","application/x-go-sgf");
   m_hash.insert("xlf","application/x-xliff");
   m_hash.insert("xliff","application/x-xliff");
   m_hash.insert("cdr","application/vnd.corel-draw");
   m_hash.insert("hpgl","application/vnd.hp-hpgl");
   m_hash.insert("pcl","application/vnd.hp-pcl");
   m_hash.insert("123","application/vnd.lotus-1-2-3");
   m_hash.insert("wk1","application/vnd.lotus-1-2-3");
   m_hash.insert("wk3","application/vnd.lotus-1-2-3");
   m_hash.insert("wk4","application/vnd.lotus-1-2-3");
   m_hash.insert("wks","application/vnd.lotus-1-2-3");
   m_hash.insert("xul","application/vnd.mozilla.xul+xml");
   m_hash.insert("mdb","application/vnd.ms-access");
   m_hash.insert("xls","application/vnd.ms-excel");
   m_hash.insert("xlc","application/vnd.ms-excel");
   m_hash.insert("xll","application/vnd.ms-excel");
   m_hash.insert("xlm","application/vnd.ms-excel");
   m_hash.insert("xlw","application/vnd.ms-excel");
   m_hash.insert("xla","application/vnd.ms-excel");
   m_hash.insert("xlt","application/vnd.ms-excel");
   m_hash.insert("xld","application/vnd.ms-excel");
   m_hash.insert("ppz","application/vnd.ms-powerpoint");
   m_hash.insert("ppt","application/vnd.ms-powerpoint");
   m_hash.insert("pps","application/vnd.ms-powerpoint");
   m_hash.insert("pot","application/vnd.ms-powerpoint");
   m_hash.insert("xps","application/vnd.ms-xpsdocument");
   m_hash.insert("doc","application/msword");
   m_hash.insert("tnef","application/vnd.ms-tnef");
   m_hash.insert("tnf","application/vnd.ms-tnef");
   m_hash.insert("sdc","application/vnd.stardivision.calc");
   m_hash.insert("sds","application/vnd.stardivision.chart");
   m_hash.insert("sda","application/vnd.stardivision.draw");
   m_hash.insert("sdd","application/vnd.stardivision.impress");
   m_hash.insert("sdp","application/vnd.stardivision.impress");
   m_hash.insert("smd","application/vnd.stardivision.mail");
   m_hash.insert("smf","application/vnd.stardivision.math");
   m_hash.insert("sdw","application/vnd.stardivision.writer");
   m_hash.insert("vor","application/vnd.stardivision.writer");
   m_hash.insert("sgl","application/vnd.stardivision.writer");
   m_hash.insert("sxc","application/vnd.sun.xml.calc");
   m_hash.insert("stc","application/vnd.sun.xml.calc.template");
   m_hash.insert("sxd","application/vnd.sun.xml.draw");
   m_hash.insert("std","application/vnd.sun.xml.draw.template");
   m_hash.insert("sxi","application/vnd.sun.xml.impress");
   m_hash.insert("sti","application/vnd.sun.xml.impress.template");
   m_hash.insert("sxm","application/vnd.sun.xml.math");
   m_hash.insert("sxw","application/vnd.sun.xml.writer");
   m_hash.insert("sxg","application/vnd.sun.xml.writer.global");
   m_hash.insert("stw","application/vnd.sun.xml.writer.template");
   m_hash.insert("odt","application/vnd.oasis.opendocument.text");
   m_hash.insert("ott","application/vnd.oasis.opendocument.text-template");
   m_hash.insert("oth","application/vnd.oasis.opendocument.text-web");
   m_hash.insert("odm","application/vnd.oasis.opendocument.text-master");
   m_hash.insert("odg","application/vnd.oasis.opendocument.graphics");
   m_hash.insert("otg","application/vnd.oasis.opendocument.graphics-template");
   m_hash.insert("odp","application/vnd.oasis.opendocument.presentation");
   m_hash.insert("otp","application/vnd.oasis.opendocument.presentation-template");
   m_hash.insert("ods","application/vnd.oasis.opendocument.spreadsheet");
   m_hash.insert("ots","application/vnd.oasis.opendocument.spreadsheet-template");
   m_hash.insert("odc","application/vnd.oasis.opendocument.chart");
   m_hash.insert("odf","application/vnd.oasis.opendocument.formula");
   m_hash.insert("odb","application/vnd.oasis.opendocument.database");
   m_hash.insert("odi","application/vnd.oasis.opendocument.image");
   m_hash.insert("sis","application/vnd.symbian.install");
   m_hash.insert("sisx","x-epoc/x-sisx-app");
   m_hash.insert("wp","application/vnd.wordperfect");
   m_hash.insert("wp4","application/vnd.wordperfect");
   m_hash.insert("wp5","application/vnd.wordperfect");
   m_hash.insert("wp6","application/vnd.wordperfect");
   m_hash.insert("wpd","application/vnd.wordperfect");
   m_hash.insert("wpp","application/vnd.wordperfect");
   m_hash.insert("xbel","application/x-xbel");
   m_hash.insert("7z","application/x-7z-compressed");
   m_hash.insert("abw","application/x-abiword");
   m_hash.insert("zabw","application/x-abiword");
   m_hash.insert("cue","application/x-cue");
   m_hash.insert("sam","application/x-amipro");
   m_hash.insert("as","application/x-applix-spreadsheet");
   m_hash.insert("aw","application/x-applix-word");
   m_hash.insert("a","application/x-archive");
   m_hash.insert("arj","application/x-arj");
   m_hash.insert("asp","application/x-asp");
   m_hash.insert("bcpio","application/x-bcpio");
   m_hash.insert("torrent","application/x-bittorrent");
   m_hash.insert("blender","application/x-blender");
   m_hash.insert("blend","application/x-blender");
   m_hash.insert("BLEND","application/x-blender");
   m_hash.insert("dvi.bz2","application/x-bzdvi");
   m_hash.insert("bz","application/x-bzip");
   m_hash.insert("bz2","application/x-bzip");
   m_hash.insert("tar.bz","application/x-bzip-compressed-tar");
   m_hash.insert("tar.bz2","application/x-bzip-compressed-tar");
   m_hash.insert("tbz","application/x-bzip-compressed-tar");
   m_hash.insert("tbz2","application/x-bzip-compressed-tar");
   m_hash.insert("pdf.bz2","application/x-bzpdf");
   m_hash.insert("ps.bz2","application/x-bzpostscript");
   m_hash.insert("cbr","application/x-cbr");
   m_hash.insert("cbz","application/x-cbz");
   m_hash.insert("iso","application/x-cd-image");
   m_hash.insert("iso9660","application/x-cd-image");
   m_hash.insert("cgi","application/x-cgi");
   m_hash.insert("pgn","application/x-chess-pgn");
   m_hash.insert("chm","application/x-chm");
   m_hash.insert("Z","application/x-compress");
   m_hash.insert("tar.gz","application/x-compressed-tar");
   m_hash.insert("tgz","application/x-compressed-tar");
   m_hash.insert("core","application/x-core");
   m_hash.insert("cpio","application/x-cpio");
   m_hash.insert("cpio.gz","application/x-cpio-compressed");
   m_hash.insert("csh","application/x-csh");
   m_hash.insert("dbf","application/x-dbf");
   m_hash.insert("es","application/ecmascript");
   m_hash.insert("dc","application/x-dc-rom");
   m_hash.insert("nds","application/x-nintendo-ds-rom");
   m_hash.insert("deb","application/x-deb");
   m_hash.insert("ui","application/x-designer");
   m_hash.insert("desktop","application/x-desktop");
   m_hash.insert("kdelnk","application/x-desktop");
   m_hash.insert("dia","application/x-dia-diagram");
   m_hash.insert("dvi","application/x-dvi");
   m_hash.insert("etheme","application/x-e-theme");
   m_hash.insert("egon","application/x-egon");
   m_hash.insert("exe","application/x-executable");
   m_hash.insert("pfa","application/x-font-type1");
   m_hash.insert("pfb","application/x-font-type1");
   m_hash.insert("gsf","application/x-font-type1");
   m_hash.insert("afm","application/x-font-afm");
   m_hash.insert("bdf","application/x-font-bdf");
   m_hash.insert("psf","application/x-font-linux-psf");
   m_hash.insert("psf.gz","application/x-gz-font-linux-psf");
   m_hash.insert("pcf","application/x-font-pcf");
   m_hash.insert("pcf.Z","application/x-font-pcf");
   m_hash.insert("pcf.gz","application/x-font-pcf");
   m_hash.insert("spd","application/x-font-speedo");
   m_hash.insert("ttf","application/x-font-ttf");
   m_hash.insert("ttc","application/x-font-ttf");
   m_hash.insert("gb","application/x-gameboy-rom");
   m_hash.insert("gba","application/x-gba-rom");
   m_hash.insert("gen","application/x-genesis-rom");
   m_hash.insert("md","application/x-genesis-rom");
   m_hash.insert("gmo","application/x-gettext-translation");
   m_hash.insert("mo","application/x-gettext-translation");
   m_hash.insert("glade","application/x-glade");
   m_hash.insert("gnucash","application/x-gnucash");
   m_hash.insert("gnc","application/x-gnucash");
   m_hash.insert("xac","application/x-gnucash");
   m_hash.insert("gnumeric","application/x-gnumeric");
   m_hash.insert("gp","application/x-gnuplot");
   m_hash.insert("gplt","application/x-gnuplot");
   m_hash.insert("gnuplot","application/x-gnuplot");
   m_hash.insert("gra","application/x-graphite");
   m_hash.insert("dvi.gz","application/x-gzdvi");
   m_hash.insert("gz","application/x-gzip");
   m_hash.insert("pdf.gz","application/x-gzpdf");
   m_hash.insert("ps.gz","application/x-gzpostscript");
   m_hash.insert("hdf","application/x-hdf");
   m_hash.insert("jar","application/x-java-archive");
   m_hash.insert("class","application/x-java");
   m_hash.insert("jnlp","application/x-java-jnlp-file");
   m_hash.insert("js","application/javascript");
   m_hash.insert("jpr","application/x-jbuilder-project");
   m_hash.insert("jpx","application/x-jbuilder-project");
   m_hash.insert("karbon","application/x-karbon");
   m_hash.insert("chrt","application/x-kchart");
   m_hash.insert("kfo","application/x-kformula");
   m_hash.insert("kil","application/x-killustrator");
   m_hash.insert("flw","application/x-kivio");
   m_hash.insert("kon","application/x-kontour");
   m_hash.insert("kpm","application/x-kpovmodeler");
   m_hash.insert("kpr","application/x-kpresenter");
   m_hash.insert("kpt","application/x-kpresenter");
   m_hash.insert("kra","application/x-krita");
   m_hash.insert("ksp","application/x-kspread");
   m_hash.insert("kud","application/x-kugar");
   m_hash.insert("kwd","application/x-kword");
   m_hash.insert("kwt","application/x-kword");
   m_hash.insert("lha","application/x-lha");
   m_hash.insert("lzh","application/x-lha");
   m_hash.insert("lhz","application/x-lhz");
   m_hash.insert("ts","application/x-linguist");
   m_hash.insert("lyx","application/x-lyx");
   m_hash.insert("lzo","application/x-lzop");
   m_hash.insert("mgp","application/x-magicpoint");
   m_hash.insert("mkv","video/x-matroska");
   m_hash.insert("mka","audio/x-matroska");
   m_hash.insert("ocl","text/x-ocl");
   m_hash.insert("mif","application/x-mif");
   m_hash.insert("wri","application/x-mswrite");
   m_hash.insert("msx","application/x-msx-rom");
   m_hash.insert("m4","application/x-m4");
   m_hash.insert("n64","application/x-n64-rom");
   m_hash.insert("nes","application/x-nes-rom");
   m_hash.insert("cdf","application/x-netcdf");
   m_hash.insert("nc","application/x-netcdf");
   m_hash.insert("o","application/x-object");
   m_hash.insert("ogg","application/ogg");
   m_hash.insert("ogx","application/ogg");
   m_hash.insert("oga","audio/ogg");
   m_hash.insert("ogv","video/ogg");
   m_hash.insert("ogg","audio/x-vorbis+ogg");
   m_hash.insert("ogg","audio/x-flac+ogg");
   m_hash.insert("ogg","audio/x-speex+ogg");
   m_hash.insert("spx","audio/x-speex");
   m_hash.insert("ogg","video/x-theora+ogg");
   m_hash.insert("ogm","video/x-ogm+ogg");
   m_hash.insert("oleo","application/x-oleo");
   m_hash.insert("pak","application/x-pak");
   m_hash.insert("pdb","application/x-palm-database");
   m_hash.insert("prc","application/x-palm-database");
   m_hash.insert("PAR2","application/x-par2");
   m_hash.insert("par2","application/x-par2");
   m_hash.insert("pl","application/x-perl");
   m_hash.insert("pm","application/x-perl");
   m_hash.insert("al","application/x-perl");
   m_hash.insert("perl","application/x-perl");
   m_hash.insert("php","application/x-php");
   m_hash.insert("php3","application/x-php");
   m_hash.insert("php4","application/x-php");
   m_hash.insert("inc","application/x-php");
   m_hash.insert("p12","application/x-pkcs12");
   m_hash.insert("pfx","application/x-pkcs12");
   m_hash.insert("pln","application/x-planperfect");
   m_hash.insert("pw","application/x-pw");
   m_hash.insert("pyc","application/x-python-bytecode");
   m_hash.insert("pyo","application/x-python-bytecode");
   m_hash.insert("wb1","application/x-quattropro");
   m_hash.insert("wb2","application/x-quattropro");
   m_hash.insert("wb3","application/x-quattropro");
   m_hash.insert("qtl","application/x-quicktime-media-link");
   m_hash.insert("qif","application/x-qw");
   m_hash.insert("rar","application/x-rar");
   m_hash.insert("dar","application/x-dar");
   m_hash.insert("rej","application/x-reject");
   m_hash.insert("rpm","application/x-rpm");
   m_hash.insert("rb","application/x-ruby");
   m_hash.insert("mab","application/x-markaby");
   m_hash.insert("shar","application/x-shar");
   m_hash.insert("la","application/x-shared-library-la");
   m_hash.insert("so","application/x-sharedlib");
   m_hash.insert("sh","application/x-shellscript");
   m_hash.insert("swf","application/x-shockwave-flash");
   m_hash.insert("spl","application/x-shockwave-flash");
   m_hash.insert("shn","application/x-shorten");
   m_hash.insert("siag","application/x-siag");
   m_hash.insert("sms","application/x-sms-rom");
   m_hash.insert("gg","application/x-sms-rom");
   m_hash.insert("smc","application/x-snes-rom");
   m_hash.insert("srt","application/x-subrip");
   m_hash.insert("smi","application/x-sami");
   m_hash.insert("sami","application/x-sami");
   m_hash.insert("sub","text/x-microdvd");
   m_hash.insert("sub","text/x-mpsub");
   m_hash.insert("ssa","text/x-ssa");
   m_hash.insert("ass","text/x-ssa");
   m_hash.insert("sv4cpio","application/x-sv4cpio");
   m_hash.insert("sv4crc","application/x-sv4crc");
   m_hash.insert("tar","application/x-tar");
   m_hash.insert("gtar","application/x-tar");
   m_hash.insert("gf","application/x-tex-gf");
   m_hash.insert("pk","application/x-tex-pk");
   m_hash.insert("obj","application/x-tgif");
   m_hash.insert("theme","application/x-theme");
   m_hash.insert("bak","application/x-trash");
   m_hash.insert("old","application/x-trash");
   m_hash.insert("sik","application/x-trash");
   m_hash.insert("tr","text/troff");
   m_hash.insert("roff","text/troff");
   m_hash.insert("t","text/troff");
   m_hash.insert("man","application/x-troff-man");
   m_hash.insert("tzo","application/x-tzo");
   m_hash.insert("ustar","application/x-ustar");
   m_hash.insert("src","application/x-wais-source");
   m_hash.insert("wpg","application/x-wpg");
   m_hash.insert("der","application/x-x509-ca-cert");
   m_hash.insert("cer","application/x-x509-ca-cert");
   m_hash.insert("crt","application/x-x509-ca-cert");
   m_hash.insert("cert","application/x-x509-ca-cert");
   m_hash.insert("pem","application/x-x509-ca-cert");
   m_hash.insert("zoo","application/x-zoo");
   m_hash.insert("xhtml","application/xhtml+xml");
   m_hash.insert("zip","application/zip");
   m_hash.insert("ac3","audio/ac3");
   m_hash.insert("amr","audio/AMR");
   m_hash.insert("awb","audio/AMR-WB");
   m_hash.insert("au","audio/basic");
   m_hash.insert("snd","audio/basic");
   m_hash.insert("sid","audio/prs.sid");
   m_hash.insert("psid","audio/prs.sid");
   m_hash.insert("aiff","audio/x-aiff");
   m_hash.insert("aif","audio/x-aiff");
   m_hash.insert("aifc","audio/x-aiff");
   m_hash.insert("ape","audio/x-ape");
   m_hash.insert("it","audio/x-it");
   m_hash.insert("flac","audio/x-flac");
   m_hash.insert("wv","audio/x-wavpack");
   m_hash.insert("wvp","audio/x-wavpack");
   m_hash.insert("wvc","audio/x-wavpack-correction");
   m_hash.insert("mid","audio/midi");
   m_hash.insert("midi","audio/midi");
   m_hash.insert("kar","audio/midi");
   m_hash.insert("m4a","audio/mp4");
   m_hash.insert("aac","audio/mp4");
   m_hash.insert("mp4","video/mp4");
   m_hash.insert("m4v","video/mp4");
   m_hash.insert("m4b","audio/x-m4b");
   m_hash.insert("3gp","video/3gpp");
   m_hash.insert("3gpp","video/3gpp");
   m_hash.insert("amr","video/3gpp");
   m_hash.insert("mod","audio/x-mod");
   m_hash.insert("ult","audio/x-mod");
   m_hash.insert("uni","audio/x-mod");
   m_hash.insert("m15","audio/x-mod");
   m_hash.insert("mtm","audio/x-mod");
   m_hash.insert("669","audio/x-mod");
   m_hash.insert("mp2","audio/mp2");
   m_hash.insert("mp3","audio/mpeg");
   m_hash.insert("mpga","audio/mpeg");
   m_hash.insert("m3u","audio/x-mpegurl");
   m_hash.insert("vlc","audio/x-mpegurl");
   m_hash.insert("asx","audio/x-ms-asx");
   m_hash.insert("wax","audio/x-ms-asx");
   m_hash.insert("wvx","audio/x-ms-asx");
   m_hash.insert("wmx","audio/x-ms-asx");
   m_hash.insert("psf","audio/x-psf");
   m_hash.insert("minipsf","audio/x-minipsf");
   m_hash.insert("psflib","audio/x-psflib");
   m_hash.insert("wma","audio/x-ms-wma");
   m_hash.insert("mpc","audio/x-musepack");
   m_hash.insert("mpp","audio/x-musepack");
   m_hash.insert("ra","audio/vnd.rn-realaudio");
   m_hash.insert("rax","audio/vnd.rn-realaudio");
   m_hash.insert("ram","application/ram");
   m_hash.insert("rv","video/vnd.rn-realvideo");
   m_hash.insert("rvx","video/vnd.rn-realvideo");
   m_hash.insert("rm","application/vnd.rn-realmedia");
   m_hash.insert("rmj","application/vnd.rn-realmedia");
   m_hash.insert("rmm","application/vnd.rn-realmedia");
   m_hash.insert("rms","application/vnd.rn-realmedia");
   m_hash.insert("rmx","application/vnd.rn-realmedia");
   m_hash.insert("rmvb","application/vnd.rn-realmedia");
   m_hash.insert("rp","image/vnd.rn-realpix");
   m_hash.insert("rt","text/vnd.rn-realtext");
   m_hash.insert("s3m","audio/x-s3m");
   m_hash.insert("pls","audio/x-scpls");
   m_hash.insert("stm","audio/x-stm");
   m_hash.insert("voc","audio/x-voc");
   m_hash.insert("wav","audio/x-wav");
   m_hash.insert("xi","audio/x-xi");
   m_hash.insert("xm","audio/x-xm");
   m_hash.insert("tta","audio/x-tta");
   m_hash.insert("bmp","image/bmp");
   m_hash.insert("wbmp","image/vnd.wap.wbmp");
   m_hash.insert("cgm","image/cgm");
   m_hash.insert("g3","image/fax-g3");
   m_hash.insert("gif","image/gif");
   m_hash.insert("ief","image/ief");
   m_hash.insert("jpeg","image/jpeg");
   m_hash.insert("jpg","image/jpeg");
   m_hash.insert("jpe","image/jpeg");
   m_hash.insert("jp2","image/jp2");
   m_hash.insert("jpc","image/jp2");
   m_hash.insert("jpx","image/jp2");
   m_hash.insert("j2k","image/jp2");
   m_hash.insert("jpf","image/jp2");
   m_hash.insert("dds","image/x-dds");
   m_hash.insert("pict","image/x-pict");
   m_hash.insert("pict1","image/x-pict");
   m_hash.insert("pict2","image/x-pict");
   m_hash.insert("ufraw","application/x-ufraw");
   m_hash.insert("dng","image/x-adobe-dng");
   m_hash.insert("crw","image/x-canon-crw");
   m_hash.insert("cr2","image/x-canon-cr2");
   m_hash.insert("raf","image/x-fuji-raf");
   m_hash.insert("dcr","image/x-kodak-dcr");
   m_hash.insert("k25","image/x-kodak-k25");
   m_hash.insert("kdc","image/x-kodak-kdc");
   m_hash.insert("mrw","image/x-minolta-mrw");
   m_hash.insert("nef","image/x-nikon-nef");
   m_hash.insert("orf","image/x-olympus-orf");
   m_hash.insert("raw","image/x-panasonic-raw");
   m_hash.insert("pef","image/x-pentax-pef");
   m_hash.insert("x3f","image/x-sigma-x3f");
   m_hash.insert("srf","image/x-sony-srf");
   m_hash.insert("sr2","image/x-sony-sr2");
   m_hash.insert("arw","image/x-sony-arw");
   m_hash.insert("png","image/png");
   m_hash.insert("rle","image/rle");
   m_hash.insert("svg","image/svg+xml");
   m_hash.insert("svgz","image/svg+xml-compressed");
   m_hash.insert("tif","image/tiff");
   m_hash.insert("tiff","image/tiff");
   m_hash.insert("dwg","image/vnd.dwg");
   m_hash.insert("dxf","image/vnd.dxf");
   m_hash.insert("3ds","image/x-3ds");
   m_hash.insert("ag","image/x-applix-graphics");
   m_hash.insert("eps.bz2","image/x-bzeps");
   m_hash.insert("epsi.bz2","image/x-bzeps");
   m_hash.insert("epsf.bz2","image/x-bzeps");
   m_hash.insert("ras","image/x-cmu-raster");
   m_hash.insert("xcf.gz","image/x-compressed-xcf");
   m_hash.insert("xcf.bz2","image/x-compressed-xcf");
   m_hash.insert("dcm","application/dicom");
   m_hash.insert("docbook","application/docbook+xml");
   m_hash.insert("djvu","image/vnd.djvu");
   m_hash.insert("djv","image/vnd.djvu");
   m_hash.insert("eps","image/x-eps");
   m_hash.insert("epsi","image/x-eps");
   m_hash.insert("epsf","image/x-eps");
   m_hash.insert("fits","image/x-fits");
   m_hash.insert("eps.gz","image/x-gzeps");
   m_hash.insert("epsi.gz","image/x-gzeps");
   m_hash.insert("epsf.gz","image/x-gzeps");
   m_hash.insert("ico","image/x-ico");
   m_hash.insert("icns","image/x-icns");
   m_hash.insert("iff","image/x-iff");
   m_hash.insert("ilbm","image/x-ilbm");
   m_hash.insert("jng","image/x-jng");
   m_hash.insert("lwo","image/x-lwo");
   m_hash.insert("lwob","image/x-lwo");
   m_hash.insert("lws","image/x-lws");
   m_hash.insert("pntg","image/x-macpaint");
   m_hash.insert("msod","image/x-msod");
   m_hash.insert("pcd","image/x-photo-cd");
   m_hash.insert("pnm","image/x-portable-anymap");
   m_hash.insert("pbm","image/x-portable-bitmap");
   m_hash.insert("pgm","image/x-portable-graymap");
   m_hash.insert("ppm","image/x-portable-pixmap");
   m_hash.insert("psd","image/x-psd");
   m_hash.insert("rgb","image/x-rgb");
   m_hash.insert("sgi","image/x-sgi");
   m_hash.insert("sun","image/x-sun-raster");
   m_hash.insert("icb","image/x-tga");
   m_hash.insert("tga","image/x-tga");
   m_hash.insert("tpic","image/x-tga");
   m_hash.insert("vda","image/x-tga");
   m_hash.insert("vst","image/x-tga");
   m_hash.insert("cur","image/x-win-bitmap");
   m_hash.insert("emf","image/x-emf");
   m_hash.insert("wmf","image/x-wmf");
   m_hash.insert("xbm","image/x-xbitmap");
   m_hash.insert("xcf","image/x-xcf");
   m_hash.insert("fig","image/x-xfig");
   m_hash.insert("xpm","image/x-xpixmap");
   m_hash.insert("xwd","image/x-xwindowdump");
   m_hash.insert("wrl","model/vrml");
   m_hash.insert("vcs","text/calendar");
   m_hash.insert("ics","text/calendar");
   m_hash.insert("css","text/css");
   m_hash.insert("CSSL","text/css");
   m_hash.insert("vcf","text/directory");
   m_hash.insert("vct","text/directory");
   m_hash.insert("gcrd","text/directory");
   m_hash.insert("t2t","text/x-txt2tags");
   m_hash.insert("vhd","text/x-vhdl");
   m_hash.insert("vhdl","text/x-vhdl");
   m_hash.insert("mml","text/mathml");
   m_hash.insert("txt","text/plain");
   m_hash.insert("asc","text/plain");
   m_hash.insert("rdf","text/rdf");
   m_hash.insert("rdfs","text/rdf");
   m_hash.insert("owl","text/rdf");
   m_hash.insert("rtx","text/richtext");
   m_hash.insert("rss","application/rss+xml");
   m_hash.insert("atom","application/atom+xml");
   m_hash.insert("opml","text/x-opml+xml");
   m_hash.insert("sgml","text/sgml");
   m_hash.insert("sgm","text/sgml");
   m_hash.insert("sylk","text/spreadsheet");
   m_hash.insert("slk","text/spreadsheet");
   m_hash.insert("tsv","text/tab-separated-values");
   m_hash.insert("jad","text/vnd.sun.j2me.app-descriptor");
   m_hash.insert("wml","text/vnd.wap.wml");
   m_hash.insert("wmls","text/vnd.wap.wmlscript");
   m_hash.insert("ace","application/x-ace");
   m_hash.insert("adb","text/x-adasrc");
   m_hash.insert("ads","text/x-adasrc");
   m_hash.insert("AUTHORS","text/x-authors");
   m_hash.insert("bib","text/x-bibtex");
   m_hash.insert("hh","text/x-c++hdr");
   m_hash.insert("hp","text/x-c++hdr");
   m_hash.insert("hpp","text/x-c++hdr");
   m_hash.insert("h++","text/x-c++hdr");
   m_hash.insert("hxx","text/x-c++hdr");
   m_hash.insert("cpp","text/x-c++src");
   m_hash.insert("cxx","text/x-c++src");
   m_hash.insert("cc","text/x-c++src");
   m_hash.insert("C","text/x-c++src");
   m_hash.insert("c++","text/x-c++src");
   m_hash.insert("ChangeLog","text/x-changelog");
   m_hash.insert("CHANGELOG","text/x-changelog");
   m_hash.insert("h","text/x-chdr");
   m_hash.insert("csv","text/csv");
   m_hash.insert("COPYING","text/x-copying");
   m_hash.insert("CREDITS","text/x-credits");
   m_hash.insert("c","text/x-csrc");
   m_hash.insert("cs","text/x-csharp");
   m_hash.insert("vala","text/x-vala");
   m_hash.insert("dcl","text/x-dcl");
   m_hash.insert("dsl","text/x-dsl");
   m_hash.insert("d","text/x-dsrc");
   m_hash.insert("dtd","text/x-dtd");
   m_hash.insert("el","text/x-emacs-lisp");
   m_hash.insert("erl","text/x-erlang");
   m_hash.insert("for","text/x-fortran");
   m_hash.insert("po","text/x-gettext-translation");
   m_hash.insert("pot","text/x-gettext-translation-template");
   m_hash.insert("html","text/html");
   m_hash.insert("htm","text/html");
   m_hash.insert("gtkrc","text/x-gtkrc");
   m_hash.insert("gtkrc","text/x-gtkrc");
   m_hash.insert("gvp","text/x-google-video-pointer");
   m_hash.insert("hs","text/x-haskell");
   m_hash.insert("idl","text/x-idl");
   m_hash.insert("INSTALL","text/x-install");
   m_hash.insert("java","text/x-java");
   m_hash.insert("ldif","text/x-ldif");
   m_hash.insert("lhs","text/x-literate-haskell");
   m_hash.insert("log","text/x-log");
   m_hash.insert("makefile","text/x-makefile");
   m_hash.insert("Makefile","text/x-makefile");
   m_hash.insert("GNUmakefile","text/x-makefile");
   m_hash.insert("moc","text/x-moc");
   m_hash.insert("mup","text/x-mup");
   m_hash.insert("not","text/x-mup");
   m_hash.insert("m","text/x-objcsrc");
   m_hash.insert("ml","text/x-ocaml");
   m_hash.insert("mli","text/x-ocaml");
   m_hash.insert("m","text/x-matlab");
   m_hash.insert("p","text/x-pascal");
   m_hash.insert("pas","text/x-pascal");
   m_hash.insert("diff","text/x-patch");
   m_hash.insert("patch","text/x-patch");
   m_hash.insert("py","text/x-python");
   m_hash.insert("lua","text/x-lua");
   m_hash.insert("README","text/x-readme");
   m_hash.insert("nfo","text/x-readme");
   m_hash.insert("spec","text/x-rpm-spec");
   m_hash.insert("scm","text/x-scheme");
   m_hash.insert("etx","text/x-setext");
   m_hash.insert("sql","text/x-sql");
   m_hash.insert("tcl","text/x-tcl");
   m_hash.insert("tk","text/x-tcl");
   m_hash.insert("tex","text/x-tex");
   m_hash.insert("ltx","text/x-tex");
   m_hash.insert("sty","text/x-tex");
   m_hash.insert("cls","text/x-tex");
   m_hash.insert("dtx","text/x-tex");
   m_hash.insert("ins","text/x-tex");
   m_hash.insert("latex","text/x-tex");
   m_hash.insert("texi","text/x-texinfo");
   m_hash.insert("texinfo","text/x-texinfo");
   m_hash.insert("me","text/x-troff-me");
   m_hash.insert("mm","text/x-troff-mm");
   m_hash.insert("ms","text/x-troff-ms");
   m_hash.insert("uil","text/x-uil");
   m_hash.insert("uri","text/x-uri");
   m_hash.insert("url","text/x-uri");
   m_hash.insert("xmi","text/x-xmi");
   m_hash.insert("fo","text/x-xslfo");
   m_hash.insert("xslfo","text/x-xslfo");
   m_hash.insert("xml","application/xml");
   m_hash.insert("xsl","application/xml");
   m_hash.insert("xslt","application/xml");
   m_hash.insert("xbl","application/xml");
   m_hash.insert("dv","video/dv");
   m_hash.insert("mpeg","video/mpeg");
   m_hash.insert("mpg","video/mpeg");
   m_hash.insert("mp2","video/mpeg");
   m_hash.insert("mpe","video/mpeg");
   m_hash.insert("vob","video/mpeg");
   m_hash.insert("m2t","video/mpeg");
   m_hash.insert("qt","video/quicktime");
   m_hash.insert("mov","video/quicktime");
   m_hash.insert("moov","video/quicktime");
   m_hash.insert("qtvr","video/quicktime");
   m_hash.insert("qtif","image/x-quicktime");
   m_hash.insert("qif","image/x-quicktime");
   m_hash.insert("viv","video/vivo");
   m_hash.insert("vivo","video/vivo");
   m_hash.insert("fli","video/x-flic");
   m_hash.insert("flc","video/x-flic");
   m_hash.insert("hwp","application/x-hwp");
   m_hash.insert("hwt","application/x-hwt");
   m_hash.insert("mng","video/x-mng");
   m_hash.insert("asf","video/x-ms-asf");
   m_hash.insert("nsc","application/x-netshow-channel");
   m_hash.insert("wmv","video/x-ms-wmv");
   m_hash.insert("avi","video/x-msvideo");
   m_hash.insert("divx","video/x-msvideo");
   m_hash.insert("nsv","video/x-nsv");
   m_hash.insert("sdp","application/sdp");
   m_hash.insert("movie","video/x-sgi-movie");
   m_hash.insert("emp","application/vnd.emusic-emusic_package");
   m_hash.insert("ica","application/x-ica");
   m_hash.insert("xul","application/vnd.mozilla.xul+xml");
   m_hash.insert("602","application/x-t602");
   return m_hash;
}
QHash<QString, QString> MimeData::hash = ff();
MimeData::MimeData()
{
    QFile file(":/freedesktop/freedesktop.js");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream jsStream(&file);
    m_engine.evaluate(jsStream.readAll());
}

QString MimeData::getMimeType(const QString &fileName)
{
    const QString cmd = QString("getMIMEtype(\"%1\")").arg(fileName);
    const QScriptValue res = m_engine.evaluate(cmd);
    if(res.isString())
        return res.toString();
    return "unknown";
}

QString MimeData::getIconMimeType(const QString &fileName)
{
    QString file = getMimeType(fileName);
    file = file.replace("/","-");
    QFileInfo fi = ":/freedesktop/mimetypes/"+file+".png";
    if(!fi.exists())
        return ":/freedesktop/mimetypes/unknown.png";
    return fi.absoluteFilePath();
}
QString MimeData::getIconMimeType(const QFileInfo &fi){
    fi.completeSuffix();
    QString mime = hash.value(fi.completeSuffix(),"");
    if(mime.isEmpty())
        return getIconMimeType(fi.absoluteFilePath());
    mime = mime.replace("/","-");
    QFileInfo mimeFi= ":/freedesktop/mimetypes/"+mime+".png";
    if(!mimeFi.exists())
        return ":/freedesktop/mimetypes/unknown.png";
    return mimeFi.absoluteFilePath();
}
