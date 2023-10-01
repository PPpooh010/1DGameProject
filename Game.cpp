#include "Game.h"
#include <math.h>
#include <vector>

Game::Game(sf::RenderWindow& window)
{
    gui.Init();
    if (backgroundTexture.loadFromFile("background_ice_2_test.png")) {
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setPosition(0.f, 0.f);
    }
    //player 1
    playerTexture.loadFromFile("ghost_all_player1.png");
    playerSprite.setPosition(40.f, 510.f); 
    scale1_big = 1;
    //player 2 
    player2Texture.loadFromFile("ghost_all_player2.png");
    player2Sprite.setPosition(1280.f, 510.f); 
    scale2_big = 1;

    playerMv1 = new PlayerMovement(this->playerSprite, this->playerTexture , this-> scale1_big);
    playerMv2 = new Player2Movement(this->player2Sprite, this->player2Texture , this-> scale2_big);

    //skill fire player 1 
    skill_fire_status = false;
    skill_fire_1.loadFromFile("skill1_all_redred.png");
    skill_fire.setTexture(skill_fire_1);
    skill_fire.setTextureRect(sf::IntRect(160, 320, 32, 32));
    skill_fire.setScale(3.1, 3.1);
    skill_fire2.setOrigin(0, 0);
    skill_fire.setPosition(-100, -100);

    canUseSkill = true;

    //skill fire player 2
    skill_fire2_status = false;
    skill_fire_2.loadFromFile("skill1_all_blue.png");
    skill_fire2.setTexture(skill_fire_2);
    skill_fire2.setTextureRect(sf::IntRect(160, 320, 32, 32));
    skill_fire2.setScale(-3.1, 3.1);
    skill_fire2.setOrigin(32, 0);
    skill_fire2.setPosition(-200, -100);

    canUseSkill2 = true;

    mv1_currentBullet = 1;
    mv1_current = 1;

    mv2_currentBullet = -1;
    mv2_current = -1;

    //skill2 
    Skill2_fire_Tex1.loadFromFile("skill_all_redred.png");   //player1
    Skill2_fire_SP1.setTexture(Skill2_fire_Tex1);
    Skill2_fire_SP1.setTextureRect(sf::IntRect(0,352, 32, 32));
    Skill2_fire_SP1.setScale(4, 4);
    Skill2_fire_SP1.setPosition(-200, -300);
    positiony_skill2_player1 = -300;
    open_skill2_P1 = false;
    use_skill_P1 = false;
    Press_K = true;

    Skill2_fire_Tex2.loadFromFile("skill_all_blue.png");  //player2 
    Skill2_fire_SP2.setTexture(Skill2_fire_Tex2);
    Skill2_fire_SP2.setTextureRect(sf::IntRect(0, 352, 32, 32));
    Skill2_fire_SP2.setScale(4, 4);
    Skill2_fire_SP2.setPosition(-200, -300);
    positiony_skill2_player2 = -300;
    open_skill2_P2 = false;
    use_skill_P2 = false;
    Press_num2 = true;


    //ultimate skil 1 
    scale_x1 = 3;
    scale_y1 = 3;
    Ult_1_Tex1.loadFromFile("ultimate_all_redred.png");
    Ult_1_SP1.setTexture(Ult_1_Tex1);
    Ult_1_SP1.setTextureRect(sf::IntRect(192,0,32,32));
    Ult_1_SP1.setScale(scale_x1, scale_y1);
    Ult_1_SP1.setPosition(-500, -600);
    ult1_open1 = false;
    Pressed_I = true;
    current_frame1 = 0 ;
 
    scale_x2 = 3;
    scale_y2 = 3;
    Ult_1_Tex2.loadFromFile("ultimate_all_blue.png");
    Ult_1_SP2.setTexture(Ult_1_Tex2);
    Ult_1_SP2.setTextureRect(sf::IntRect(192, 0, 32, 32));
    Ult_1_SP2.setScale(scale_x2, scale_y2);
    Ult_1_SP2.setPosition(-500, -600);
    ult1_open2 = false;
    Pressed_numpad5 = true;
    current_frame2 = 0;
    
    // time 
    srand(time(NULL));
    currentFrame = 0;
    currentFrame2 = 0;
    frame_py1D = 0;
    frame_py2D = 0;
    currentframe_item = 0;
    currentframe_skill2_P1 = 0;

    // Alive
    isPlayer1Alive = true;
    isPlayer2Alive = true;

    //item drop 
    item_drop = false;
    start_item = false;
    position_y_item = -20; 

    item1_tex.loadFromFile("item_drop.png");
    item1_sp.setTexture(item1_tex);
    item1_sp.setTextureRect(sf::IntRect(288, 0, 32 , 32));
    item1_sp.setScale(2.5, 2.5);

    item2_tex.loadFromFile("item_drop.png");
    item2_sp.setTexture(item2_tex);
    item1_sp.setTextureRect(sf::IntRect(320, 0, 32, 32));
    item2_sp.setScale(2.5, 2.5);

    item3_tex.loadFromFile("item_drop.png");
    item3_sp.setTexture(item3_tex);
    item1_sp.setTextureRect(sf::IntRect(352, 0, 32, 32));
    item3_sp.setScale(2.5, 2.5);

    // back alive
    
    start_back_alive = false;
    item_alive_tex.loadFromFile("item_drop.png");
    item_alive_sp.setTexture(item_alive_tex) ;
    item_alive_sp.setTextureRect(sf::IntRect(0, 32, 32, 32));
    item_alive_sp.setScale(3, 3);
    pos_y = -10;
    one_only_alive = false ; 

    //status
    player1HP = 3000;
    player2HP = 3000;
    player1Damage = 55 ;
    player2Damage = 55 ;
    Stamina_player1 = 5; //start
    Stamina_player2 = 5;
    down = 5;

    //snow
    snow_tex.loadFromFile("skill_blue.png");
    snow_sp.setTexture(snow_tex);
    snow_sp.setTextureRect(sf::IntRect(192, 416, 32, 32));
    snow_sp.setScale(3.5, 3.5);
    snow_sp.setPosition(-200, -100);
    snow_on = false; 
    frame_snow = 0;
    stun1_on = false; 
    stun2_on = false;

    //Batman
    batman_tex.loadFromFile("blackhole.png");
    batman_sp.setTexture(batman_tex);
    batman_sp.setTextureRect(sf::IntRect(512, 256, 32, 32));
    batman_sp.setPosition(sf::Vector2f (- 550 , -60 ));
    batman_on = false;
    scaleup_on = false;
    batman_sp.setOrigin(0, 0);
    scalex = 0.5;
    scaley = 0.5; 
    scaleup = 0.1;
    batman_sp.setScale(scalex, scaley);
    current_batman = 0 ;
   // batman_speed = 3.2;
    gohere_x = 550;
    gohere_y = 60;


    //Ultimate 
    scale1_big = 1;
    scale2_big = 1;

    //Blackhole 
    blackhole_on = false;

    Loop(window);
}


