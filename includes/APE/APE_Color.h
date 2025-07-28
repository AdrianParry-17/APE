#ifndef __APE_COLOR_H__
#define __APE_COLOR_H__

#include "APE_Define.h"

#include <SDL2/SDL_render.h>

namespace APE {
    /// @brief The Color class, represent a 32 bit RGBA color.
    class Color {
    public:
        /// @brief The Red channel of the Color (from range [0->255]).
        uint8_t Red = 0;
        /// @brief The Green channel of the Color (from range [0->255]).
        uint8_t Green = 0;
        /// @brief The Blue channel of the Color (from range [0->255]).
        uint8_t Blue = 0;
        /// @brief The Alpha channel of the Color (from range [0->255]).
        uint8_t Alpha = 0;

        /// @brief Create an empty Color with all channel value are set to 0.
        Color();
        /// @brief Create a new Color with all channel value are the same.
        /// @param rgba The value for all channel of the color.
        Color(uint8_t rgba);
        /// @brief Create a new Color with the red, green, blue channel are the same, and with specific
        /// alpha channel.
        /// @param rgb The value for the red, green and blue channel.
        /// @param a The alpha channel value.
        Color(uint8_t rgb, uint8_t a);
        /// @brief Create a new Color with specific red, green and blue channel (The alpha channel are set
        /// to 255).
        /// @param r The red channel value.
        /// @param g The green channel value.
        /// @param b The blue channel value.
        Color(uint8_t r, uint8_t g, uint8_t b);
        /// @brief Create a new Color with specific red, green, blue and alpha channel value.
        /// @param r The red channel value.
        /// @param g The green channel value.
        /// @param b The blue channel value.
        /// @param a The alpha channel value.
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        /// @brief Create a new Color from the given Color red, green and blue channel value, and the
        /// given alpha channel value.
        /// @param c The Color to get the red, green and blue channel value from.
        /// @param a The alpha channel value.
        Color(const Color& c, uint8_t a);

        Color(const Color& c);

        Color& operator=(uint8_t rgba);
        Color& operator=(const Color& c);

        bool operator==(uint8_t rgba) const;
        bool operator==(const Color& c) const;
        bool operator!=(uint8_t rgba) const;
        bool operator!=(const Color& c) const;

        /// @brief Convert the color to an unsigned 32 bit integer. The color value was stored in the given order:
        /// Red (bit 25->32), Green (bit 17->24), Blue (bit 9->16), Alpha (bit 1->8).
        /// @return The result of the convertion.
        uint32_t ToUint32() const;
		/// @brief Linear interpolation from this color to the given color.
		/// @param target The end color of the interpolation.
		/// @param t The interpolation value, in range [0->1] (if out of range will clamped it).
		/// @return The result of the interpolation.
		Color LerpTo(const Color& target, float t) const;
		/// @brief Lighten the color by the given percentage (similar to lerp
		/// to a solid while color).
		/// @param percent The lighten percentage, in range [0->100] (if out of range will clamped it).
		/// @return The result of the lighten operation.
		Color Lighten(float percent) const;
		/// @brief Darken the color by the given percentage (similar to lerp
		/// to a solid black color).
		/// @param percent The darken percentage, in range [0->100] (if out of range will clamped it).
		/// @return The result of the darken operation.
		Color Darken(float percent) const;

		/// @brief Linear interpolation between two color.
		/// @param a The start color of the interpolation.
		/// @param b The end color of the interpolation.
		/// @param t The interpolation value, in range [0->1] (if out of range will clamped it).
		/// @return The result of the interpolation.
		static Color Lerp(const Color& a, const Color& b, float t);
		/// @brief Create a new Color, but with the given value are from the range [0->1].
		/// @param r The red value of the color, in range [0->1] (if out of range will clamped it).
		/// @param g The green value of the color, in range [0->1] (if out of range will clamped it).
		/// @param b The blue value of the color, in range [0->1] (if out of range will clamped it).
		/// @param a The alpha value of the color, in range [0->1] (if out of range will clamped it).
		/// @return The new created Color.
		static Color From01(float r, float g, float b, float a);

		/// @brief The Empty Color with all channel are set to 0.
		static const Color Empty;
	};;

