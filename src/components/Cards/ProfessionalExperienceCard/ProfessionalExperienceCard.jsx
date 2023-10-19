import React from 'react';
import styles from './ProfessionalExperienceCard.module.scss';

const ProfessionalExperienceCard = () => (
  <div className={styles.card}>
    <h4 className={styles.cardTitle}>Professional experience</h4>
    <div className={styles.cardContents}>
      <div className={`${styles.layer} ${styles.window}`}>
        <div className={styles.windowBar}>
          <div className={`${styles.dot} ${styles.red}`} />
          <div className={`${styles.dot} ${styles.amber}`} />
          <div className={`${styles.dot} ${styles.green}`} />
        </div>
        <div className={styles.windowContents}>
          <img className={styles.reactLogo} src="logo-react.svg" alt="React logo" />
          <img src="logo-typescript.svg" alt="Typescript logo" />
        </div>

      </div>
      <div className={`${styles.layer} ${styles.image}`}><img src="logo-graphql.svg" alt="GraphQL logo" /></div>
      <div className={`${styles.layer} ${styles.image}`}><img src="logo-vertx.svg" alt="Vertx logo" /></div>
    </div>
  </div>
);

export default ProfessionalExperienceCard;
