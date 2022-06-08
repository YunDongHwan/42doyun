import { Injectable } from '@nestjs/common';
import { Cats } from './interface/cats.interface';

@Injectable()
export class CatsService {
    private readonly cats: Cats[] = [];

    create(cat: Cats) { //Cats자료형의 cat객체 한개를 만들어
        this.cats.push(cat); //Cats[] 자료형에 push한다.
    }

    findAll(): Cats[] {
        return this.cats;
    }
}