    /// @brief The Known Color static class, contain the known color.
    class KnownColor final {
    public:
		/// @brief The Absolute Zero color, RGB value are 0, 72, 186.
		static const Color AbsoluteZero;
		/// @brief The Acid Green color, RGB value are 176, 191, 26.
		static const Color AcidGreen;
		/// @brief The Aero color, RGB value are 124, 185, 232.
		static const Color Aero;
		/// @brief The African Violet color, RGB value are 178, 132, 190.
		static const Color AfricanViolet;
		/// @brief The Air Superiority Blue color, RGB value are 114, 160, 193.
		static const Color AirSuperiorityBlue;
		/// @brief The Alice Blue color, RGB value are 240, 248, 255.
		static const Color AliceBlue;
		/// @brief The Alizarin color, RGB value are 219, 45, 67.
		static const Color Alizarin;
		/// @brief The Alloy Orange color, RGB value are 196, 98, 16.
		static const Color AlloyOrange;
		/// @brief The Almond color, RGB value are 239, 222, 205.
		static const Color Almond;
		/// @brief The Amaranth Deep Purple color, RGB value are 159, 43, 104.
		static const Color AmaranthDeepPurple;
		/// @brief The Amaranth Pink color, RGB value are 241, 156, 187.
		static const Color AmaranthPink;
		/// @brief The Amaranth Purple color, RGB value are 171, 39, 79.
		static const Color AmaranthPurple;
		/// @brief The Amazon color, RGB value are 59, 122, 87.
		static const Color Amazon;
		/// @brief The Amber color, RGB value are 255, 191, 0.
		static const Color Amber;
		/// @brief The Amethyst color, RGB value are 153, 102, 204.
		static const Color Amethyst;
		/// @brief The Android Green color, RGB value are 61, 220, 132.
		static const Color AndroidGreen;
		/// @brief The Antique Brass color, RGB value are 205, 149, 117.
		static const Color AntiqueBrass;
		/// @brief The Antique Bronze color, RGB value are 102, 93, 30.
		static const Color AntiqueBronze;
		/// @brief The Antique Fuchsia color, RGB value are 145, 92, 131.
		static const Color AntiqueFuchsia;
		/// @brief The Antique Ruby color, RGB value are 132, 27, 45.
		static const Color AntiqueRuby;
		/// @brief The Antique White color, RGB value are 250, 235, 215.
		static const Color AntiqueWhite;
		/// @brief The Apricot color, RGB value are 251, 206, 177.
		static const Color Apricot;
		/// @brief The Aqua color, RGB value are 0, 255, 255.
		static const Color Aqua;
		/// @brief The Aquamarine color, RGB value are 127, 255, 212.
		static const Color Aquamarine;
		/// @brief The Arctic Lime color, RGB value are 208, 255, 20.
		static const Color ArcticLime;
		/// @brief The Artichoke Green color, RGB value are 75, 111, 68.
		static const Color ArtichokeGreen;
		/// @brief The Arylide Yellow color, RGB value are 233, 214, 107.
		static const Color ArylideYellow;
		/// @brief The Ash Gray color, RGB value are 178, 190, 181.
		static const Color AshGray;
		/// @brief The Atomic Tangerine color, RGB value are 255, 153, 102.
		static const Color AtomicTangerine;
		/// @brief The Aureolin color, RGB value are 253, 238, 0.
		static const Color Aureolin;
		/// @brief The Azure color, RGB value are 0, 127, 255.
		static const Color Azure;
		/// @brief The Azure X11 Web Color color, RGB value are 240, 255, 255.
		static const Color AzureX11WebColor;
		/// @brief The Baby Blue color, RGB value are 137, 207, 240.
		static const Color BabyBlue;
		/// @brief The Baby Blue Eyes color, RGB value are 161, 202, 241.
		static const Color BabyBlueEyes;
		/// @brief The Baby Pink color, RGB value are 244, 194, 194.
		static const Color BabyPink;
		/// @brief The Baby Powder color, RGB value are 254, 254, 250.
		static const Color BabyPowder;
		/// @brief The Baker Miller Pink color, RGB value are 255, 145, 175.
		static const Color BakerMillerPink;
		/// @brief The Banana Mania color, RGB value are 250, 231, 181.
		static const Color BananaMania;
		/// @brief The Barbie Pink color, RGB value are 218, 24, 132.
		static const Color BarbiePink;
		/// @brief The Barn Red color, RGB value are 124, 10, 2.
		static const Color BarnRed;
		/// @brief The Battleship Grey color, RGB value are 132, 132, 130.
		static const Color BattleshipGrey;
		/// @brief The Beau Blue color, RGB value are 188, 212, 230.
		static const Color BeauBlue;
		/// @brief The Beaver color, RGB value are 159, 129, 112.
		static const Color Beaver;
		/// @brief The Beige color, RGB value are 245, 245, 220.
		static const Color Beige;
		/// @brief The B Dazzled Blue color, RGB value are 46, 88, 148.
		static const Color BDazzledBlue;
		/// @brief The Big Dip O Ruby color, RGB value are 156, 37, 66.
		static const Color BigDipORuby;
		/// @brief The Bisque color, RGB value are 255, 228, 196.
		static const Color Bisque;
		/// @brief The Bistre color, RGB value are 61, 43, 31.
		static const Color Bistre;
		/// @brief The Bistre Brown color, RGB value are 150, 113, 23.
		static const Color BistreBrown;
		/// @brief The Bitter Lemon color, RGB value are 202, 224, 13.
		static const Color BitterLemon;
		/// @brief The Black color, RGB value are 0, 0, 0.
		static const Color Black;
		/// @brief The Black Bean color, RGB value are 61, 12, 2.
		static const Color BlackBean;
		/// @brief The Black Coral color, RGB value are 84, 98, 111.
		static const Color BlackCoral;
		/// @brief The Black Olive color, RGB value are 59, 60, 54.
		static const Color BlackOlive;
		/// @brief The Black Shadows color, RGB value are 191, 175, 178.
		static const Color BlackShadows;
		/// @brief The Blanched Almond color, RGB value are 255, 235, 205.
		static const Color BlanchedAlmond;
		/// @brief The Blast Off Bronze color, RGB value are 165, 113, 100.
		static const Color BlastOffBronze;
		/// @brief The Bleu De France color, RGB value are 49, 140, 231.
		static const Color BleuDeFrance;
		/// @brief The Blizzard Blue color, RGB value are 172, 229, 238.
		static const Color BlizzardBlue;
		/// @brief The Blood Red color, RGB value are 102, 0, 0.
		static const Color BloodRed;
		/// @brief The Blue color, RGB value are 0, 0, 255.
		static const Color Blue;
		/// @brief The Blue Crayola color, RGB value are 31, 117, 254.
		static const Color BlueCrayola;
		/// @brief The Blue Munsell color, RGB value are 0, 147, 175.
		static const Color BlueMunsell;
		/// @brief The Blue Ncs color, RGB value are 0, 135, 189.
		static const Color BlueNcs;
		/// @brief The Blue Pantone color, RGB value are 0, 24, 168.
		static const Color BluePantone;
		/// @brief The Blue Pigment color, RGB value are 51, 51, 153.
		static const Color BluePigment;
		/// @brief The Blue Bell color, RGB value are 162, 162, 208.
		static const Color BlueBell;
		/// @brief The Blue Gray Crayola color, RGB value are 102, 153, 204.
		static const Color BlueGrayCrayola;
		/// @brief The Blue Jeans color, RGB value are 93, 173, 236.
		static const Color BlueJeans;
		/// @brief The Blue Sapphire color, RGB value are 18, 97, 128.
		static const Color BlueSapphire;
		/// @brief The Blue Violet color, RGB value are 138, 43, 226.
		static const Color BlueViolet;
		/// @brief The Blue Yonder color, RGB value are 80, 114, 167.
		static const Color BlueYonder;
		/// @brief The Bluetiful color, RGB value are 60, 105, 231.
		static const Color Bluetiful;
		/// @brief The Blush color, RGB value are 222, 93, 131.
		static const Color Blush;
		/// @brief The Bole color, RGB value are 121, 68, 59.
		static const Color Bole;
		/// @brief The Bone color, RGB value are 227, 218, 201.
		static const Color Bone;
		/// @brief The Brick Red color, RGB value are 203, 65, 84.
		static const Color BrickRed;
		/// @brief The Bright Lilac color, RGB value are 216, 145, 239.
		static const Color BrightLilac;
		/// @brief The Bright Yellow Crayola color, RGB value are 255, 170, 29.
		static const Color BrightYellowCrayola;
		/// @brief The Bronze color, RGB value are 205, 127, 50.
		static const Color Bronze;
		/// @brief The Brown color, RGB value are 136, 84, 11.
		static const Color Brown;
		/// @brief The Brown Sugar color, RGB value are 175, 110, 77.
		static const Color BrownSugar;
		/// @brief The Bud Green color, RGB value are 123, 182, 97.
		static const Color BudGreen;
		/// @brief The Buff color, RGB value are 255, 198, 128.
		static const Color Buff;
		/// @brief The Burgundy color, RGB value are 128, 0, 32.
		static const Color Burgundy;
		/// @brief The Burlywood color, RGB value are 222, 184, 135.
		static const Color Burlywood;
		/// @brief The Burnished Brown color, RGB value are 161, 122, 116.
		static const Color BurnishedBrown;
		/// @brief The Burnt Orange color, RGB value are 204, 85, 0.
		static const Color BurntOrange;
		/// @brief The Burnt Sienna color, RGB value are 233, 116, 81.
		static const Color BurntSienna;
		/// @brief The Burnt Umber color, RGB value are 138, 51, 36.
		static const Color BurntUmber;
		/// @brief The Byzantine color, RGB value are 189, 51, 164.
		static const Color Byzantine;
		/// @brief The Byzantium color, RGB value are 112, 41, 99.
		static const Color Byzantium;
		/// @brief The Cadet Blue color, RGB value are 95, 158, 160.
		static const Color CadetBlue;
		/// @brief The Cadet Grey color, RGB value are 145, 163, 176.
		static const Color CadetGrey;
		/// @brief The Cadmium Green color, RGB value are 0, 107, 60.
		static const Color CadmiumGreen;
		/// @brief The Cadmium Orange color, RGB value are 237, 135, 45.
		static const Color CadmiumOrange;
		/// @brief The Cafe Au Lait color, RGB value are 166, 123, 91.
		static const Color CafeAuLait;
		/// @brief The Cafe Noir color, RGB value are 75, 54, 33.
		static const Color CafeNoir;
		/// @brief The Cambridge Blue color, RGB value are 163, 193, 173.
		static const Color CambridgeBlue;
		/// @brief The Camel color, RGB value are 193, 154, 107.
		static const Color Camel;
		/// @brief The Cameo Pink color, RGB value are 239, 187, 204.
		static const Color CameoPink;
		/// @brief The Canary color, RGB value are 255, 255, 153.
		static const Color Canary;
		/// @brief The Canary Yellow color, RGB value are 255, 239, 0.
		static const Color CanaryYellow;
		/// @brief The Candy Pink color, RGB value are 228, 113, 122.
		static const Color CandyPink;
		/// @brief The Cardinal color, RGB value are 196, 30, 58.
		static const Color Cardinal;
		/// @brief The Caribbean Green color, RGB value are 0, 204, 153.
		static const Color CaribbeanGreen;
		/// @brief The Carmine color, RGB value are 150, 0, 24.
		static const Color Carmine;
		/// @brief The Carmine M P color, RGB value are 215, 0, 64.
		static const Color CarmineMP;
		/// @brief The Carnation Pink color, RGB value are 255, 166, 201.
		static const Color CarnationPink;
		/// @brief The Carnelian color, RGB value are 179, 27, 27.
		static const Color Carnelian;
		/// @brief The Carolina Blue color, RGB value are 86, 160, 211.
		static const Color CarolinaBlue;
		/// @brief The Carrot Orange color, RGB value are 237, 145, 33.
		static const Color CarrotOrange;
		/// @brief The Catawba color, RGB value are 112, 54, 66.
		static const Color Catawba;
		/// @brief The Cedar Chest color, RGB value are 201, 90, 73.
		static const Color CedarChest;
		/// @brief The Celadon color, RGB value are 172, 225, 175.
		static const Color Celadon;
		/// @brief The Celeste color, RGB value are 178, 255, 255.
		static const Color Celeste;
		/// @brief The Cerise color, RGB value are 222, 49, 99.
		static const Color Cerise;
		/// @brief The Cerulean color, RGB value are 0, 123, 167.
		static const Color Cerulean;
		/// @brief The Cerulean Blue color, RGB value are 42, 82, 190.
		static const Color CeruleanBlue;
		/// @brief The Cerulean Frost color, RGB value are 109, 155, 195.
		static const Color CeruleanFrost;
		/// @brief The Cerulean Crayola color, RGB value are 29, 172, 214.
		static const Color CeruleanCrayola;
		/// @brief The Cerulean Rgb color, RGB value are 0, 64, 255.
		static const Color CeruleanRgb;
		/// @brief The Champagne color, RGB value are 247, 231, 206.
		static const Color Champagne;
		/// @brief The Champagne Pink color, RGB value are 241, 221, 207.
		static const Color ChampagnePink;
		/// @brief The Charcoal color, RGB value are 54, 69, 79.
		static const Color Charcoal;
		/// @brief The Charm Pink color, RGB value are 230, 143, 172.
		static const Color CharmPink;
		/// @brief The Chartreuse Web color, RGB value are 128, 255, 0.
		static const Color ChartreuseWeb;
		/// @brief The Cherry Blossom Pink color, RGB value are 255, 183, 197.
		static const Color CherryBlossomPink;
		/// @brief The Chestnut color, RGB value are 149, 69, 53.
		static const Color Chestnut;
		/// @brief The Chili Red color, RGB value are 226, 61, 40.
		static const Color ChiliRed;
		/// @brief The China Pink color, RGB value are 222, 111, 161.
		static const Color ChinaPink;
		/// @brief The Chinese Red color, RGB value are 170, 56, 30.
		static const Color ChineseRed;
		/// @brief The Chinese Violet color, RGB value are 133, 96, 136.
		static const Color ChineseViolet;
		/// @brief The Chinese Yellow color, RGB value are 255, 178, 0.
		static const Color ChineseYellow;
		/// @brief The Chocolate Traditional color, RGB value are 123, 63, 0.
		static const Color ChocolateTraditional;
		/// @brief The Chocolate Web color, RGB value are 210, 105, 30.
		static const Color ChocolateWeb;
		/// @brief The Cinereous color, RGB value are 152, 129, 123.
		static const Color Cinereous;
		/// @brief The Cinnabar color, RGB value are 227, 66, 52.
		static const Color Cinnabar;
		/// @brief The Cinnamon Satin color, RGB value are 205, 96, 126.
		static const Color CinnamonSatin;
		/// @brief The Citrine color, RGB value are 228, 208, 10.
		static const Color Citrine;
		/// @brief The Citron color, RGB value are 159, 169, 31.
		static const Color Citron;
		/// @brief The Claret color, RGB value are 127, 23, 52.
		static const Color Claret;
		/// @brief The Coffee color, RGB value are 111, 78, 55.
		static const Color Coffee;
		/// @brief The Columbia Blue color, RGB value are 185, 217, 235.
		static const Color ColumbiaBlue;
		/// @brief The Congo Pink color, RGB value are 248, 131, 121.
		static const Color CongoPink;
		/// @brief The Cool Grey color, RGB value are 140, 146, 172.
		static const Color CoolGrey;
		/// @brief The Copper color, RGB value are 184, 115, 51.
		static const Color Copper;
		/// @brief The Copper Crayola color, RGB value are 218, 138, 103.
		static const Color CopperCrayola;
		/// @brief The Copper Penny color, RGB value are 173, 111, 105.
		static const Color CopperPenny;
		/// @brief The Copper Red color, RGB value are 203, 109, 81.
		static const Color CopperRed;
		/// @brief The Copper Rose color, RGB value are 153, 102, 102.
		static const Color CopperRose;
		/// @brief The Coquelicot color, RGB value are 255, 56, 0.
		static const Color Coquelicot;
		/// @brief The Coral color, RGB value are 255, 127, 80.
		static const Color Coral;
		/// @brief The Coral Pink color, RGB value are 248, 131, 121.
		static const Color CoralPink;
		/// @brief The Cordovan color, RGB value are 137, 63, 69.
		static const Color Cordovan;
		/// @brief The Corn color, RGB value are 251, 236, 93.
		static const Color Corn;
		/// @brief The Cornflower Blue color, RGB value are 100, 149, 237.
		static const Color CornflowerBlue;
		/// @brief The Cornsilk color, RGB value are 255, 248, 220.
		static const Color Cornsilk;
		/// @brief The Cosmic Cobalt color, RGB value are 46, 45, 136.
		static const Color CosmicCobalt;
		/// @brief The Cosmic Latte color, RGB value are 255, 248, 231.
		static const Color CosmicLatte;
		/// @brief The Coyote Brown color, RGB value are 129, 97, 60.
		static const Color CoyoteBrown;
		/// @brief The Cotton Candy color, RGB value are 255, 188, 217.
		static const Color CottonCandy;
		/// @brief The Cream color, RGB value are 255, 253, 208.
		static const Color Cream;
		/// @brief The Crimson color, RGB value are 220, 20, 60.
		static const Color Crimson;
		/// @brief The Crimson Ua color, RGB value are 158, 27, 50.
		static const Color CrimsonUa;
		/// @brief The Cultured Pearl color, RGB value are 245, 245, 245.
		static const Color CulturedPearl;
		/// @brief The Cyan color, RGB value are 0, 255, 255.
		static const Color Cyan;
		/// @brief The Cyan Process color, RGB value are 0, 183, 235.
		static const Color CyanProcess;
		/// @brief The Cyber Grape color, RGB value are 88, 66, 124.
		static const Color CyberGrape;
		/// @brief The Cyber Yellow color, RGB value are 255, 211, 0.
		static const Color CyberYellow;
		/// @brief The Cyclamen color, RGB value are 245, 111, 161.
		static const Color Cyclamen;
		/// @brief The Dandelion color, RGB value are 254, 216, 93.
		static const Color Dandelion;
		/// @brief The Dark Brown color, RGB value are 101, 67, 33.
		static const Color DarkBrown;
		/// @brief The Dark Byzantium color, RGB value are 93, 57, 84.
		static const Color DarkByzantium;
		/// @brief The Dark Cyan color, RGB value are 0, 139, 139.
		static const Color DarkCyan;
		/// @brief The Dark Electric Blue color, RGB value are 83, 104, 120.
		static const Color DarkElectricBlue;
		/// @brief The Dark Goldenrod color, RGB value are 184, 134, 11.
		static const Color DarkGoldenrod;
		/// @brief The Dark Green X11 color, RGB value are 0, 100, 0.
		static const Color DarkGreenX11;
		/// @brief The Dark Jungle Green color, RGB value are 26, 36, 33.
		static const Color DarkJungleGreen;
		/// @brief The Dark Khaki color, RGB value are 189, 183, 107.
		static const Color DarkKhaki;
		/// @brief The Dark Lava color, RGB value are 72, 60, 50.
		static const Color DarkLava;
		/// @brief The Dark Liver Horses color, RGB value are 84, 61, 55.
		static const Color DarkLiverHorses;
		/// @brief The Dark Magenta color, RGB value are 139, 0, 139.
		static const Color DarkMagenta;
		/// @brief The Dark Olive Green color, RGB value are 85, 107, 47.
		static const Color DarkOliveGreen;
		/// @brief The Dark Orange color, RGB value are 255, 140, 0.
		static const Color DarkOrange;
		/// @brief The Dark Orchid color, RGB value are 153, 50, 204.
		static const Color DarkOrchid;
		/// @brief The Dark Purple color, RGB value are 48, 25, 52.
		static const Color DarkPurple;
		/// @brief The Dark Red color, RGB value are 139, 0, 0.
		static const Color DarkRed;
		/// @brief The Dark Salmon color, RGB value are 233, 150, 122.
		static const Color DarkSalmon;
		/// @brief The Dark Sea Green color, RGB value are 143, 188, 143.
		static const Color DarkSeaGreen;
		/// @brief The Dark Sienna color, RGB value are 60, 20, 20.
		static const Color DarkSienna;
		/// @brief The Dark Sky Blue color, RGB value are 140, 190, 214.
		static const Color DarkSkyBlue;
		/// @brief The Dark Slate Blue color, RGB value are 72, 61, 139.
		static const Color DarkSlateBlue;
		/// @brief The Dark Slate Gray color, RGB value are 47, 79, 79.
		static const Color DarkSlateGray;
		/// @brief The Dark Spring Green color, RGB value are 23, 114, 69.
		static const Color DarkSpringGreen;
		/// @brief The Dark Turquoise color, RGB value are 0, 206, 209.
		static const Color DarkTurquoise;
		/// @brief The Dark Violet color, RGB value are 148, 0, 211.
		static const Color DarkViolet;
		/// @brief The Davy S Grey color, RGB value are 85, 85, 85.
		static const Color DavySGrey;
		/// @brief The Deep Cerise color, RGB value are 218, 50, 135.
		static const Color DeepCerise;
		/// @brief The Deep Champagne color, RGB value are 250, 214, 165.
		static const Color DeepChampagne;
		/// @brief The Deep Chestnut color, RGB value are 185, 78, 72.
		static const Color DeepChestnut;
		/// @brief The Deep Jungle Green color, RGB value are 0, 75, 73.
		static const Color DeepJungleGreen;
		/// @brief The Deep Pink color, RGB value are 255, 20, 147.
		static const Color DeepPink;
		/// @brief The Deep Saffron color, RGB value are 255, 153, 51.
		static const Color DeepSaffron;
		/// @brief The Deep Sky Blue color, RGB value are 0, 191, 255.
		static const Color DeepSkyBlue;
		/// @brief The Deep Space Sparkle color, RGB value are 74, 100, 108.
		static const Color DeepSpaceSparkle;
		/// @brief The Deep Taupe color, RGB value are 126, 94, 96.
		static const Color DeepTaupe;
		/// @brief The Denim color, RGB value are 21, 96, 189.
		static const Color Denim;
		/// @brief The Denim Blue color, RGB value are 34, 67, 182.
		static const Color DenimBlue;
		/// @brief The Desert color, RGB value are 193, 154, 107.
		static const Color Desert;
		/// @brief The Desert Sand color, RGB value are 237, 201, 175.
		static const Color DesertSand;
		/// @brief The Dim Gray color, RGB value are 105, 105, 105.
		static const Color DimGray;
		/// @brief The Dodger Blue color, RGB value are 30, 144, 255.
		static const Color DodgerBlue;
		/// @brief The Drab Dark Brown color, RGB value are 74, 65, 42.
		static const Color DrabDarkBrown;
		/// @brief The Duke Blue color, RGB value are 0, 0, 156.
		static const Color DukeBlue;
		/// @brief The Dutch White color, RGB value are 239, 223, 187.
		static const Color DutchWhite;
		/// @brief The Ebony color, RGB value are 85, 93, 80.
		static const Color Ebony;
		/// @brief The Ecru color, RGB value are 194, 178, 128.
		static const Color Ecru;
		/// @brief The Eerie Black color, RGB value are 27, 27, 27.
		static const Color EerieBlack;
		/// @brief The Eggplant color, RGB value are 97, 64, 81.
		static const Color Eggplant;
		/// @brief The Eggshell color, RGB value are 240, 234, 214.
		static const Color Eggshell;
		/// @brief The Electric Lime color, RGB value are 204, 255, 0.
		static const Color ElectricLime;
		/// @brief The Electric Purple color, RGB value are 191, 0, 255.
		static const Color ElectricPurple;
		/// @brief The Electric Violet color, RGB value are 143, 0, 255.
		static const Color ElectricViolet;
		/// @brief The Emerald color, RGB value are 80, 200, 120.
		static const Color Emerald;
		/// @brief The Eminence color, RGB value are 108, 48, 130.
		static const Color Eminence;
		/// @brief The English Lavender color, RGB value are 180, 131, 149.
		static const Color EnglishLavender;
		/// @brief The English Red color, RGB value are 171, 75, 82.
		static const Color EnglishRed;
		/// @brief The English Vermillion color, RGB value are 204, 71, 75.
		static const Color EnglishVermillion;
		/// @brief The English Violet color, RGB value are 86, 60, 92.
		static const Color EnglishViolet;
		/// @brief The Erin color, RGB value are 0, 255, 64.
		static const Color Erin;
		/// @brief The Eton Blue color, RGB value are 150, 200, 162.
		static const Color EtonBlue;
		/// @brief The Fallow color, RGB value are 193, 154, 107.
		static const Color Fallow;
		/// @brief The Falu Red color, RGB value are 128, 24, 24.
		static const Color FaluRed;
		/// @brief The Fandango color, RGB value are 181, 51, 137.
		static const Color Fandango;
		/// @brief The Fandango Pink color, RGB value are 222, 82, 133.
		static const Color FandangoPink;
		/// @brief The Fawn color, RGB value are 229, 170, 112.
		static const Color Fawn;
		/// @brief The Fern Green color, RGB value are 79, 121, 66.
		static const Color FernGreen;
		/// @brief The Field Drab color, RGB value are 108, 84, 30.
		static const Color FieldDrab;
		/// @brief The Fiery Rose color, RGB value are 255, 84, 112.
		static const Color FieryRose;
		/// @brief The Finn color, RGB value are 104, 48, 104.
		static const Color Finn;
		/// @brief The Firebrick color, RGB value are 178, 34, 34.
		static const Color Firebrick;
		/// @brief The Fire Engine Red color, RGB value are 206, 32, 41.
		static const Color FireEngineRed;
		/// @brief The Flame color, RGB value are 226, 88, 34.
		static const Color Flame;
		/// @brief The Flax color, RGB value are 238, 220, 130.
		static const Color Flax;
		/// @brief The Flirt color, RGB value are 162, 0, 109.
		static const Color Flirt;
		/// @brief The Floral White color, RGB value are 255, 250, 240.
		static const Color FloralWhite;
		/// @brief The Forest Green Web color, RGB value are 34, 139, 34.
		static const Color ForestGreenWeb;
		/// @brief The French Beige color, RGB value are 166, 123, 91.
		static const Color FrenchBeige;
		/// @brief The French Bistre color, RGB value are 133, 109, 77.
		static const Color FrenchBistre;
		/// @brief The French Blue color, RGB value are 0, 114, 187.
		static const Color FrenchBlue;
		/// @brief The French Fuchsia color, RGB value are 253, 63, 146.
		static const Color FrenchFuchsia;
		/// @brief The French Lilac color, RGB value are 134, 96, 142.
		static const Color FrenchLilac;
		/// @brief The French Lime color, RGB value are 158, 253, 56.
		static const Color FrenchLime;
		/// @brief The French Mauve color, RGB value are 212, 115, 212.
		static const Color FrenchMauve;
		/// @brief The French Pink color, RGB value are 253, 108, 158.
		static const Color FrenchPink;
		/// @brief The French Raspberry color, RGB value are 199, 44, 72.
		static const Color FrenchRaspberry;
		/// @brief The French Sky Blue color, RGB value are 119, 181, 254.
		static const Color FrenchSkyBlue;
		/// @brief The French Violet color, RGB value are 136, 6, 206.
		static const Color FrenchViolet;
		/// @brief The Frostbite color, RGB value are 233, 54, 167.
		static const Color Frostbite;
		/// @brief The Fuchsia color, RGB value are 255, 0, 255.
		static const Color Fuchsia;
		/// @brief The Fuchsia Crayola color, RGB value are 193, 84, 193.
		static const Color FuchsiaCrayola;
		/// @brief The Fulvous color, RGB value are 228, 132, 0.
		static const Color Fulvous;
		/// @brief The Fuzzy Wuzzy color, RGB value are 135, 66, 31.
		static const Color FuzzyWuzzy;
		/// @brief The Gainsboro color, RGB value are 220, 220, 220.
		static const Color Gainsboro;
		/// @brief The Gamboge color, RGB value are 228, 155, 15.
		static const Color Gamboge;
		/// @brief The Generic Viridian color, RGB value are 0, 127, 102.
		static const Color GenericViridian;
		/// @brief The Ghost White color, RGB value are 248, 248, 255.
		static const Color GhostWhite;
		/// @brief The Glaucous color, RGB value are 96, 130, 182.
		static const Color Glaucous;
		/// @brief The Glossy Grape color, RGB value are 171, 146, 179.
		static const Color GlossyGrape;
		/// @brief The Go Green color, RGB value are 0, 171, 102.
		static const Color GoGreen;
		/// @brief The Gold Metallic color, RGB value are 212, 175, 55.
		static const Color GoldMetallic;
		/// @brief The Gold Web Golden color, RGB value are 255, 215, 0.
		static const Color GoldWebGolden;
		/// @brief The Gold Crayola color, RGB value are 230, 190, 138.
		static const Color GoldCrayola;
		/// @brief The Gold Fusion color, RGB value are 133, 117, 78.
		static const Color GoldFusion;
		/// @brief The Golden Brown color, RGB value are 153, 101, 21.
		static const Color GoldenBrown;
		/// @brief The Golden Poppy color, RGB value are 252, 194, 0.
		static const Color GoldenPoppy;
		/// @brief The Golden Yellow color, RGB value are 255, 223, 0.
		static const Color GoldenYellow;
		/// @brief The Goldenrod color, RGB value are 218, 165, 32.
		static const Color Goldenrod;
		/// @brief The Gotham Green color, RGB value are 0, 87, 63.
		static const Color GothamGreen;
		/// @brief The Granite Gray color, RGB value are 103, 103, 103.
		static const Color GraniteGray;
		/// @brief The Granny Smith Apple color, RGB value are 168, 228, 160.
		static const Color GrannySmithApple;
		/// @brief The Gray Web color, RGB value are 128, 128, 128.
		static const Color GrayWeb;
		/// @brief The Gray X11 Gray color, RGB value are 190, 190, 190.
		static const Color GrayX11Gray;
		/// @brief The Green color, RGB value are 0, 255, 0.
		static const Color Green;
		/// @brief The Green Crayola color, RGB value are 28, 172, 120.
		static const Color GreenCrayola;
		/// @brief The Green Web color, RGB value are 0, 128, 0.
		static const Color GreenWeb;
		/// @brief The Green Munsell color, RGB value are 0, 168, 119.
		static const Color GreenMunsell;
		/// @brief The Green Ncs color, RGB value are 0, 159, 107.
		static const Color GreenNcs;
		/// @brief The Green Pantone color, RGB value are 0, 173, 67.
		static const Color GreenPantone;
		/// @brief The Green Pigment color, RGB value are 0, 165, 80.
		static const Color GreenPigment;
		/// @brief The Green Blue color, RGB value are 17, 100, 180.
		static const Color GreenBlue;
		/// @brief The Green Lizard color, RGB value are 167, 244, 50.
		static const Color GreenLizard;
		/// @brief The Green Sheen color, RGB value are 110, 174, 161.
		static const Color GreenSheen;
		/// @brief The Gunmetal color, RGB value are 42, 52, 57.
		static const Color Gunmetal;
		/// @brief The Hansa Yellow color, RGB value are 233, 214, 107.
		static const Color HansaYellow;
		/// @brief The Harlequin color, RGB value are 63, 255, 0.
		static const Color Harlequin;
		/// @brief The Harvest Gold color, RGB value are 218, 145, 0.
		static const Color HarvestGold;
		/// @brief The Heat Wave color, RGB value are 255, 122, 0.
		static const Color HeatWave;
		/// @brief The Heliotrope color, RGB value are 223, 115, 255.
		static const Color Heliotrope;
		/// @brief The Heliotrope Gray color, RGB value are 170, 152, 169.
		static const Color HeliotropeGray;
		/// @brief The Hollywood Cerise color, RGB value are 244, 0, 161.
		static const Color HollywoodCerise;
		/// @brief The Honolulu Blue color, RGB value are 0, 109, 176.
		static const Color HonoluluBlue;
		/// @brief The Hooker S Green color, RGB value are 73, 121, 107.
		static const Color HookerSGreen;
		/// @brief The Hot Magenta color, RGB value are 255, 29, 206.
		static const Color HotMagenta;
		/// @brief The Hot Pink color, RGB value are 255, 105, 180.
		static const Color HotPink;
		/// @brief The Hunter Green color, RGB value are 53, 94, 59.
		static const Color HunterGreen;
		/// @brief The Iceberg color, RGB value are 113, 166, 210.
		static const Color Iceberg;
		/// @brief The Illuminating Emerald color, RGB value are 49, 145, 119.
		static const Color IlluminatingEmerald;
		/// @brief The Imperial Red color, RGB value are 237, 41, 57.
		static const Color ImperialRed;
		/// @brief The Inchworm color, RGB value are 178, 236, 93.
		static const Color Inchworm;
		/// @brief The Independence color, RGB value are 76, 81, 109.
		static const Color Independence;
		/// @brief The India Green color, RGB value are 19, 136, 8.
		static const Color IndiaGreen;
		/// @brief The Indian Red color, RGB value are 205, 92, 92.
		static const Color IndianRed;
		/// @brief The Indian Yellow color, RGB value are 227, 168, 87.
		static const Color IndianYellow;
		/// @brief The Indigo color, RGB value are 75, 0, 130.
		static const Color Indigo;
		/// @brief The Indigo Dye color, RGB value are 0, 65, 106.
		static const Color IndigoDye;
		/// @brief The International Klein Blue color, RGB value are 19, 10, 143.
		static const Color InternationalKleinBlue;
		/// @brief The International Orange Engineering color, RGB value are 186, 22, 12.
		static const Color InternationalOrangeEngineering;
		/// @brief The International Orange Golden Gate Bridge color, RGB value are 192, 54, 44.
		static const Color InternationalOrangeGoldenGateBridge;
		/// @brief The Irresistible color, RGB value are 179, 68, 108.
		static const Color Irresistible;
		/// @brief The Isabelline color, RGB value are 244, 240, 236.
		static const Color Isabelline;
		/// @brief The Italian Sky Blue color, RGB value are 178, 255, 255.
		static const Color ItalianSkyBlue;
		/// @brief The Ivory color, RGB value are 255, 255, 240.
		static const Color Ivory;
		/// @brief The Japanese Carmine color, RGB value are 157, 41, 51.
		static const Color JapaneseCarmine;
		/// @brief The Japanese Violet color, RGB value are 91, 50, 86.
		static const Color JapaneseViolet;
		/// @brief The Jasmine color, RGB value are 248, 222, 126.
		static const Color Jasmine;
		/// @brief The Jazzberry Jam color, RGB value are 165, 11, 94.
		static const Color JazzberryJam;
		/// @brief The Jet color, RGB value are 52, 52, 52.
		static const Color Jet;
		/// @brief The Jonquil color, RGB value are 244, 202, 22.
		static const Color Jonquil;
		/// @brief The June Bud color, RGB value are 189, 218, 87.
		static const Color JuneBud;
		/// @brief The Jungle Green color, RGB value are 41, 171, 135.
		static const Color JungleGreen;
		/// @brief The Kelly Green color, RGB value are 76, 187, 23.
		static const Color KellyGreen;
		/// @brief The Keppel color, RGB value are 58, 176, 158.
		static const Color Keppel;
		/// @brief The Key Lime color, RGB value are 232, 244, 140.
		static const Color KeyLime;
		/// @brief The Khaki Web color, RGB value are 195, 176, 145.
		static const Color KhakiWeb;
		/// @brief The Khaki X11 Light Khaki color, RGB value are 240, 230, 140.
		static const Color KhakiX11LightKhaki;
		/// @brief The Kobe color, RGB value are 136, 45, 23.
		static const Color Kobe;
		/// @brief The Kobi color, RGB value are 231, 159, 196.
		static const Color Kobi;
		/// @brief The Kobicha color, RGB value are 107, 68, 35.
		static const Color Kobicha;
		/// @brief The Ksu Purple color, RGB value are 81, 40, 136.
		static const Color KsuPurple;
		/// @brief The Languid Lavender color, RGB value are 214, 202, 221.
		static const Color LanguidLavender;
		/// @brief The Lapis Lazuli color, RGB value are 38, 97, 156.
		static const Color LapisLazuli;
		/// @brief The Laser Lemon color, RGB value are 255, 255, 102.
		static const Color LaserLemon;
		/// @brief The Laurel Green color, RGB value are 169, 186, 157.
		static const Color LaurelGreen;
		/// @brief The Lava color, RGB value are 207, 16, 32.
		static const Color Lava;
		/// @brief The Lavender Floral color, RGB value are 181, 126, 220.
		static const Color LavenderFloral;
		/// @brief The Lavender Web color, RGB value are 230, 230, 250.
		static const Color LavenderWeb;
		/// @brief The Lavender Blue color, RGB value are 204, 204, 255.
		static const Color LavenderBlue;
		/// @brief The Lavender Blush color, RGB value are 255, 240, 245.
		static const Color LavenderBlush;
		/// @brief The Lavender Gray color, RGB value are 196, 195, 208.
		static const Color LavenderGray;
		/// @brief The Lawn Green color, RGB value are 124, 252, 0.
		static const Color LawnGreen;
		/// @brief The Lemon color, RGB value are 255, 247, 0.
		static const Color Lemon;
		/// @brief The Lemon Chiffon color, RGB value are 255, 250, 205.
		static const Color LemonChiffon;
		/// @brief The Lemon Curry color, RGB value are 204, 160, 29.
		static const Color LemonCurry;
		/// @brief The Lemon Glacier color, RGB value are 253, 255, 0.
		static const Color LemonGlacier;
		/// @brief The Lemon Meringue color, RGB value are 246, 234, 190.
		static const Color LemonMeringue;
		/// @brief The Lemon Yellow color, RGB value are 255, 244, 79.
		static const Color LemonYellow;
		/// @brief The Lemon Yellow Crayola color, RGB value are 255, 255, 159.
		static const Color LemonYellowCrayola;
		/// @brief The Liberty color, RGB value are 84, 90, 167.
		static const Color Liberty;
		/// @brief The Light Blue color, RGB value are 173, 216, 230.
		static const Color LightBlue;
		/// @brief The Light Coral color, RGB value are 240, 128, 128.
		static const Color LightCoral;
		/// @brief The Light Cornflower Blue color, RGB value are 147, 204, 234.
		static const Color LightCornflowerBlue;
		/// @brief The Light Cyan color, RGB value are 224, 255, 255.
		static const Color LightCyan;
		/// @brief The Light French Beige color, RGB value are 200, 173, 127.
		static const Color LightFrenchBeige;
		/// @brief The Light Goldenrod Yellow color, RGB value are 250, 250, 210.
		static const Color LightGoldenrodYellow;
		/// @brief The Light Gray color, RGB value are 211, 211, 211.
		static const Color LightGray;
		/// @brief The Light Green color, RGB value are 144, 238, 144.
		static const Color LightGreen;
		/// @brief The Light Orange color, RGB value are 254, 216, 177.
		static const Color LightOrange;
		/// @brief The Light Periwinkle color, RGB value are 197, 203, 225.
		static const Color LightPeriwinkle;
		/// @brief The Light Pink color, RGB value are 255, 182, 193.
		static const Color LightPink;
		/// @brief The Light Salmon color, RGB value are 255, 160, 122.
		static const Color LightSalmon;
		/// @brief The Light Sea Green color, RGB value are 32, 178, 170.
		static const Color LightSeaGreen;
		/// @brief The Light Sky Blue color, RGB value are 135, 206, 250.
		static const Color LightSkyBlue;
		/// @brief The Light Slate Gray color, RGB value are 119, 136, 153.
		static const Color LightSlateGray;
		/// @brief The Light Steel Blue color, RGB value are 176, 196, 222.
		static const Color LightSteelBlue;
		/// @brief The Light Yellow color, RGB value are 255, 255, 224.
		static const Color LightYellow;
		/// @brief The Lilac color, RGB value are 200, 162, 200.
		static const Color Lilac;
		/// @brief The Lilac Luster color, RGB value are 174, 152, 170.
		static const Color LilacLuster;
		/// @brief The Lime Color Wheel color, RGB value are 191, 255, 0.
		static const Color LimeColorWheel;
		/// @brief The Lime Web X11 Green color, RGB value are 0, 255, 0.
		static const Color LimeWebX11Green;
		/// @brief The Lime Green color, RGB value are 50, 205, 50.
		static const Color LimeGreen;
		/// @brief The Lincoln Green color, RGB value are 25, 89, 5.
		static const Color LincolnGreen;
		/// @brief The Linen color, RGB value are 250, 240, 230.
		static const Color Linen;
		/// @brief The Lion color, RGB value are 222, 204, 156.
		static const Color Lion;
		/// @brief The Liseran Purple color, RGB value are 222, 111, 161.
		static const Color LiseranPurple;
		/// @brief The Little Boy Blue color, RGB value are 108, 160, 220.
		static const Color LittleBoyBlue;
		/// @brief The Liver color, RGB value are 103, 76, 71.
		static const Color Liver;
		/// @brief The Liver Dogs color, RGB value are 184, 109, 41.
		static const Color LiverDogs;
		/// @brief The Liver Organ color, RGB value are 108, 46, 31.
		static const Color LiverOrgan;
		/// @brief The Liver Chestnut color, RGB value are 152, 116, 86.
		static const Color LiverChestnut;
		/// @brief The Livid color, RGB value are 102, 153, 204.
		static const Color Livid;
		/// @brief The Macaroni And Cheese color, RGB value are 255, 189, 136.
		static const Color MacaroniAndCheese;
		/// @brief The Madder Lake color, RGB value are 204, 51, 54.
		static const Color MadderLake;
		/// @brief The Magenta color, RGB value are 255, 0, 255.
		static const Color Magenta;
		/// @brief The Magenta Crayola color, RGB value are 246, 83, 166.
		static const Color MagentaCrayola;
		/// @brief The Magenta Dye color, RGB value are 202, 31, 123.
		static const Color MagentaDye;
		/// @brief The Magenta Pantone color, RGB value are 208, 65, 126.
		static const Color MagentaPantone;
		/// @brief The Magenta Process color, RGB value are 255, 0, 144.
		static const Color MagentaProcess;
		/// @brief The Magenta Haze color, RGB value are 159, 69, 118.
		static const Color MagentaHaze;
		/// @brief The Magic Mint color, RGB value are 170, 240, 209.
		static const Color MagicMint;
		/// @brief The Magnolia color, RGB value are 242, 232, 215.
		static const Color Magnolia;
		/// @brief The Mahogany color, RGB value are 192, 64, 0.
		static const Color Mahogany;
		/// @brief The Maize color, RGB value are 251, 236, 93.
		static const Color Maize;
		/// @brief The Maize Crayola color, RGB value are 242, 198, 73.
		static const Color MaizeCrayola;
		/// @brief The Majorelle Blue color, RGB value are 96, 80, 220.
		static const Color MajorelleBlue;
		/// @brief The Malachite color, RGB value are 11, 218, 81.
		static const Color Malachite;
		/// @brief The Manatee color, RGB value are 151, 154, 170.
		static const Color Manatee;
		/// @brief The Mandarin color, RGB value are 243, 122, 72.
		static const Color Mandarin;
		/// @brief The Mango color, RGB value are 253, 190, 2.
		static const Color Mango;
		/// @brief The Mango Tango color, RGB value are 255, 130, 67.
		static const Color MangoTango;
		/// @brief The Mantis color, RGB value are 116, 195, 101.
		static const Color Mantis;
		/// @brief The Mardi Gras color, RGB value are 136, 0, 133.
		static const Color MardiGras;
		/// @brief The Marigold color, RGB value are 234, 162, 33.
		static const Color Marigold;
		/// @brief The Maroon Crayola color, RGB value are 195, 33, 72.
		static const Color MaroonCrayola;
		/// @brief The Maroon Web color, RGB value are 128, 0, 0.
		static const Color MaroonWeb;
		/// @brief The Maroon X11 color, RGB value are 176, 48, 96.
		static const Color MaroonX11;
		/// @brief The Mauve color, RGB value are 224, 176, 255.
		static const Color Mauve;
		/// @brief The Mauve Taupe color, RGB value are 145, 95, 109.
		static const Color MauveTaupe;
		/// @brief The Mauvelous color, RGB value are 239, 152, 170.
		static const Color Mauvelous;
		/// @brief The Maximum Blue color, RGB value are 71, 171, 204.
		static const Color MaximumBlue;
		/// @brief The Maximum Blue Green color, RGB value are 48, 191, 191.
		static const Color MaximumBlueGreen;
		/// @brief The Maximum Blue Purple color, RGB value are 172, 172, 230.
		static const Color MaximumBluePurple;
		/// @brief The Maximum Green color, RGB value are 94, 140, 49.
		static const Color MaximumGreen;
		/// @brief The Maximum Green Yellow color, RGB value are 217, 230, 80.
		static const Color MaximumGreenYellow;
		/// @brief The Maximum Purple color, RGB value are 115, 51, 128.
		static const Color MaximumPurple;
		/// @brief The Maximum Red color, RGB value are 217, 33, 33.
		static const Color MaximumRed;
		/// @brief The Maximum Red Purple color, RGB value are 166, 58, 121.
		static const Color MaximumRedPurple;
		/// @brief The Maximum Yellow color, RGB value are 250, 250, 55.
		static const Color MaximumYellow;
		/// @brief The Maximum Yellow Red color, RGB value are 242, 186, 73.
		static const Color MaximumYellowRed;
		/// @brief The May Green color, RGB value are 76, 145, 65.
		static const Color MayGreen;
		/// @brief The Maya Blue color, RGB value are 115, 194, 251.
		static const Color MayaBlue;
		/// @brief The Medium Aquamarine color, RGB value are 102, 221, 170.
		static const Color MediumAquamarine;
		/// @brief The Medium Blue color, RGB value are 0, 0, 205.
		static const Color MediumBlue;
		/// @brief The Medium Candy Apple Red color, RGB value are 226, 6, 44.
		static const Color MediumCandyAppleRed;
		/// @brief The Medium Carmine color, RGB value are 175, 64, 53.
		static const Color MediumCarmine;
		/// @brief The Medium Champagne color, RGB value are 243, 229, 171.
		static const Color MediumChampagne;
		/// @brief The Medium Orchid color, RGB value are 186, 85, 211.
		static const Color MediumOrchid;
		/// @brief The Medium Purple color, RGB value are 147, 112, 219.
		static const Color MediumPurple;
		/// @brief The Medium Sea Green color, RGB value are 60, 179, 113.
		static const Color MediumSeaGreen;
		/// @brief The Medium Slate Blue color, RGB value are 123, 104, 238.
		static const Color MediumSlateBlue;
		/// @brief The Medium Spring Green color, RGB value are 0, 250, 154.
		static const Color MediumSpringGreen;
		/// @brief The Medium Turquoise color, RGB value are 72, 209, 204.
		static const Color MediumTurquoise;
		/// @brief The Medium Violet Red color, RGB value are 199, 21, 133.
		static const Color MediumVioletRed;
		/// @brief The Mellow Apricot color, RGB value are 248, 184, 120.
		static const Color MellowApricot;
		/// @brief The Mellow Yellow color, RGB value are 248, 222, 126.
		static const Color MellowYellow;
		/// @brief The Melon color, RGB value are 254, 186, 173.
		static const Color Melon;
		/// @brief The Metallic Gold color, RGB value are 211, 175, 55.
		static const Color MetallicGold;
		/// @brief The Metallic Seaweed color, RGB value are 10, 126, 140.
		static const Color MetallicSeaweed;
		/// @brief The Metallic Sunburst color, RGB value are 156, 124, 56.
		static const Color MetallicSunburst;
		/// @brief The Mexican Pink color, RGB value are 228, 0, 124.
		static const Color MexicanPink;
		/// @brief The Middle Blue color, RGB value are 126, 212, 230.
		static const Color MiddleBlue;
		/// @brief The Middle Blue Green color, RGB value are 141, 217, 204.
		static const Color MiddleBlueGreen;
		/// @brief The Middle Blue Purple color, RGB value are 139, 114, 190.
		static const Color MiddleBluePurple;
		/// @brief The Middle Grey color, RGB value are 139, 134, 128.
		static const Color MiddleGrey;
		/// @brief The Middle Green color, RGB value are 77, 140, 87.
		static const Color MiddleGreen;
		/// @brief The Middle Green Yellow color, RGB value are 172, 191, 96.
		static const Color MiddleGreenYellow;
		/// @brief The Middle Purple color, RGB value are 217, 130, 181.
		static const Color MiddlePurple;
		/// @brief The Middle Red color, RGB value are 229, 142, 115.
		static const Color MiddleRed;
		/// @brief The Middle Red Purple color, RGB value are 165, 83, 83.
		static const Color MiddleRedPurple;
		/// @brief The Middle Yellow color, RGB value are 255, 235, 0.
		static const Color MiddleYellow;
		/// @brief The Middle Yellow Red color, RGB value are 236, 177, 118.
		static const Color MiddleYellowRed;
		/// @brief The Midnight color, RGB value are 112, 38, 112.
		static const Color Midnight;
		/// @brief The Midnight Blue color, RGB value are 25, 25, 112.
		static const Color MidnightBlue;
		/// @brief The Midnight Green Eagle Green color, RGB value are 0, 73, 83.
		static const Color MidnightGreenEagleGreen;
		/// @brief The Mikado Yellow color, RGB value are 255, 196, 12.
		static const Color MikadoYellow;
		/// @brief The Mimi Pink color, RGB value are 255, 218, 233.
		static const Color MimiPink;
		/// @brief The Mindaro color, RGB value are 227, 249, 136.
		static const Color Mindaro;
		/// @brief The Ming color, RGB value are 54, 116, 125.
		static const Color Ming;
		/// @brief The Minion Yellow color, RGB value are 245, 224, 80.
		static const Color MinionYellow;
		/// @brief The Mint color, RGB value are 62, 180, 137.
		static const Color Mint;
		/// @brief The Mint Cream color, RGB value are 245, 255, 250.
		static const Color MintCream;
		/// @brief The Mint Green color, RGB value are 152, 255, 152.
		static const Color MintGreen;
		/// @brief The Misty Moss color, RGB value are 187, 180, 119.
		static const Color MistyMoss;
		/// @brief The Misty Rose color, RGB value are 255, 228, 225.
		static const Color MistyRose;
		/// @brief The Mode Beige color, RGB value are 150, 113, 23.
		static const Color ModeBeige;
		/// @brief The Mona Lisa color, RGB value are 255, 148, 142.
		static const Color MonaLisa;
		/// @brief The Morning Blue color, RGB value are 141, 163, 153.
		static const Color MorningBlue;
		/// @brief The Moss Green color, RGB value are 138, 154, 91.
		static const Color MossGreen;
		/// @brief The Mountain Meadow color, RGB value are 48, 186, 143.
		static const Color MountainMeadow;
		/// @brief The Mountbatten Pink color, RGB value are 153, 122, 141.
		static const Color MountbattenPink;
		/// @brief The Msu Green color, RGB value are 24, 69, 59.
		static const Color MsuGreen;
		/// @brief The Mulberry color, RGB value are 197, 75, 140.
		static const Color Mulberry;
		/// @brief The Mulberry Crayola color, RGB value are 200, 80, 155.
		static const Color MulberryCrayola;
		/// @brief The Mustard color, RGB value are 255, 219, 88.
		static const Color Mustard;
		/// @brief The Myrtle Green color, RGB value are 49, 120, 115.
		static const Color MyrtleGreen;
		/// @brief The Mystic color, RGB value are 214, 82, 130.
		static const Color Mystic;
		/// @brief The Mystic Maroon color, RGB value are 173, 67, 121.
		static const Color MysticMaroon;
		/// @brief The Nadeshiko Pink color, RGB value are 246, 173, 198.
		static const Color NadeshikoPink;
		/// @brief The Naples Yellow color, RGB value are 250, 218, 94.
		static const Color NaplesYellow;
		/// @brief The Navajo White color, RGB value are 255, 222, 173.
		static const Color NavajoWhite;
		/// @brief The Navy Blue color, RGB value are 0, 0, 128.
		static const Color NavyBlue;
		/// @brief The Navy Blue Crayola color, RGB value are 25, 116, 210.
		static const Color NavyBlueCrayola;
		/// @brief The Neon Blue color, RGB value are 70, 102, 255.
		static const Color NeonBlue;
		/// @brief The Neon Green color, RGB value are 57, 255, 20.
		static const Color NeonGreen;
		/// @brief The Neon Fuchsia color, RGB value are 254, 65, 100.
		static const Color NeonFuchsia;
		/// @brief The New Car color, RGB value are 33, 79, 198.
		static const Color NewCar;
		/// @brief The New York Pink color, RGB value are 215, 131, 127.
		static const Color NewYorkPink;
		/// @brief The Nickel color, RGB value are 114, 116, 114.
		static const Color Nickel;
		/// @brief The Non Photo Blue color, RGB value are 164, 221, 237.
		static const Color NonPhotoBlue;
		/// @brief The Nyanza color, RGB value are 233, 255, 219.
		static const Color Nyanza;
		/// @brief The Ochre color, RGB value are 204, 119, 34.
		static const Color Ochre;
		/// @brief The Old Burgundy color, RGB value are 67, 48, 46.
		static const Color OldBurgundy;
		/// @brief The Old Gold color, RGB value are 207, 181, 59.
		static const Color OldGold;
		/// @brief The Old Lace color, RGB value are 253, 245, 230.
		static const Color OldLace;
		/// @brief The Old Lavender color, RGB value are 121, 104, 120.
		static const Color OldLavender;
		/// @brief The Old Mauve color, RGB value are 103, 49, 71.
		static const Color OldMauve;
		/// @brief The Old Rose color, RGB value are 192, 128, 129.
		static const Color OldRose;
		/// @brief The Old Silver color, RGB value are 132, 132, 130.
		static const Color OldSilver;
		/// @brief The Olive color, RGB value are 128, 128, 0.
		static const Color Olive;
		/// @brief The Olive Drab3 color, RGB value are 107, 142, 35.
		static const Color OliveDrab3;
		/// @brief The Olive Drab7 color, RGB value are 60, 52, 31.
		static const Color OliveDrab7;
		/// @brief The Olive Green color, RGB value are 181, 179, 92.
		static const Color OliveGreen;
		/// @brief The Olivine color, RGB value are 154, 185, 115.
		static const Color Olivine;
		/// @brief The Onyx color, RGB value are 53, 56, 57.
		static const Color Onyx;
		/// @brief The Opal color, RGB value are 168, 195, 188.
		static const Color Opal;
		/// @brief The Opera Mauve color, RGB value are 183, 132, 167.
		static const Color OperaMauve;
		/// @brief The Orange color, RGB value are 255, 127, 0.
		static const Color Orange;
		/// @brief The Orange Crayola color, RGB value are 255, 117, 56.
		static const Color OrangeCrayola;
		/// @brief The Orange Pantone color, RGB value are 255, 88, 0.
		static const Color OrangePantone;
		/// @brief The Orange Web color, RGB value are 255, 165, 0.
		static const Color OrangeWeb;
		/// @brief The Orange Peel color, RGB value are 255, 159, 0.
		static const Color OrangePeel;
		/// @brief The Orange Red color, RGB value are 255, 104, 31.
		static const Color OrangeRed;
		/// @brief The Orange Red Crayola color, RGB value are 255, 83, 73.
		static const Color OrangeRedCrayola;
		/// @brief The Orange Soda color, RGB value are 250, 91, 61.
		static const Color OrangeSoda;
		/// @brief The Orange Yellow color, RGB value are 245, 189, 31.
		static const Color OrangeYellow;
		/// @brief The Orange Yellow Crayola color, RGB value are 248, 213, 104.
		static const Color OrangeYellowCrayola;
		/// @brief The Orchid color, RGB value are 218, 112, 214.
		static const Color Orchid;
		/// @brief The Orchid Pink color, RGB value are 242, 189, 205.
		static const Color OrchidPink;
		/// @brief The Orchid Crayola color, RGB value are 226, 156, 210.
		static const Color OrchidCrayola;
		/// @brief The Outer Space Crayola color, RGB value are 45, 56, 58.
		static const Color OuterSpaceCrayola;
		/// @brief The Outrageous Orange color, RGB value are 255, 110, 74.
		static const Color OutrageousOrange;
		/// @brief The Oxblood color, RGB value are 74, 0, 0.
		static const Color Oxblood;
		/// @brief The Oxford Blue color, RGB value are 0, 33, 71.
		static const Color OxfordBlue;
		/// @brief The Ou Crimson Red color, RGB value are 132, 22, 23.
		static const Color OuCrimsonRed;
		/// @brief The Pacific Blue color, RGB value are 28, 169, 201.
		static const Color PacificBlue;
		/// @brief The Pakistan Green color, RGB value are 0, 102, 0.
		static const Color PakistanGreen;
		/// @brief The Palatinate Purple color, RGB value are 104, 40, 96.
		static const Color PalatinatePurple;
		/// @brief The Pale Aqua color, RGB value are 190, 211, 229.
		static const Color PaleAqua;
		/// @brief The Pale Cerulean color, RGB value are 155, 196, 226.
		static const Color PaleCerulean;
		/// @brief The Pale Dogwood color, RGB value are 237, 122, 155.
		static const Color PaleDogwood;
		/// @brief The Pale Pink color, RGB value are 250, 218, 221.
		static const Color PalePink;
		/// @brief The Pale Purple Pantone color, RGB value are 250, 230, 250.
		static const Color PalePurplePantone;
		/// @brief The Pale Spring Bud color, RGB value are 236, 235, 189.
		static const Color PaleSpringBud;
		/// @brief The Pansy Purple color, RGB value are 120, 24, 74.
		static const Color PansyPurple;
		/// @brief The Paolo Veronese Green color, RGB value are 0, 155, 125.
		static const Color PaoloVeroneseGreen;
		/// @brief The Papaya Whip color, RGB value are 255, 239, 213.
		static const Color PapayaWhip;
		/// @brief The Paradise Pink color, RGB value are 230, 62, 98.
		static const Color ParadisePink;
		/// @brief The Parchment color, RGB value are 241, 233, 210.
		static const Color Parchment;
		/// @brief The Paris Green color, RGB value are 80, 200, 120.
		static const Color ParisGreen;
		/// @brief The Pastel Pink color, RGB value are 222, 165, 164.
		static const Color PastelPink;
		/// @brief The Patriarch color, RGB value are 128, 0, 128.
		static const Color Patriarch;
		/// @brief The Paua color, RGB value are 31, 0, 94.
		static const Color Paua;
		/// @brief The Payne S Grey color, RGB value are 83, 104, 120.
		static const Color PayneSGrey;
		/// @brief The Peach color, RGB value are 255, 229, 180.
		static const Color Peach;
		/// @brief The Peach Crayola color, RGB value are 255, 203, 164.
		static const Color PeachCrayola;
		/// @brief The Peach Puff color, RGB value are 255, 218, 185.
		static const Color PeachPuff;
		/// @brief The Pear color, RGB value are 209, 226, 49.
		static const Color Pear;
		/// @brief The Pearly Purple color, RGB value are 183, 104, 162.
		static const Color PearlyPurple;
		/// @brief The Periwinkle color, RGB value are 204, 204, 255.
		static const Color Periwinkle;
		/// @brief The Periwinkle Crayola color, RGB value are 195, 205, 230.
		static const Color PeriwinkleCrayola;
		/// @brief The Permanent Geranium Lake color, RGB value are 225, 44, 44.
		static const Color PermanentGeraniumLake;
		/// @brief The Persian Blue color, RGB value are 28, 57, 187.
		static const Color PersianBlue;
		/// @brief The Persian Green color, RGB value are 0, 166, 147.
		static const Color PersianGreen;
		/// @brief The Persian Indigo color, RGB value are 50, 18, 122.
		static const Color PersianIndigo;
		/// @brief The Persian Orange color, RGB value are 217, 144, 88.
		static const Color PersianOrange;
		/// @brief The Persian Pink color, RGB value are 247, 127, 190.
		static const Color PersianPink;
		/// @brief The Persian Plum color, RGB value are 112, 28, 28.
		static const Color PersianPlum;
		/// @brief The Persian Red color, RGB value are 204, 51, 51.
		static const Color PersianRed;
		/// @brief The Persian Rose color, RGB value are 254, 40, 162.
		static const Color PersianRose;
		/// @brief The Persimmon color, RGB value are 236, 88, 0.
		static const Color Persimmon;
		/// @brief The Pewter Blue color, RGB value are 139, 168, 183.
		static const Color PewterBlue;
		/// @brief The Phlox color, RGB value are 223, 0, 255.
		static const Color Phlox;
		/// @brief The Phthalo Blue color, RGB value are 0, 15, 137.
		static const Color PhthaloBlue;
		/// @brief The Phthalo Green color, RGB value are 18, 53, 36.
		static const Color PhthaloGreen;
		/// @brief The Picotee Blue color, RGB value are 46, 39, 135.
		static const Color PicoteeBlue;
		/// @brief The Pictorial Carmine color, RGB value are 195, 11, 78.
		static const Color PictorialCarmine;
		/// @brief The Piggy Pink color, RGB value are 253, 221, 230.
		static const Color PiggyPink;
		/// @brief The Pine Green color, RGB value are 1, 121, 111.
		static const Color PineGreen;
		/// @brief The Pine Tree color, RGB value are 42, 47, 35.
		static const Color PineTree;
		/// @brief The Pink color, RGB value are 255, 192, 203.
		static const Color Pink;
		/// @brief The Pink Pantone color, RGB value are 215, 72, 148.
		static const Color PinkPantone;
		/// @brief The Pink Lace color, RGB value are 255, 221, 244.
		static const Color PinkLace;
		/// @brief The Pink Lavender color, RGB value are 216, 178, 209.
		static const Color PinkLavender;
		/// @brief The Pink Sherbet color, RGB value are 247, 143, 167.
		static const Color PinkSherbet;
		/// @brief The Pistachio color, RGB value are 147, 197, 114.
		static const Color Pistachio;
		/// @brief The Platinum color, RGB value are 229, 228, 226.
		static const Color Platinum;
		/// @brief The Plum color, RGB value are 142, 69, 133.
		static const Color Plum;
		/// @brief The Plum Web color, RGB value are 221, 160, 221.
		static const Color PlumWeb;
		/// @brief The Plump Purple color, RGB value are 89, 70, 178.
		static const Color PlumpPurple;
		/// @brief The Polished Pine color, RGB value are 93, 164, 147.
		static const Color PolishedPine;
		/// @brief The Pomp And Power color, RGB value are 134, 96, 142.
		static const Color PompAndPower;
		/// @brief The Popstar color, RGB value are 190, 79, 98.
		static const Color Popstar;
		/// @brief The Portland Orange color, RGB value are 255, 90, 54.
		static const Color PortlandOrange;
		/// @brief The Powder Blue color, RGB value are 176, 224, 230.
		static const Color PowderBlue;
		/// @brief The Prairie Gold color, RGB value are 225, 202, 122.
		static const Color PrairieGold;
		/// @brief The Princeton Orange color, RGB value are 245, 128, 37.
		static const Color PrincetonOrange;
		/// @brief The Process Yellow color, RGB value are 255, 239, 0.
		static const Color ProcessYellow;
		/// @brief The Prune color, RGB value are 112, 28, 28.
		static const Color Prune;
		/// @brief The Prussian Blue color, RGB value are 0, 49, 83.
		static const Color PrussianBlue;
		/// @brief The Psychedelic Purple color, RGB value are 223, 0, 255.
		static const Color PsychedelicPurple;
		/// @brief The Puce color, RGB value are 204, 136, 153.
		static const Color Puce;
		/// @brief The Pullman Brown Ups Brown color, RGB value are 100, 65, 23.
		static const Color PullmanBrownUpsBrown;
		/// @brief The Pumpkin color, RGB value are 255, 117, 24.
		static const Color Pumpkin;
		/// @brief The Purple color, RGB value are 106, 13, 173.
		static const Color Purple;
		/// @brief The Purple Web color, RGB value are 128, 0, 128.
		static const Color PurpleWeb;
		/// @brief The Purple Munsell color, RGB value are 159, 0, 197.
		static const Color PurpleMunsell;
		/// @brief The Purple X11 color, RGB value are 160, 32, 240.
		static const Color PurpleX11;
		/// @brief The Purple Mountain Majesty color, RGB value are 150, 120, 182.
		static const Color PurpleMountainMajesty;
		/// @brief The Purple Navy color, RGB value are 78, 81, 128.
		static const Color PurpleNavy;
		/// @brief The Purple Pizzazz color, RGB value are 254, 78, 218.
		static const Color PurplePizzazz;
		/// @brief The Purple Plum color, RGB value are 156, 81, 182.
		static const Color PurplePlum;
		/// @brief The Purpureus color, RGB value are 154, 78, 174.
		static const Color Purpureus;
		/// @brief The Queen Blue color, RGB value are 67, 107, 149.
		static const Color QueenBlue;
		/// @brief The Queen Pink color, RGB value are 232, 204, 215.
		static const Color QueenPink;
		/// @brief The Quick Silver color, RGB value are 166, 166, 166.
		static const Color QuickSilver;
		/// @brief The Quinacridone Magenta color, RGB value are 142, 58, 89.
		static const Color QuinacridoneMagenta;
		/// @brief The Radical Red color, RGB value are 255, 53, 94.
		static const Color RadicalRed;
		/// @brief The Raisin Black color, RGB value are 36, 33, 36.
		static const Color RaisinBlack;
		/// @brief The Rajah color, RGB value are 251, 171, 96.
		static const Color Rajah;
		/// @brief The Raspberry color, RGB value are 227, 11, 93.
		static const Color Raspberry;
		/// @brief The Raspberry Glace color, RGB value are 145, 95, 109.
		static const Color RaspberryGlace;
		/// @brief The Raspberry Rose color, RGB value are 179, 68, 108.
		static const Color RaspberryRose;
		/// @brief The Raw Sienna color, RGB value are 214, 138, 89.
		static const Color RawSienna;
		/// @brief The Raw Umber color, RGB value are 130, 102, 68.
		static const Color RawUmber;
		/// @brief The Razzle Dazzle Rose color, RGB value are 255, 51, 204.
		static const Color RazzleDazzleRose;
		/// @brief The Razzmatazz color, RGB value are 227, 37, 107.
		static const Color Razzmatazz;
		/// @brief The Razzmic Berry color, RGB value are 141, 78, 133.
		static const Color RazzmicBerry;
		/// @brief The Rebecca Purple color, RGB value are 102, 51, 153.
		static const Color RebeccaPurple;
		/// @brief The Red color, RGB value are 255, 0, 0.
		static const Color Red;
		/// @brief The Red Crayola color, RGB value are 238, 32, 77.
		static const Color RedCrayola;
		/// @brief The Red Munsell color, RGB value are 242, 0, 60.
		static const Color RedMunsell;
		/// @brief The Red Ncs color, RGB value are 196, 2, 51.
		static const Color RedNcs;
		/// @brief The Red Pantone color, RGB value are 237, 41, 57.
		static const Color RedPantone;
		/// @brief The Red Pigment color, RGB value are 237, 28, 36.
		static const Color RedPigment;
		/// @brief The Red Ryb color, RGB value are 254, 39, 18.
		static const Color RedRyb;
		/// @brief The Red Orange color, RGB value are 255, 83, 73.
		static const Color RedOrange;
		/// @brief The Red Orange Crayola color, RGB value are 255, 104, 31.
		static const Color RedOrangeCrayola;
		/// @brief The Red Orange Color Wheel color, RGB value are 255, 69, 0.
		static const Color RedOrangeColorWheel;
		/// @brief The Red Purple color, RGB value are 228, 0, 120.
		static const Color RedPurple;
		/// @brief The Red Salsa color, RGB value are 253, 58, 74.
		static const Color RedSalsa;
		/// @brief The Red Violet color, RGB value are 199, 21, 133.
		static const Color RedViolet;
		/// @brief The Red Violet Crayola color, RGB value are 192, 68, 143.
		static const Color RedVioletCrayola;
		/// @brief The Red Violet Color Wheel color, RGB value are 146, 43, 62.
		static const Color RedVioletColorWheel;
		/// @brief The Redwood color, RGB value are 164, 90, 82.
		static const Color Redwood;
		/// @brief The Resolution Blue color, RGB value are 0, 35, 135.
		static const Color ResolutionBlue;
		/// @brief The Rhythm color, RGB value are 119, 118, 150.
		static const Color Rhythm;
		/// @brief The Rich Black color, RGB value are 0, 64, 64.
		static const Color RichBlack;
		/// @brief The Rich Black Fogra29 color, RGB value are 1, 11, 19.
		static const Color RichBlackFogra29;
		/// @brief The Rich Black Fogra39 color, RGB value are 1, 2, 3.
		static const Color RichBlackFogra39;
		/// @brief The Rifle Green color, RGB value are 68, 76, 56.
		static const Color RifleGreen;
		/// @brief The Robin Egg Blue color, RGB value are 0, 204, 204.
		static const Color RobinEggBlue;
		/// @brief The Rocket Metallic color, RGB value are 138, 127, 128.
		static const Color RocketMetallic;
		/// @brief The Rojo Spanish Red color, RGB value are 169, 17, 1.
		static const Color RojoSpanishRed;
		/// @brief The Roman Silver color, RGB value are 131, 137, 150.
		static const Color RomanSilver;
		/// @brief The Rose color, RGB value are 255, 0, 127.
		static const Color Rose;
		/// @brief The Rose Bonbon color, RGB value are 249, 66, 158.
		static const Color RoseBonbon;
		/// @brief The Rose Dust color, RGB value are 158, 94, 111.
		static const Color RoseDust;
		/// @brief The Rose Ebony color, RGB value are 103, 72, 70.
		static const Color RoseEbony;
		/// @brief The Rose Madder color, RGB value are 227, 38, 54.
		static const Color RoseMadder;
		/// @brief The Rose Pink color, RGB value are 255, 102, 204.
		static const Color RosePink;
		/// @brief The Rose Pompadour color, RGB value are 237, 122, 155.
		static const Color RosePompadour;
		/// @brief The Rose Red color, RGB value are 194, 30, 86.
		static const Color RoseRed;
		/// @brief The Rose Taupe color, RGB value are 144, 93, 93.
		static const Color RoseTaupe;
		/// @brief The Rose Vale color, RGB value are 171, 78, 82.
		static const Color RoseVale;
		/// @brief The Rosewood color, RGB value are 101, 0, 11.
		static const Color Rosewood;
		/// @brief The Rosso Corsa color, RGB value are 212, 0, 0.
		static const Color RossoCorsa;
		/// @brief The Rosy Brown color, RGB value are 188, 143, 143.
		static const Color RosyBrown;
		/// @brief The Royal Blue Dark color, RGB value are 0, 35, 102.
		static const Color RoyalBlueDark;
		/// @brief The Royal Blue Light color, RGB value are 65, 105, 225.
		static const Color RoyalBlueLight;
		/// @brief The Royal Purple color, RGB value are 120, 81, 169.
		static const Color RoyalPurple;
		/// @brief The Royal Yellow color, RGB value are 250, 218, 94.
		static const Color RoyalYellow;
		/// @brief The Ruber color, RGB value are 206, 70, 118.
		static const Color Ruber;
		/// @brief The Rubine Red color, RGB value are 209, 0, 86.
		static const Color RubineRed;
		/// @brief The Ruby color, RGB value are 224, 17, 95.
		static const Color Ruby;
		/// @brief The Ruby Red color, RGB value are 155, 17, 30.
		static const Color RubyRed;
		/// @brief The Rufous color, RGB value are 168, 28, 7.
		static const Color Rufous;
		/// @brief The Russet color, RGB value are 128, 70, 27.
		static const Color Russet;
		/// @brief The Russian Green color, RGB value are 103, 146, 103.
		static const Color RussianGreen;
		/// @brief The Russian Violet color, RGB value are 50, 23, 77.
		static const Color RussianViolet;
		/// @brief The Rust color, RGB value are 183, 65, 14.
		static const Color Rust;
		/// @brief The Rusty Red color, RGB value are 218, 44, 67.
		static const Color RustyRed;
		/// @brief The Sacramento State Green color, RGB value are 4, 57, 39.
		static const Color SacramentoStateGreen;
		/// @brief The Saddle Brown color, RGB value are 139, 69, 19.
		static const Color SaddleBrown;
		/// @brief The Safety Orange color, RGB value are 255, 120, 0.
		static const Color SafetyOrange;
		/// @brief The Safety Orange Blaze Orange color, RGB value are 255, 103, 0.
		static const Color SafetyOrangeBlazeOrange;
		/// @brief The Safety Yellow color, RGB value are 238, 210, 2.
		static const Color SafetyYellow;
		/// @brief The Saffron color, RGB value are 244, 196, 48.
		static const Color Saffron;
		/// @brief The Sage color, RGB value are 188, 184, 138.
		static const Color Sage;
		/// @brief The St Patrick S Blue color, RGB value are 35, 41, 122.
		static const Color StPatrickSBlue;
		/// @brief The Salmon color, RGB value are 250, 128, 114.
		static const Color Salmon;
		/// @brief The Salmon Pink color, RGB value are 255, 145, 164.
		static const Color SalmonPink;
		/// @brief The Sand color, RGB value are 194, 178, 128.
		static const Color Sand;
		/// @brief The Sand Dune color, RGB value are 150, 113, 23.
		static const Color SandDune;
		/// @brief The Sandy Brown color, RGB value are 244, 164, 96.
		static const Color SandyBrown;
		/// @brief The Sap Green color, RGB value are 80, 125, 42.
		static const Color SapGreen;
		/// @brief The Sapphire color, RGB value are 15, 82, 186.
		static const Color Sapphire;
		/// @brief The Sapphire Blue color, RGB value are 0, 103, 165.
		static const Color SapphireBlue;
		/// @brief The Sapphire Crayola color, RGB value are 45, 93, 161.
		static const Color SapphireCrayola;
		/// @brief The Satin Sheen Gold color, RGB value are 203, 161, 53.
		static const Color SatinSheenGold;
		/// @brief The Scarlet color, RGB value are 255, 36, 0.
		static const Color Scarlet;
		/// @brief The Schauss Pink color, RGB value are 255, 145, 175.
		static const Color SchaussPink;
		/// @brief The School Bus Yellow color, RGB value are 255, 216, 0.
		static const Color SchoolBusYellow;
		/// @brief The Screamin Green color, RGB value are 102, 255, 102.
		static const Color ScreaminGreen;
		/// @brief The Sea Green color, RGB value are 46, 139, 87.
		static const Color SeaGreen;
		/// @brief The Sea Green Crayola color, RGB value are 0, 255, 205.
		static const Color SeaGreenCrayola;
		/// @brief The Seance color, RGB value are 97, 32, 134.
		static const Color Seance;
		/// @brief The Seal Brown color, RGB value are 89, 38, 11.
		static const Color SealBrown;
		/// @brief The Seashell color, RGB value are 255, 245, 238.
		static const Color Seashell;
		/// @brief The Secret color, RGB value are 118, 67, 116.
		static const Color Secret;
		/// @brief The Selective Yellow color, RGB value are 255, 186, 0.
		static const Color SelectiveYellow;
		/// @brief The Sepia color, RGB value are 112, 66, 20.
		static const Color Sepia;
		/// @brief The Shadow color, RGB value are 138, 121, 93.
		static const Color Shadow;
		/// @brief The Shadow Blue color, RGB value are 119, 139, 165.
		static const Color ShadowBlue;
		/// @brief The Shamrock Green color, RGB value are 0, 158, 96.
		static const Color ShamrockGreen;
		/// @brief The Sheen Green color, RGB value are 143, 212, 0.
		static const Color SheenGreen;
		/// @brief The Shimmering Blush color, RGB value are 217, 134, 149.
		static const Color ShimmeringBlush;
		/// @brief The Shiny Shamrock color, RGB value are 95, 167, 120.
		static const Color ShinyShamrock;
		/// @brief The Shocking Pink color, RGB value are 252, 15, 192.
		static const Color ShockingPink;
		/// @brief The Shocking Pink Crayola color, RGB value are 255, 111, 255.
		static const Color ShockingPinkCrayola;
		/// @brief The Sienna color, RGB value are 136, 45, 23.
		static const Color Sienna;
		/// @brief The Silver color, RGB value are 192, 192, 192.
		static const Color Silver;
		/// @brief The Silver Crayola color, RGB value are 201, 192, 187.
		static const Color SilverCrayola;
		/// @brief The Silver Metallic color, RGB value are 170, 169, 173.
		static const Color SilverMetallic;
		/// @brief The Silver Chalice color, RGB value are 172, 172, 172.
		static const Color SilverChalice;
		/// @brief The Silver Pink color, RGB value are 196, 174, 173.
		static const Color SilverPink;
		/// @brief The Silver Sand color, RGB value are 191, 193, 194.
		static const Color SilverSand;
		/// @brief The Sinopia color, RGB value are 203, 65, 11.
		static const Color Sinopia;
		/// @brief The Sizzling Red color, RGB value are 255, 56, 85.
		static const Color SizzlingRed;
		/// @brief The Sizzling Sunrise color, RGB value are 255, 219, 0.
		static const Color SizzlingSunrise;
		/// @brief The Skobeloff color, RGB value are 0, 116, 116.
		static const Color Skobeloff;
		/// @brief The Sky Blue color, RGB value are 135, 206, 235.
		static const Color SkyBlue;
		/// @brief The Sky Blue Crayola color, RGB value are 118, 215, 234.
		static const Color SkyBlueCrayola;
		/// @brief The Sky Magenta color, RGB value are 207, 113, 175.
		static const Color SkyMagenta;
		/// @brief The Slate Blue color, RGB value are 106, 90, 205.
		static const Color SlateBlue;
		/// @brief The Slate Gray color, RGB value are 112, 128, 144.
		static const Color SlateGray;
		/// @brief The Slimy Green color, RGB value are 41, 150, 23.
		static const Color SlimyGreen;
		/// @brief The Smitten color, RGB value are 200, 65, 134.
		static const Color Smitten;
		/// @brief The Smoky Black color, RGB value are 16, 12, 8.
		static const Color SmokyBlack;
		/// @brief The Snow color, RGB value are 255, 250, 250.
		static const Color Snow;
		/// @brief The Solid Pink color, RGB value are 137, 56, 67.
		static const Color SolidPink;
		/// @brief The Sonic Silver color, RGB value are 117, 117, 117.
		static const Color SonicSilver;
		/// @brief The Space Cadet color, RGB value are 29, 41, 81.
		static const Color SpaceCadet;
		/// @brief The Spanish Bistre color, RGB value are 128, 117, 50.
		static const Color SpanishBistre;
		/// @brief The Spanish Blue color, RGB value are 0, 112, 184.
		static const Color SpanishBlue;
		/// @brief The Spanish Carmine color, RGB value are 209, 0, 71.
		static const Color SpanishCarmine;
		/// @brief The Spanish Gray color, RGB value are 152, 152, 152.
		static const Color SpanishGray;
		/// @brief The Spanish Green color, RGB value are 0, 145, 80.
		static const Color SpanishGreen;
		/// @brief The Spanish Orange color, RGB value are 232, 97, 0.
		static const Color SpanishOrange;
		/// @brief The Spanish Pink color, RGB value are 247, 191, 190.
		static const Color SpanishPink;
		/// @brief The Spanish Red color, RGB value are 230, 0, 38.
		static const Color SpanishRed;
		/// @brief The Spanish Sky Blue color, RGB value are 0, 255, 254.
		static const Color SpanishSkyBlue;
		/// @brief The Spanish Violet color, RGB value are 76, 40, 130.
		static const Color SpanishViolet;
		/// @brief The Spanish Viridian color, RGB value are 0, 127, 92.
		static const Color SpanishViridian;
		/// @brief The Spring Bud color, RGB value are 167, 252, 0.
		static const Color SpringBud;
		/// @brief The Spring Frost color, RGB value are 135, 255, 42.
		static const Color SpringFrost;
		/// @brief The Spring Green color, RGB value are 0, 255, 127.
		static const Color SpringGreen;
		/// @brief The Spring Green Crayola color, RGB value are 236, 235, 189.
		static const Color SpringGreenCrayola;
		/// @brief The Star Command Blue color, RGB value are 0, 123, 184.
		static const Color StarCommandBlue;
		/// @brief The Steel Blue color, RGB value are 70, 130, 180.
		static const Color SteelBlue;
		/// @brief The Steel Pink color, RGB value are 204, 51, 204.
		static const Color SteelPink;
		/// @brief The Stil De Grain Yellow color, RGB value are 250, 218, 94.
		static const Color StilDeGrainYellow;
		/// @brief The Straw color, RGB value are 228, 217, 111.
		static const Color Straw;
		/// @brief The Strawberry color, RGB value are 250, 80, 83.
		static const Color Strawberry;
		/// @brief The Strawberry Blonde color, RGB value are 255, 147, 97.
		static const Color StrawberryBlonde;
		/// @brief The Strong Lime Green color, RGB value are 51, 204, 51.
		static const Color StrongLimeGreen;
		/// @brief The Sugar Plum color, RGB value are 145, 78, 117.
		static const Color SugarPlum;
		/// @brief The Sunglow color, RGB value are 255, 204, 51.
		static const Color Sunglow;
		/// @brief The Sunray color, RGB value are 227, 171, 87.
		static const Color Sunray;
		/// @brief The Sunset color, RGB value are 250, 214, 165.
		static const Color Sunset;
		/// @brief The Super Pink color, RGB value are 207, 107, 169.
		static const Color SuperPink;
		/// @brief The Sweet Brown color, RGB value are 168, 55, 49.
		static const Color SweetBrown;
		/// @brief The Syracuse Orange color, RGB value are 212, 69, 0.
		static const Color SyracuseOrange;
		/// @brief The Tan color, RGB value are 210, 180, 140.
		static const Color Tan;
		/// @brief The Tan Crayola color, RGB value are 217, 154, 108.
		static const Color TanCrayola;
		/// @brief The Tangerine color, RGB value are 242, 133, 0.
		static const Color Tangerine;
		/// @brief The Tango Pink color, RGB value are 228, 113, 122.
		static const Color TangoPink;
		/// @brief The Tart Orange color, RGB value are 251, 77, 70.
		static const Color TartOrange;
		/// @brief The Taupe color, RGB value are 72, 60, 50.
		static const Color Taupe;
		/// @brief The Taupe Gray color, RGB value are 139, 133, 137.
		static const Color TaupeGray;
		/// @brief The Tea Green color, RGB value are 208, 240, 192.
		static const Color TeaGreen;
		/// @brief The Tea Rose color, RGB value are 244, 194, 194.
		static const Color TeaRose;
		/// @brief The Teal color, RGB value are 0, 128, 128.
		static const Color Teal;
		/// @brief The Teal Blue color, RGB value are 54, 117, 136.
		static const Color TealBlue;
		/// @brief The Technobotanica color, RGB value are 0, 255, 191.
		static const Color Technobotanica;
		/// @brief The Telemagenta color, RGB value are 207, 52, 118.
		static const Color Telemagenta;
		/// @brief The Tawny color, RGB value are 205, 87, 0.
		static const Color Tawny;
		/// @brief The Terra Cotta color, RGB value are 226, 114, 91.
		static const Color TerraCotta;
		/// @brief The Thistle color, RGB value are 216, 191, 216.
		static const Color Thistle;
		/// @brief The Thulian Pink color, RGB value are 222, 111, 161.
		static const Color ThulianPink;
		/// @brief The Tickle Me Pink color, RGB value are 252, 137, 172.
		static const Color TickleMePink;
		/// @brief The Tiffany Blue color, RGB value are 10, 186, 181.
		static const Color TiffanyBlue;
		/// @brief The Timberwolf color, RGB value are 219, 215, 210.
		static const Color Timberwolf;
		/// @brief The Titanium Yellow color, RGB value are 238, 230, 0.
		static const Color TitaniumYellow;
		/// @brief The Tomato color, RGB value are 255, 99, 71.
		static const Color Tomato;
		/// @brief The Tourmaline color, RGB value are 134, 161, 169.
		static const Color Tourmaline;
		/// @brief The Tropical Rainforest color, RGB value are 0, 117, 94.
		static const Color TropicalRainforest;
		/// @brief The True Blue color, RGB value are 45, 104, 196.
		static const Color TrueBlue;
		/// @brief The Trypan Blue color, RGB value are 28, 5, 179.
		static const Color TrypanBlue;
		/// @brief The Tufts Blue color, RGB value are 62, 142, 222.
		static const Color TuftsBlue;
		/// @brief The Tumbleweed color, RGB value are 222, 170, 136.
		static const Color Tumbleweed;
		/// @brief The Turquoise color, RGB value are 64, 224, 208.
		static const Color Turquoise;
		/// @brief The Turquoise Blue color, RGB value are 0, 255, 239.
		static const Color TurquoiseBlue;
		/// @brief The Turquoise Green color, RGB value are 160, 214, 180.
		static const Color TurquoiseGreen;
		/// @brief The Turtle Green color, RGB value are 138, 154, 91.
		static const Color TurtleGreen;
		/// @brief The Tuscan color, RGB value are 250, 214, 165.
		static const Color Tuscan;
		/// @brief The Tuscan Brown color, RGB value are 111, 78, 55.
		static const Color TuscanBrown;
		/// @brief The Tuscan Red color, RGB value are 124, 72, 72.
		static const Color TuscanRed;
		/// @brief The Tuscan Tan color, RGB value are 166, 123, 91.
		static const Color TuscanTan;
		/// @brief The Tuscany color, RGB value are 192, 153, 153.
		static const Color Tuscany;
		/// @brief The Twilight Lavender color, RGB value are 138, 73, 107.
		static const Color TwilightLavender;
		/// @brief The Tyrian Purple color, RGB value are 102, 2, 60.
		static const Color TyrianPurple;
		/// @brief The Ua Blue color, RGB value are 0, 51, 170.
		static const Color UaBlue;
		/// @brief The Ua Red color, RGB value are 217, 0, 76.
		static const Color UaRed;
		/// @brief The Ultramarine color, RGB value are 63, 0, 255.
		static const Color Ultramarine;
		/// @brief The Ultramarine Blue color, RGB value are 65, 102, 245.
		static const Color UltramarineBlue;
		/// @brief The Ultra Pink color, RGB value are 255, 111, 255.
		static const Color UltraPink;
		/// @brief The Ultra Red color, RGB value are 252, 108, 133.
		static const Color UltraRed;
		/// @brief The Umber color, RGB value are 99, 81, 71.
		static const Color Umber;
		/// @brief The Unbleached Silk color, RGB value are 255, 221, 202.
		static const Color UnbleachedSilk;
		/// @brief The United Nations Blue color, RGB value are 0, 158, 219.
		static const Color UnitedNationsBlue;
		/// @brief The University Of Pennsylvania Red color, RGB value are 165, 0, 33.
		static const Color UniversityOfPennsylvaniaRed;
		/// @brief The Unmellow Yellow color, RGB value are 255, 255, 102.
		static const Color UnmellowYellow;
		/// @brief The Up Forest Green color, RGB value are 1, 68, 33.
		static const Color UpForestGreen;
		/// @brief The Up Maroon color, RGB value are 123, 17, 19.
		static const Color UpMaroon;
		/// @brief The Upsdell Red color, RGB value are 174, 32, 41.
		static const Color UpsdellRed;
		/// @brief The Uranian Blue color, RGB value are 175, 219, 245.
		static const Color UranianBlue;
		/// @brief The Usafa Blue color, RGB value are 0, 79, 152.
		static const Color UsafaBlue;
		/// @brief The Van Dyke Brown color, RGB value are 102, 66, 40.
		static const Color VanDykeBrown;
		/// @brief The Vanilla color, RGB value are 243, 229, 171.
		static const Color Vanilla;
		/// @brief The Vanilla Ice color, RGB value are 243, 143, 169.
		static const Color VanillaIce;
		/// @brief The Vegas Gold color, RGB value are 197, 179, 88.
		static const Color VegasGold;
		/// @brief The Venetian Red color, RGB value are 200, 8, 21.
		static const Color VenetianRed;
		/// @brief The Verdigris color, RGB value are 67, 179, 174.
		static const Color Verdigris;
		/// @brief The Vermilion color, RGB value are 227, 66, 52.
		static const Color Vermilion;
		/// @brief The Veronica color, RGB value are 160, 32, 240.
		static const Color Veronica;
		/// @brief The Violet color, RGB value are 143, 0, 255.
		static const Color Violet;
		/// @brief The Violet Color Wheel color, RGB value are 127, 0, 255.
		static const Color VioletColorWheel;
		/// @brief The Violet Crayola color, RGB value are 150, 61, 127.
		static const Color VioletCrayola;
		/// @brief The Violet Ryb color, RGB value are 134, 1, 175.
		static const Color VioletRyb;
		/// @brief The Violet Web color, RGB value are 238, 130, 238.
		static const Color VioletWeb;
		/// @brief The Violet Blue color, RGB value are 50, 74, 178.
		static const Color VioletBlue;
		/// @brief The Violet Blue Crayola color, RGB value are 118, 110, 200.
		static const Color VioletBlueCrayola;
		/// @brief The Violet Red color, RGB value are 247, 83, 148.
		static const Color VioletRed;
		/// @brief The Violet Red Perbang color, RGB value are 240, 89, 156.
		static const Color VioletRedPerbang;
		/// @brief The Viridian color, RGB value are 64, 130, 109.
		static const Color Viridian;
		/// @brief The Viridian Green color, RGB value are 0, 150, 152.
		static const Color ViridianGreen;
		/// @brief The Vivid Burgundy color, RGB value are 159, 29, 53.
		static const Color VividBurgundy;
		/// @brief The Vivid Sky Blue color, RGB value are 0, 204, 255.
		static const Color VividSkyBlue;
		/// @brief The Vivid Tangerine color, RGB value are 255, 160, 137.
		static const Color VividTangerine;
		/// @brief The Vivid Violet color, RGB value are 159, 0, 255.
		static const Color VividViolet;
		/// @brief The Volt color, RGB value are 206, 255, 0.
		static const Color Volt;
		/// @brief The Warm Black color, RGB value are 0, 66, 66.
		static const Color WarmBlack;
		/// @brief The Weezy Blue color, RGB value are 24, 155, 204.
		static const Color WeezyBlue;
		/// @brief The Wheat color, RGB value are 245, 222, 179.
		static const Color Wheat;
		/// @brief The White color, RGB value are 255, 255, 255.
		static const Color White;
		/// @brief The Wild Blue Yonder color, RGB value are 162, 173, 208.
		static const Color WildBlueYonder;
		/// @brief The Wild Orchid color, RGB value are 212, 112, 162.
		static const Color WildOrchid;
		/// @brief The Wild Strawberry color, RGB value are 255, 67, 164.
		static const Color WildStrawberry;
		/// @brief The Wild Watermelon color, RGB value are 252, 108, 133.
		static const Color WildWatermelon;
		/// @brief The Windsor Tan color, RGB value are 167, 85, 2.
		static const Color WindsorTan;
		/// @brief The Wine color, RGB value are 114, 47, 55.
		static const Color Wine;
		/// @brief The Wine Dregs color, RGB value are 103, 49, 71.
		static const Color WineDregs;
		/// @brief The Winter Sky color, RGB value are 255, 0, 124.
		static const Color WinterSky;
		/// @brief The Wintergreen Dream color, RGB value are 86, 136, 125.
		static const Color WintergreenDream;
		/// @brief The Wisteria color, RGB value are 201, 160, 220.
		static const Color Wisteria;
		/// @brief The Wood Brown color, RGB value are 193, 154, 107.
		static const Color WoodBrown;
		/// @brief The Xanadu color, RGB value are 115, 134, 120.
		static const Color Xanadu;
		/// @brief The Xanthic color, RGB value are 238, 237, 9.
		static const Color Xanthic;
		/// @brief The Xanthous color, RGB value are 241, 180, 47.
		static const Color Xanthous;
		/// @brief The Yale Blue color, RGB value are 0, 53, 107.
		static const Color YaleBlue;
		/// @brief The Yellow color, RGB value are 255, 255, 0.
		static const Color Yellow;
		/// @brief The Yellow Crayola color, RGB value are 252, 232, 131.
		static const Color YellowCrayola;
		/// @brief The Yellow Munsell color, RGB value are 239, 204, 0.
		static const Color YellowMunsell;
		/// @brief The Yellow Ncs color, RGB value are 255, 211, 0.
		static const Color YellowNcs;
		/// @brief The Yellow Pantone color, RGB value are 254, 223, 0.
		static const Color YellowPantone;
		/// @brief The Yellow Process color, RGB value are 255, 239, 0.
		static const Color YellowProcess;
		/// @brief The Yellow Ryb color, RGB value are 254, 254, 51.
		static const Color YellowRyb;
		/// @brief The Yellow Green color, RGB value are 154, 205, 50.
		static const Color YellowGreen;
		/// @brief The Yellow Green Crayola color, RGB value are 197, 227, 132.
		static const Color YellowGreenCrayola;
		/// @brief The Yellow Green Color Wheel color, RGB value are 48, 178, 26.
		static const Color YellowGreenColorWheel;
		/// @brief The Yellow Orange color, RGB value are 255, 174, 66.
		static const Color YellowOrange;
		/// @brief The Yellow Orange Color Wheel color, RGB value are 255, 149, 5.
		static const Color YellowOrangeColorWheel;
		/// @brief The Yellow Sunshine color, RGB value are 255, 247, 0.
		static const Color YellowSunshine;
		/// @brief The Yinmn Blue color, RGB value are 46, 80, 144.
		static const Color YinmnBlue;
		/// @brief The Zaffre color, RGB value are 0, 20, 168.
		static const Color Zaffre;
		/// @brief The Zinnwaldite Brown color, RGB value are 44, 22, 8.
		static const Color ZinnwalditeBrown;
		/// @brief The Zomp color, RGB value are 57, 167, 142.
		static const Color Zomp;
    };
}
#endif // __APE_COLOR_H__