void Game::Update(sf::RenderWindow& window, sf::Event& event)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    //--------------------------Rain snow ------------------------------
    if (snow_time.getElapsedTime().asSeconds() > 4.2 && isPlayer1Alive && isPlayer2Alive ) {
        snow_on = true;
        snow_posx = 50 + rand() % 1200;
        snow_posy = -10;
        snow_time.restart();
    }
    if (snow_on) {
        snow_sp.setPosition(snow_posx, snow_posy);
        snow_posy += 9.5;
        if (snow_sp.getPosition().y == 900) {
            snow_on = false;
        }
    }
    if (snow_animation.getElapsedTime().asSeconds() > 0.1 ) {
        snow_animation.restart();
        frame_snow = (frame_snow + 1) % 4;
        snow_sp.setTextureRect(sf::IntRect(192 + frame_snow * 32, 416, 32, 32));
    }
     //--------------------------Rain snow ------------------------------


    //----------------------Black Hole -------------------------------
       
    if (CD_blackhole.getElapsedTime().asSeconds() > 8 && isPlayer1Alive && isPlayer2Alive) {

        CD_blackhole.restart();
        start_blackhole.restart();
        blackhole_on = true;
    }
    if (blackhole_on) down = 9;
    else if (!blackhole_on) down =  5;
    if (start_blackhole.getElapsedTime().asSeconds() > 3 ) {
        blackhole_on = false;
    }

    if (blackhole_on) {

        ps_x1 = playerSprite.getPosition().x;
        ps_y1 = playerSprite.getPosition().y;
        ps_x_blackhole = batman_sp.getPosition().x;
        ps_y_blackhole = batman_sp.getPosition().y;

        int speed_blackhole1 = 7.f / scale1_big;
        int speed_blackhole2 = 7.f / scale2_big; 
        //Q1
        if (ps_x1 >= ps_x_blackhole && ps_y1 <= ps_y_blackhole) playerSprite.move(-speed_blackhole1, speed_blackhole1);
        //Q2
        if (ps_x1 <= ps_x_blackhole && ps_y1 <= ps_y_blackhole) playerSprite.move(speed_blackhole1, speed_blackhole1);
        //Q3
        if (ps_x1 >= ps_x_blackhole && ps_y1 >= ps_y_blackhole) playerSprite.move(-speed_blackhole1, -speed_blackhole1);
        if (ps_x1 <= ps_x_blackhole && ps_y1 >= ps_y_blackhole) playerSprite.move(speed_blackhole1, -speed_blackhole1);

        ps_x2 = player2Sprite.getPosition().x;
        ps_y2 = player2Sprite.getPosition().y;
        //Q1
        if (ps_x2 >= ps_x_blackhole && ps_y2 <= ps_y_blackhole) player2Sprite.move(-speed_blackhole2, speed_blackhole2);
        //Q2    
        if (ps_x2 <= ps_x_blackhole && ps_y2 <= ps_y_blackhole) player2Sprite.move(speed_blackhole2, speed_blackhole2);
        //Q3    
        if (ps_x2 >= ps_x_blackhole && ps_y2 >= ps_y_blackhole) player2Sprite.move(-speed_blackhole2, -speed_blackhole2);
        //Q4    
        if (ps_x2 <= ps_x_blackhole && ps_y2 >= ps_y_blackhole) player2Sprite.move(speed_blackhole2, -speed_blackhole2);
    }           

    //----------------------Black Hole -------------------------------

    // -----------------------BATMAN---------------------------------------
    if (batman_move.getElapsedTime().asSeconds() > 7.9 && isPlayer1Alive && isPlayer2Alive ) {
        batman_on = true;  
        gohere_x = 150 +  rand() % 1100 ; 
        gohere_y = 150 + rand() % 550;
        scaleup_on = true;

        batman_sp.setPosition(gohere_x, gohere_y);
        batman_move.restart();
        batgo.restart();
    }
    if (batman_on) {
        batman_sp.setScale(scalex, scaley);
        if (scaleup_on && scalex < 5 && scaley < 5) scalex += scaleup, scaley += scaleup;
        else {
            scaleup_on = false;
        }
        if (batgo.getElapsedTime().asSeconds() > 3.1) {
            if(scalex > 0.2 && scaley > 0.2 ) scalex -= scaleup, scaley -= scaleup;
            else {
                batman_sp.setPosition(-300, -200);
                batman_on = false;
            }
        }
    }

    if( animation_batman.getElapsedTime().asSeconds() > 0.02){
        animation_batman.restart();
        current_batman = (current_batman + 1) % 4;
        batman_sp.setTextureRect(sf::IntRect(512 + current_batman * 32, 256, 32, 32));
    }
    //------------------------BATMAN------------------------------------

   //--------------------------Ultimate Skill 1 ----------------------------
    if (animation1_ult.getElapsedTime().asSeconds() > 0.1 && ult1_open1) {
        animation1_ult.restart();
        current_frame1 = ((current_frame1 + 1) % 4);
        Ult_1_SP1.setTextureRect(sf::IntRect(192 + current_frame1 * 32 , 0, 32, 32));
    }
    if (ult1_open1) {
       Ult_1_SP1.setPosition(pos_x1_ult, pos_y1_ult - 125);
       Ult_1_SP1.setScale(scale_x1 - 0.9999999999999999999999999999999999  , scale_y1 - 0.9999999999999999999999999999999999);
       if (current_P1 == 1)  pos_x1_ult += 7.5; 
       if (current_P1 == -1)  pos_x1_ult -= 7.5;
    }
    if (CD_Ult1_1.getElapsedTime().asSeconds() > 4 && ult1_open1) {
        Pressed_I = true;
        ult1_open1 = false;
    }
    if (scale_ult.getElapsedTime().asSeconds() > 0.055 && ult1_open1 && scale_x1 <= 14 ) {
        scale_ult.restart();
        scale_x1 ++ ;
        scale_y1 ++ ;
    }
    //--------------------------Ultimate Skill 1 ----------------------------
    
    //-----------------------------Ultimate Skill 1 ---------------------Player2

    if (animation2_ult.getElapsedTime().asSeconds() > 0.1 && ult1_open2) {
        animation2_ult.restart();
        current_frame2 = ((current_frame2 + 1) % 4);
        Ult_1_SP2.setTextureRect(sf::IntRect(192 + current_frame2 * 32, 0, 32, 32));
    }

    if (ult1_open2) {
        Ult_1_SP2.setPosition(pos_x2_ult, pos_y2_ult - 125);
        Ult_1_SP2.setScale(scale_x2 - 0.9999999999999999999999999999999999, scale_y2 - 0.9999999999999999999999999999999999);

        if (current_P2 == 1)  pos_x2_ult += 7.5;
        if (current_P2 == -1)  pos_x2_ult -= 7.5;
    }
    if (CD_Ult1_2.getElapsedTime().asSeconds() > 4 && ult1_open2) {
        Pressed_numpad5 = true;
        ult1_open2 = false;
    }
    if (scale2_ult.getElapsedTime().asSeconds() > 0.055 && ult1_open2 && scale_x2 <= 14) {
        scale2_ult.restart();
        scale_x2++;
        scale_y2++;
    }
    //-----------------------------Ultimate Skill 1 ---------------------Player2

    //----------------------------Skill2 player1----------------------------------
    if (use_skill_P1) {
        Press_K = false ;
        Skill2_fire_SP1.setPosition(positionx_skill2_player1, positiony_skill2_player1);
        positiony_skill2_player1 += 13.5;

        if (animation_skill2_P1.getElapsedTime().asSeconds() >= 0.1 ) {  //animation
            animation_skill2_P1.restart();
            currentframe_skill2_P1 = ((currentframe_skill2_P1 + 1) % 4);
            Skill2_fire_SP1.setTextureRect(sf::IntRect(0 , 352 + currentframe_skill2_P1 * 32, 32, 32));
        }
    }
    if (Skill2_fire_SP1.getPosition().y > 1200 ) {
        Press_K = true;
        use_skill_P1 = false; 
    }
    //----------------------------Skill2 player1----------------------------------
     
    //----------------------------Skill2 ---------player2--------------------------

    if (use_skill_P2) {
        Press_num2 = false;
        Skill2_fire_SP2.setPosition(positionx_skill2_player2, positiony_skill2_player2);
        positiony_skill2_player2 += 13.5;

        if (animation_skill2_P2.getElapsedTime().asSeconds() >= 0.1) {     //animation
            animation_skill2_P2.restart();
            currentframe_skill2_P2 = ((currentframe_skill2_P2 + 1) % 4);
            Skill2_fire_SP2.setTextureRect(sf::IntRect(0, 352 + currentframe_skill2_P2 * 32, 32, 32));
        }
    }
    if (Skill2_fire_SP2.getPosition().y > 1100) {
        Press_num2 = true;
        use_skill_P2 = false;
    }
    //----------------------------Skill2 ---------player2--------------------------

    // ------------------------Luckey Back alive --------------------------------------
    if ((!isPlayer1Alive || !isPlayer2Alive) && !start_back_alive && !one_only_alive ) {
        pos_x = 7 + rand() % 1410;
        pos_y = -20 ;
        start_back_alive = true;

        // lucky
        luck_alive = rand() % 3; // 0 1 2 
        if (luck_alive == 2 && !isPlayer1Alive) pos_x = playerSprite.getPosition().x ;
        else if (luck_alive == 2 && !isPlayer2Alive) pos_x = player2Sprite.getPosition().x;
    }
    if (start_back_alive) {
        item_alive_sp.setPosition(pos_x,pos_y);
        pos_y = pos_y + 13.5;
    }
    else if (!start_back_alive) {
        item_alive_sp.setPosition(-600, -800);
    }

    // ------------------------Luckey Back alive --------------------------------------

    //-------------------------------Item Drop----------------------------------
    if (CD_item_drop.getElapsedTime().asSeconds() > 5 && isPlayer1Alive && isPlayer2Alive) {
        random_item = rand() % 3 ; // 0 1 2 
        random_buff = rand() % 2 ; // 0 1  
        player1Damage = 65;
        player2Damage = 65;
        position_x_random = 7 + rand() % 1340;
        item_drop = true;
        CD_item_drop.restart();
        start_item = true;
    }
    if (idle_item.getElapsedTime().asSeconds() > 0.1) {
        idle_item.restart();
        currentframe_item = ((currentframe_item + 1) % 7);
        item1_sp.setTextureRect(sf::IntRect(currentframe_item * 32, 288, 32, 32));
        item2_sp.setTextureRect(sf::IntRect(currentframe_item * 32, 320, 32, 32));
        item3_sp.setTextureRect(sf::IntRect(currentframe_item * 32, 352, 32, 32));
    }

    if (item_drop && position_y_item <= 735 ) {
        if (random_item == 0) { //RED
            item1_sp.setPosition(position_x_random, position_y_item);
        }
        if (random_item == 1) { //GREEN
            item2_sp.setPosition(position_x_random, position_y_item);
        }
        if (random_item == 2) {//PURPLE
            item3_sp.setPosition(position_x_random, position_y_item);
        }     
        position_y_item += 5 ; 
   
    }
    if (item_drop && start_item) {
        start_item_end.restart();
        start_item = false;
    }
    if (start_item_end.getElapsedTime().asSeconds() > 4) {
        item_drop = false;
    }
    if (!item_drop) {
        position_y_item = -20; 
        if (random_item == 0) item1_sp.setPosition(-100, -200);
        if (random_item == 1) item2_sp.setPosition(-100, -200);
        if (random_item == 2) item3_sp.setPosition(-100, -200);
    }
    // ------------------------Luckey Back alive --------------------------------------

   // -----------CD skill 1

    if (skillCD.getElapsedTime().asSeconds() > 0.5) canUseSkill = true;
    if (skillCD2.getElapsedTime().asSeconds() > 0.5) canUseSkill2 = true;
    
    if (!skill_fire_status) {
        mv1_currentBullet = mv1_current;
    }
    if (!skill_fire2_status) {
        mv2_currentBullet = mv2_current;
    }

    // -----------CD skill 1


    //--------------------MOVEMENT player 1 ---------------------------
    if (!blackhole_on) jump_player1 = 19;
    else if (blackhole_on) jump_player1 = 11;
    //jump 1
    if (!blackhole_on && playerSprite.getPosition().y < window.getSize().y - playerSprite.getGlobalBounds().height - 20) {
        playerSprite.setPosition(sf::Vector2f(playerSprite.getPosition().x, playerSprite.getPosition().y + 10));
    }
    if (!stun1_on && playerSprite.getPosition().y > 70 &&sf::Keyboard::isKeyPressed(sf::Keyboard::W)&& canfly_P1 && isPlayer1Alive && playerSprite.getPosition().x <= window.getSize().x - 10) {
        playerSprite.setPosition(sf::Vector2f(playerSprite.getPosition().x, playerSprite.getPosition().y - jump_player1));
    }
    //jump 1
    if (!stun1_on &&sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::J) && canUseSkill && !skill_fire_status && isPlayer1Alive) {
        skill_fire.setPosition(playerSprite.getPosition());
        skill_fire_status = true;
        canUseSkill = false;
        skillCD.restart();
    }
    if (!stun1_on && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::J) && canUseSkill && !skill_fire_status && isPlayer1Alive) {
        skill_fire.setPosition(playerSprite.getPosition());
        skill_fire_status = true;
        canUseSkill = false;
        skillCD.restart();
    }
    if (!stun1_on && sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isPlayer1Alive && playerSprite.getPosition().y < window.getSize().y - playerSprite.getGlobalBounds().height - 20) {
        playerSprite.move(sf::Vector2f(0, down ));
    }

    //ult 1
    
    // charge stamina 

    if (!stun1_on && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isPlayer1Alive) {
        canfly_P1 = false;
        if(Stamina_player1 <= 100 ) Stamina_player1 += 0.30;
        if (player1Dead.getElapsedTime().asSeconds() >= 0.1f) {
            player1Dead.restart();
            currentFrame = ((currentFrame + 1) % 4);
            playerSprite.setTextureRect(sf::IntRect(128 + currentFrame * 32, 0, 32, 32));
        }
    }
  
    else if (!stun1_on && sf::Keyboard::isKeyPressed(sf::Keyboard::I) && Stamina_player1 >= 65 && isPlayer1Alive && Pressed_I) {
        Stamina_player1 = Stamina_player1 - 65;
        ult1_open1 = true;
        Pressed_I = false;
        scale_x1 = 3;
        scale_y1 = 3;
        pos_x1_ult = playerSprite.getPosition().x;
        pos_y1_ult = playerSprite.getPosition().y;
        current_P1 = mv1_current;
        CD_Ult1_1.restart();
    }

    else if (!stun1_on && sf::Keyboard::isKeyPressed(sf::Keyboard::K) && Press_K && isPlayer1Alive) { //  Skill2  player 1//
        positionx_skill2_player1 = player2Sprite.getPosition().x;
        positiony_skill2_player1 = -300;
        use_skill_P1 = true;
        canfly_P1 = true;
    }
    
    else if (!stun1_on && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && isPlayer1Alive && playerSprite.getPosition().x <= window.getSize().x - playerSprite.getGlobalBounds().width) {
        playerMv1->moveRight();
        mv1_current = 1;
        if (!skill_fire_status) mv1_currentBullet = 1;
        canfly_P1 = true;
    }

    else if (!stun1_on && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && isPlayer1Alive && playerSprite.getPosition().x >= 0)
         {
        playerMv1->moveLeft();
        mv1_current = -1;
        if (!skill_fire_status) mv1_currentBullet = -1;
    }

    else if (!stun1_on && sf::Keyboard::isKeyPressed(sf::Keyboard::J) && canUseSkill && !skill_fire_status && isPlayer1Alive) {  // skill j 
        skill_fire.setPosition(playerSprite.getPosition());
        skill_fire_status = true;
        canUseSkill = false;
        canfly_P1 = true;
        skillCD.restart();
    }
    else if (isPlayer1Alive) {
        playerMv1->update();
        canfly_P1 = true;
    }
    else {
        // dead1 animation
        if (player1Dead.getElapsedTime().asSeconds() >= 0.25f) {
            player1Dead.restart();
            currentFrame2 = ((currentFrame2 + 1) % 3);
            playerSprite.setTextureRect(sf::IntRect(160 + currentFrame2 * 32, 224, 32, 32));
        }
    }
    if (skill_fire.getPosition().x < 0 || skill_fire.getPosition().x > window.getSize().x)
        skill_fire_status = false;

    // movement player2 
    if (!blackhole_on) jump_player2 = 19;
    else if (blackhole_on) jump_player2 = 11;
    //jump2 
    if ( !blackhole_on && player2Sprite.getPosition().y < window.getSize().y - player2Sprite.getGlobalBounds().height - 20) {
        player2Sprite.setPosition(sf::Vector2f(player2Sprite.getPosition().x, player2Sprite.getPosition().y + 10));
    }
    if (!stun2_on &&  player2Sprite.getPosition().y > 70 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&& canfly_P2 && isPlayer2Alive && player2Sprite.getPosition().x < window.getSize().x + 10) {
        player2Sprite.setPosition(sf::Vector2f(player2Sprite.getPosition().x, player2Sprite.getPosition().y - jump_player2));
    }
    if (!stun2_on && sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && isPlayer2Alive && player2Sprite.getPosition().y < window.getSize().y - player2Sprite.getGlobalBounds().height - 20) {
        player2Sprite.move(sf::Vector2f(0, down));
    }
    
    //jump2
    if (!stun2_on && sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) && canUseSkill2 && !skill_fire2_status && isPlayer2Alive) {
        skill_fire2.setPosition(player2Sprite.getPosition());
        skill_fire2_status = true;
        canUseSkill2 = false;
        skillCD2.restart();
    }
    if (!stun2_on && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) && canUseSkill2 && !skill_fire2_status && isPlayer2Alive) {
        skill_fire2.setPosition(player2Sprite.getPosition());
        skill_fire2_status = true;
        canUseSkill2 = false;
        skillCD2.restart();
    }
    
    //charge stamian player 2
     //ult1 P2 

    if (!stun2_on && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0) && isPlayer2Alive) {
        canfly_P2 = false; 
        if(Stamina_player2 <= 100)Stamina_player2 += 0.30;
        if (player2Dead.getElapsedTime().asSeconds() >= 0.1f) {
            player2Dead.restart();
            currentFrame2 = ((currentFrame2 + 1) % 4);
            player2Sprite.setTextureRect(sf::IntRect(128 + currentFrame2 * 32, 0, 32, 32));
        }

    }
    else if (!stun2_on && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5) && Stamina_player2 >= 65 && isPlayer2Alive && Pressed_numpad5) {
        Stamina_player2 = Stamina_player2 - 65;
        ult1_open2 = true;
        Pressed_numpad5 = false;
        scale_x2 = 3;
        scale_y2 = 3;
        pos_x2_ult = player2Sprite.getPosition().x;
        pos_y2_ult = player2Sprite.getPosition().y;
        current_P2 = mv2_current;
        CD_Ult1_2.restart();
    }
    else if (!stun2_on && sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && isPlayer2Alive && player2Sprite.getPosition().x <= window.getSize().x - player2Sprite.getGlobalBounds().width) {
        playerMv2->moveRight2();
        mv2_current = 1;
        canfly_P2 = true;
        if (!skill_fire2_status) mv2_currentBullet = 1;
    }
    else if (!stun2_on && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2) && Press_num2 && isPlayer2Alive) {  // skil2 player2 //
        positionx_skill2_player2 = playerSprite.getPosition().x;
        positiony_skill2_player2 = -300;
        canfly_P2 = true;
        use_skill_P2 = true;
    }
    else if (!stun2_on && sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && isPlayer2Alive && player2Sprite.getPosition().x >= 0) {
        playerMv2->moveLeft2();
        canfly_P2 = true;
        mv2_current = -1;
        if (!skill_fire2_status) mv2_currentBullet = -1;
    }
   
    else if (!stun2_on && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) && canUseSkill2 && !skill_fire2_status && isPlayer2Alive) {
        skill_fire2.setPosition(player2Sprite.getPosition());
        skill_fire2_status = true;
        canfly_P2 = true;
        canUseSkill2 = false;
        skillCD2.restart();
    }
    else if (isPlayer2Alive) {
        playerMv2->update2();
        canfly_P2 = true;
    }
    else {
        // dead2 animation
        if (player2Dead.getElapsedTime().asSeconds() >= 0.25f) {
            player2Dead.restart();
            currentFrame2 = ((currentFrame2 + 1) % 3);
            player2Sprite.setTextureRect(sf::IntRect(160 + currentFrame2 * 32, 224, 32, 32));
        }
    }
    if (skill_fire2.getPosition().x < 0 || skill_fire2.getPosition().x > window.getSize().x)
        skill_fire2_status = false;

    // hit box ***********************************************************************

    sf::FloatRect player1_hitbox = playerSprite.getGlobalBounds();
    sf::FloatRect player2_hitbox = player2Sprite.getGlobalBounds();
    sf::FloatRect skill_frie_hitbox = skill_fire.getGlobalBounds();
    sf::FloatRect skill_frie2_hitbox = skill_fire2.getGlobalBounds();
    sf::FloatRect item1_sp_hitbox = item1_sp.getGlobalBounds();
    sf::FloatRect item2_sp_hitbox = item2_sp.getGlobalBounds();
    sf::FloatRect item3_sp_hitbox = item3_sp.getGlobalBounds();
    sf::FloatRect item_alive_hitbox = item_alive_sp.getGlobalBounds();
    sf::FloatRect skill2_P1_hitbox = Skill2_fire_SP1.getGlobalBounds();
    sf::FloatRect skill2_P2_hitbox = Skill2_fire_SP2.getGlobalBounds();
    sf::FloatRect Ult1_P1_hitbox = Ult_1_SP1.getGlobalBounds();
    sf::FloatRect Ult1_P2_hitbox = Ult_1_SP2.getGlobalBounds();
    sf::FloatRect Snow_hitbox = snow_sp.getGlobalBounds();



    //collision snow stun 
    if (Snow_hitbox.intersects(player1_hitbox)) {
        player1Dead.restart();
        stun1_on = true;
    }
    if (player1Dead.getElapsedTime().asSeconds() < 0.8 && stun1_on ) {
        playerSprite.setTextureRect(sf::IntRect(32, 192, 32, 32));
        stun1_on =true;
    }

    else {
        stun1_on = false;
    }
    if (Snow_hitbox.intersects(player2_hitbox)) {
        player2Dead.restart();
        stun2_on = true;
    }

    if (player2Dead.getElapsedTime().asSeconds() < 0.8 && stun2_on ) {
        player2Sprite.setTextureRect(sf::IntRect(32, 192, 32, 32));
        stun2_on = true;
    }
    else {
        stun2_on = false;
    }

    //collision ult 1 
    if (Ult1_P1_hitbox.intersects(player2_hitbox)) {
        if(player2HP > 0)player2HP -= 6.5 / scale2_big ; 
    }
    if (Ult1_P2_hitbox.intersects(player1_hitbox)) {
        if (player1HP > 0)player1HP -= 6.5 / scale1_big ;
    }
    if (Ult1_P2_hitbox.intersects(skill_frie_hitbox)) {
        skill_fire_status = 0;
    }
    if (Ult1_P1_hitbox.intersects(skill_frie2_hitbox)) {
        skill_fire2_status = 0;
    }

    //skill 2 fire player 1  |  collision 


    if (skill2_P1_hitbox.intersects(player2_hitbox)) {
        if(player2HP > 0 ) player2HP -= (player1Damage / 12 + 8) / scale2_big ;
        if (Stamina_player1 < 100) Stamina_player1 += 0.5  ;
    }
    if (skill2_P2_hitbox.intersects(player1_hitbox)) {
        if (player1HP > 0) player1HP -= (player2Damage / 12 + 8) /scale1_big ;
        if (Stamina_player2 < 100) Stamina_player2 += 0.5 / scale1_big;
    }

    // skill fire player 1 
    if (skill_fire_status && !skill_frie_hitbox.intersects(player2_hitbox)) {
        if (mv1_currentBullet == 1) {
            skill_fire.setOrigin(0, 0);
            skill_fire.setScale(3.1, 3.1);
            skill_fire.setPosition(skill_fire.getPosition() + sf::Vector2f(25, 0));
        }
        else if (mv1_currentBullet == -1) {
            skill_fire.setOrigin(16, 0);
            skill_fire.setScale(-3.1, 3.1);
            skill_fire.setPosition(skill_fire.getPosition() + sf::Vector2f(-25, 0));
        }

        if (frameClock.getElapsedTime() >= frameTime) {
            frameClock.restart();
            currentFrame = ((currentFrame + 1) % 4);
            skill_fire.setTextureRect(sf::IntRect(160 + currentFrame * 32, 320, 32, 32));
        }
    }

    //skil fire player 2

    if (skill_fire2_status && !skill_frie2_hitbox.intersects(player1_hitbox)) {
        if (mv2_currentBullet == 1) {
            skill_fire2.setOrigin(0, 0);
            skill_fire2.setScale(3.1, 3.1);
            skill_fire2.setPosition(skill_fire2.getPosition() + sf::Vector2f(25, 0));
        }
        if (mv2_currentBullet == -1) {
            skill_fire2.setOrigin(32, 0);
            skill_fire2.setScale(-3.1, 3.1);
            skill_fire2.setPosition(skill_fire2.getPosition() + sf::Vector2f(-25, 0));
        }
        if (frameClock2.getElapsedTime() >= frameTime2) {
            frameClock2.restart();
            currentFrame2 = ((currentFrame2 + 1) % 4);
            skill_fire2.setTextureRect(sf::IntRect(160 + currentFrame2 * 32, 320, 32, 32));
        }
    }
  
    if (skill_frie_hitbox.intersects(player2_hitbox) && skill_fire_status == 1 && isPlayer2Alive) {
        player2HP -= player1Damage / scale2_big;
        if (Stamina_player1 < 100) Stamina_player1 += 1.5;
        skill_fire_status = 0;
    }
    else if (skill_frie_hitbox.intersects(player2_hitbox)) skill_fire_status = 0;

    if (skill_frie2_hitbox.intersects(player1_hitbox) && skill_fire2_status == 1 && isPlayer1Alive) {
        player1HP -= player2Damage / scale1_big ;
        skill_fire2_status = 0;
        if (Stamina_player2 < 100) Stamina_player2 += 1.5; 
    }
    else if (skill_frie2_hitbox.intersects(player1_hitbox)) {
        skill_fire2_status = 0;
    }

    //collision item 
    if (item1_sp_hitbox.intersects(player1_hitbox)) {// red
        item_drop = false;
        if (random_buff == 0) player1Damage += 25;
        if (random_buff == 1)player1Damage -= 45;
    }
    if (item2_sp_hitbox.intersects(player1_hitbox)) {//green
        item_drop = false;
        if (random_buff == 0) if(player1HP < 1350 )player1HP += 200;
        if (random_buff == 1)if (player1HP > 230) player1HP -= 250;
    }
    if (item3_sp_hitbox.intersects(player1_hitbox)) {//purple
        item_drop = false;
        if (random_buff == 0) if (Stamina_player1 < 80 )Stamina_player1 += 20 ;
        if (random_buff == 1) if(Stamina_player1 > 30)Stamina_player1 -= 30 ;
    }

    if (item1_sp_hitbox.intersects(player2_hitbox)) {// red
        item_drop = false;
        if (random_buff == 0) player2Damage += 25 ;
        if (random_buff == 1)player2Damage -= 45 ;
    }
    if (item2_sp_hitbox.intersects(player2_hitbox)) { //green
        item_drop = false; 
        if (random_buff == 0) if (player2HP < 1310)player2HP += 200;
        if (random_buff == 1)if (player2HP > 250) player2HP -= 250;
    }
    if (item3_sp_hitbox.intersects(player2_hitbox)) { //purple
        item_drop = false;
        if (random_buff == 0) if(Stamina_player2 < 80 ) Stamina_player2 += 20;
        if (random_buff == 1)if (Stamina_player2 > 30) Stamina_player2 -= 30;
    }

    //collision back to alive
    if (item_alive_hitbox.intersects(player1_hitbox))   {
        if (!isPlayer1Alive) {
            start_back_alive = false;
            one_only_alive = false;
            isPlayer1Alive = true;
            player1HP += 200;
        }
        else if (isPlayer1Alive) {
            one_only_alive = true;
            start_back_alive = false;
        }
    }
    if (item_alive_hitbox.intersects(player2_hitbox)) {
        if (!isPlayer2Alive) {
            start_back_alive = false;
            one_only_alive = false;
            isPlayer2Alive = true;
            player2HP += 200;
        }
        else if (isPlayer2Alive) {
            one_only_alive = true;
            start_back_alive = false;
        }

    }

    //***************************************************************************
    //player dead 
    if (player1HP <= 0 && isPlayer1Alive) {
        player1HP = 0;
        isPlayer1Alive = false;
    }
    if (player2HP <= 0 && isPlayer2Alive) {
        player2HP = 0;
        isPlayer2Alive = false;
    }

    //Gui update

    gui.Update(player1HP, player2HP, Stamina_player1 , Stamina_player2);
}

void Game::Draw(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);
    if (ult1_open1) window.draw(Ult_1_SP1);
    if (ult1_open2) window.draw(Ult_1_SP2);
    if (start_back_alive)window.draw(item_alive_sp);
    if (item_drop && random_item == 0 )window.draw(item1_sp);
    if (item_drop && random_item == 1)window.draw(item2_sp);
    if (item_drop && random_item == 2)window.draw(item3_sp);
    if (1) window.draw(playerSprite);
    if (1) window.draw(player2Sprite);
    if (skill_fire_status) window.draw(skill_fire);
    if (skill_fire2_status) window.draw(skill_fire2);
    if (use_skill_P1) window.draw(Skill2_fire_SP1);
    if (use_skill_P2) window.draw(Skill2_fire_SP2);
    if (snow_on)window.draw(snow_sp);
    window.draw(batman_sp);
    gui.Draw(window);
}

void Game::Loop(sf::RenderWindow& window)
{
    while (window.isOpen()) {
        sf::Event event;
        window.clear();
        Update(window, event);
        Draw(window);
        window.display();
    }
}


