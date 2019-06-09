void menu()
{

  bup.update();
  bdown.update();
  bool exit = false;
  done_something = false;
  while (bup.is_pressed() || bdown.is_pressed())
  {
    bup.update();
    bdown.update();
  }
  delay(100);

  while (!exit)
  {

    bup.update();
    bdown.update();


    if (global_mode == LOOPER_MODE)
    {
      dis.commit(0, loopers[0].get_state(), loopers[1].get_state(), loopers[2].get_state(), 1, 1, 1, 0);
      if (bup.has_been_released() || bdown.has_been_released()) global_mode = ARP_MONO_MODE;
    }
    else if (global_mode == ARP_MONO_MODE)
    {
      for (unsigned int i = 0; i < 2; i++) b[i].update();

      if (bup.has_been_released() || bdown.has_been_released()) global_mode = LOOPER_MODE;
      bool sub_exit = false;

      for (byte j = 0; j < 2; j++)
      {
        if (b[j].has_been_pressed())
        {
          while (!sub_exit)
          {
            b[j].update();
            bup.update();
            bdown.update();
            if (bup.has_been_pressed()) taker.change_arp(j, 1);
            if (bdown.has_been_pressed()) taker.change_arp(j, -1);
            if (j == 0) dis.commit(1, arp[taker.get_arp_index(0)].get_name(), arp[taker.get_arp_index(1)].get_name(), 'T', 0, 1, 1, 0);
            if (j == 1) dis.commit(1, arp[taker.get_arp_index(0)].get_name(), arp[taker.get_arp_index(1)].get_name(), 'T', 1, 0, 1, 0);
            dis.apply();

            if (b[j].has_been_pressed()) sub_exit = true;
          }

        }
      }
      dis.commit(1, arp[taker.get_arp_index(0)].get_name(), arp[taker.get_arp_index(1)].get_name(), 'T', 1, 1, 1, 0);



    }

    if (bup.is_pressed() && bdown.is_pressed()) exit = true;
    dis.apply();
  }
  while (bup.is_pressed() || bdown.is_pressed())
  {
    bup.update();
    bdown.update();
  }
}

